#include "mainwindow.h"

#include <QCloseEvent>
#include <QDir>
#include <QFile>
#include <QFont>
#include <QHBoxLayout>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>
#include <QPushButton>
#include <QStandardPaths>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    buildUi();
    loadTasks();
}

MainWindow::~MainWindow() {
    saveTasks();
}

void MainWindow::buildUi() {
    setWindowTitle("To-Do List");
    resize(420, 520);

    auto *central = new QWidget(this);
    auto *layout = new QVBoxLayout(central);

    // Top row: text input + "Add" button
    auto *inputRow = new QHBoxLayout();
    m_input = new QLineEdit(central);
    m_input->setPlaceholderText("What needs doing?");
    m_addButton = new QPushButton("Add", central);
    inputRow->addWidget(m_input);
    inputRow->addWidget(m_addButton);
    layout->addLayout(inputRow);

    // Middle: the checkable task list
    m_taskList = new QListWidget(central);
    layout->addWidget(m_taskList);

    // Bottom: delete button for the selected task
    m_deleteButton = new QPushButton("Delete Selected", central);
    layout->addWidget(m_deleteButton);

    setCentralWidget(central);

    // Wire up interactions
    connect(m_addButton, &QPushButton::clicked, this, &MainWindow::addTask);
    connect(m_input, &QLineEdit::returnPressed, this, &MainWindow::addTask);
    connect(m_deleteButton, &QPushButton::clicked, this, &MainWindow::deleteSelectedTask);
    connect(m_taskList, &QListWidget::itemChanged, this, &MainWindow::onItemChanged);
}

void MainWindow::addTask() {
    const QString text = m_input->text().trimmed();
    if (text.isEmpty()) {
        return;
    }

    auto *item = new QListWidgetItem(text, m_taskList);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked);
    m_taskList->addItem(item);

    m_input->clear();
    saveTasks();
}

void MainWindow::deleteSelectedTask() {
    const auto selected = m_taskList->selectedItems();
    for (QListWidgetItem *item : selected) {
        delete m_taskList->takeItem(m_taskList->row(item));
    }
    saveTasks();
}

void MainWindow::onItemChanged(QListWidgetItem *item) {
    // Give completed tasks a strike-through so progress is visible at a glance.
    QFont font = item->font();
    font.setStrikeOut(item->checkState() == Qt::Checked);
    item->setFont(font);
    saveTasks();
}

QString MainWindow::dataFilePath() const {
    const QString dir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(dir);
    return dir + "/tasks.json";
}

void MainWindow::saveTasks() {
    QJsonArray tasks;
    for (int i = 0; i < m_taskList->count(); ++i) {
        QListWidgetItem *item = m_taskList->item(i);
        QJsonObject obj;
        obj["text"] = item->text();
        obj["done"] = (item->checkState() == Qt::Checked);
        tasks.append(obj);
    }

    QFile file(dataFilePath());
    if (file.open(QIODevice::WriteOnly)) {
        file.write(QJsonDocument(tasks).toJson());
    }
}

void MainWindow::loadTasks() {
    QFile file(dataFilePath());
    if (!file.open(QIODevice::ReadOnly)) {
        return; // First run: no saved tasks yet.
    }

    const QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    if (!doc.isArray()) {
        return;
    }

    for (const QJsonValue &val : doc.array()) {
        const QJsonObject obj = val.toObject();
        auto *item = new QListWidgetItem(obj["text"].toString(), m_taskList);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        const bool done = obj["done"].toBool();
        item->setCheckState(done ? Qt::Checked : Qt::Unchecked);

        QFont font = item->font();
        font.setStrikeOut(done);
        item->setFont(font);

        m_taskList->addItem(item);
    }
}
