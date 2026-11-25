# Tic-Tac-Toe Game Using OOP in C++

A two-player, console-based Tic-Tac-Toe game written in C++ to demonstrate core Object-Oriented Programming (OOP) concepts.

## Features

- Two human players with custom names
- Turn-based play using **X** and **O**
- 3 × 3 console board
- Input validation for non-numeric input, out-of-range coordinates, and occupied cells
- Win detection across rows, columns, and diagonals
- Draw detection when the board is full

## OOP Concepts Demonstrated

| Concept | Where it appears |
|---|---|
| Classes and objects | `Player`, `HumanPlayer`, `Board`, and `Game` |
| Abstraction | `Player` is an abstract base class with pure virtual `makeMove()` |
| Inheritance | `HumanPlayer` publicly inherits from `Player` |
| Polymorphism | `Game` calls the overridden virtual `makeMove()` through a `Player*` |
| Encapsulation | Board cells and game state are private; operations are exposed through public methods |

## Project Structure

```text
OOPS/
├── tictactoe.cpp
├── README.md
├── .gitignore
├── docs/
│   ├── project-report.md
│   └── class-diagram.mmd
└── screenshots/
    └── README.md
```

## Requirements

- A C++ compiler with C++11 or later support (GCC / MinGW-w64 recommended)
- A terminal or command prompt

The program uses only standard C++ headers; no third-party libraries are required.

## Build and Run

### Windows (PowerShell with GCC / MinGW-w64)

From the repository root:

```powershell
g++ -std=c++11 -Wall -Wextra -pedantic tictactoe.cpp -o game.exe
.\game.exe
```

### MSYS2 UCRT64

Open the **MSYS2 UCRT64** terminal:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic tictactoe.cpp -o game.exe
./game.exe
```

### Linux / macOS

```bash
g++ -std=c++11 -Wall -Wextra -pedantic tictactoe.cpp -o game
./game
```

## How to Play

1. Enter the names of Player 1 and Player 2 when prompted.
2. Player 1 uses **X**; Player 2 uses **O**.
3. On each turn, enter a row and column, each from **1** to **3**, separated by a space (for example, `2 3`).
4. A player wins by placing three of their symbols in one row, one column, or one diagonal.
5. If all nine cells are occupied and nobody has won, the game ends in a draw.

An invalid move does not consume the player's turn.

## Documentation

- [Project report](docs/project-report.md)
- [UML class diagram source](docs/class-diagram.mmd)
- [Screenshot instructions](screenshots/README.md)

## Current Scope and Limitations

- This version supports two human players on the same computer.
- It is a console application; no graphical interface or computer opponent is included.
- The game ends after a win or draw; replay and score tracking are not currently implemented.

## Author

**Abhinav Dixit**

> Before academic submission, fill in your roll number, course/semester, institution, and submission date in the project report. Add genuine screenshots from a successful run in the `screenshots/` directory.
