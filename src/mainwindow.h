#pragma once

#include <QMainWindow>

class QLineEdit;
class QListWidget;
class QPushButton;
class QListWidgetItem;

// MainWindow owns the whole UI for the to-do app: the input row at the top,
// the checkable task list in the middle, and the delete button at the bottom.
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void addTask();
    void deleteSelectedTask();
    void onItemChanged(QListWidgetItem *item);

private:
    void buildUi();
    void loadTasks();
    void saveTasks();
    QString dataFilePath() const;

    QLineEdit   *m_input;
    QListWidget *m_taskList;
    QPushButton *m_addButton;
    QPushButton *m_deleteButton;
};
