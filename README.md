To-Do List (Qt / C++)

A small desktop to-do list app built with **C++17** and **Qt Widgets**. Tasks are checkable, completed tasks get a strike-through, and everything is saved to disk automatically so your list is still there next time you open the app.

<img width="532" height="664" alt="Screenshot 2026-09-05 at 2 30 57 AM" src="https://github.com/user-attachments/assets/c1b809c8-a1f6-4a21-bef5-562abca89341" />

Features
- Add tasks by typing and pressing Enter (or clicking "Add")
- Check off tasks — completed ones get a strike-through
- Delete selected tasks
- Tasks persist automatically between sessions (saved as JSON)

Tech
- C++17
- Qt 5 or Qt 6 (Widgets module)
- CMake for building

Building it yourself

Install Qt — macOS (Homebrew):
```bash
brew install qt cmake
```

Ubuntu/Debian:
```bash
sudo apt install qtbase5-dev cmake build-essential
```

Windows: Download the Qt online installer from qt.io/download-qt-installer and install Qt + the "Desktop" component, plus CMake from cmake.org/download.

Build:
```bash
git clone https://github.com/MTomachi/todo-qt.git
cd todo-qt
mkdir build && cd build
cmake ..
cmake --build .
```

Run:
```bash
./TodoApp        # Linux/macOS
TodoApp.exe      # Windows
```

Optional: Quick launch shortcut

Once built, you can set up a one-word command to launch the app instantly from any Terminal window:

1. Open your shell config file:
```bash
nano ~/.zshrc
```
2. Add this line (adjust the path to wherever you built the app):
```bash
alias todo="~/path/to/todo-qt/build/TodoApp"
```
3. Save (Ctrl+O, then Enter) and exit (Ctrl+X)
4. Reload your shell:
```bash
source ~/.zshrc
```
5. Now just type `todo` in any Terminal window to launch the app.

Project structure

todo-qt/
├── CMakeLists.txt
├── src/
│ ├── main.cpp # entry point
│ ├── mainwindow.h # UI declaration
│ └── mainwindow.cpp # UI + logic
└── README.md


Notes
This was a project to practice combining C++ with UI design principles — keeping the interface minimal and giving immediate visual feedback (strike-through) when a task is completed.
