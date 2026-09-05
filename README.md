# To-Do List (Qt / C++)

A small desktop to-do list app built with **C++17** and **Qt Widgets**. Tasks are checkable, completed tasks get a strike-through, and everything is saved to disk automatically so your list is still there next time you open the app.

![screenshot placeholder](docs/screenshot.png)
*(swap this in once you have a screenshot!)*

## Features
- Add tasks by typing and pressing Enter (or clicking "Add")
- Check off tasks — completed ones get a strike-through
- Delete selected tasks
- Tasks persist automatically between sessions (saved as JSON)

## Tech
- C++17
- Qt 5 or Qt 6 (Widgets module)
- CMake for building

## Building it yourself

### 1. Install Qt

**macOS (Homebrew):**
```bash
brew install qt cmake
```

**Ubuntu/Debian:**
```bash
sudo apt install qtbase5-dev cmake build-essential
```

**Windows:**
Download the [Qt online installer](https://www.qt.io/download-qt-installer) and install Qt + the "Desktop" component, plus [CMake](https://cmake.org/download/).

### 2. Build

```bash
git clone https://github.com/MTomachi/todo-qt.git
cd todo-qt
mkdir build && cd build
cmake ..
cmake --build .
```

### 3. Run

```bash
./TodoApp        # Linux/macOS
TodoApp.exe      # Windows
```

## Project structure
```
todo-qt/
├── CMakeLists.txt
├── src/
│   ├── main.cpp        # entry point
│   ├── mainwindow.h     # UI declaration
│   └── mainwindow.cpp   # UI + logic (add/check/delete/save/load)
└── README.md
```

## Notes
This was a project to practice combining C++ with UI design principles — keeping the interface minimal and giving immediate visual feedback (strike-through) when a task is completed.
