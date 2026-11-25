# Project Report: Tic-Tac-Toe Game Using Object-Oriented Programming in C++

## Cover Page

**Project Title:** Tic-Tac-Toe Game Using OOP in C++  
**Submitted by:** Abhinav Dixit  
**Roll Number:** [Fill in your roll number]  
**Course / Semester:** [Fill in course and semester]  
**Institution:** [Fill in institution name]  
**Subject:** Object-Oriented Programming  
**Submitted to:** [Faculty name, if required]  
**Submission Date:** [Fill in date]

---

## 1. Abstract

This project implements a two-player Tic-Tac-Toe game as a console application in C++. Players take alternate turns to place their symbols, X and O, on a 3 × 3 board. The program validates moves, checks the rows, columns, and diagonals for a winning combination, and detects a draw when all board cells are occupied without a winner.

The implementation is designed to demonstrate object-oriented programming through an abstract base class, inheritance, runtime polymorphism, encapsulation, and the use of classes and objects.

## 2. Introduction

Tic-Tac-Toe is a turn-based game played on a 3 × 3 grid by two players. A player wins by placing three identical symbols in a horizontal row, vertical column, or diagonal. This project models the game's responsibilities using separate C++ classes so that player behavior, board operations, and game flow are organized into distinct components.

## 3. Objectives

- Build a working two-player Tic-Tac-Toe game in C++.
- Apply abstraction using an abstract base class.
- Demonstrate inheritance through a specialized human-player class.
- Demonstrate runtime polymorphism using a virtual function.
- Encapsulate board data and expose operations through public methods.
- Validate moves and identify win and draw conditions.

## 4. Software Requirements

- C++ compiler supporting C++11 or later (for example, GCC / MinGW-w64).
- Terminal or command prompt.
- Visual Studio Code or another text editor/IDE (optional).

No external libraries are required; the program uses standard C++ headers.

## 5. Class Design

### 5.1 Player

- Abstract base class.
- Stores the player's name and symbol as protected data.
- Declares `makeMove()` as a pure virtual function.
- Provides public getters for the name and symbol.
- Has a virtual destructor.

### 5.2 HumanPlayer

- Publicly inherits from `Player`.
- Implements `makeMove()` to display the current player's turn and request row/column input.

### 5.3 Board

- Stores the 3 × 3 character grid as private data.
- Initializes and resets the board.
- Displays the current board.
- Validates and places moves.
- Checks rows, columns, and diagonals for a winner.
- Checks whether all cells are occupied.

### 5.4 Game

- Owns a `Board` object.
- Owns two player objects through `unique_ptr<Player>`.
- Reads player names and initializes X and O players.
- Controls the turn loop, validates user input, switches turns, and ends on a win or draw.

See [class-diagram.mmd](class-diagram.mmd) for the UML class diagram source.

## 6. Object-Oriented Programming Concepts

| OOP concept | Application in this project |
|---|---|
| Class and object | `Game` creates/uses a `Board` and two player objects. |
| Abstraction | `Player` defines a common interface through the pure virtual `makeMove()` function. |
| Inheritance | `HumanPlayer` derives from `Player`. |
| Polymorphism | A `Player*` points to a `HumanPlayer` object; calling virtual `makeMove()` dispatches to the override. |
| Encapsulation | `Board::grid` and `Game` state are private and accessed through class methods. |

## 7. Program Flow / Algorithm

1. Create the game object.
2. Ask both players for their names.
3. Create Player 1 with symbol X and Player 2 with symbol O.
4. Display the board and prompt the current player.
5. Read row and column input.
6. If input is not numeric, clear the input error and ask again.
7. Convert the 1-based user coordinates into 0-based array indices.
8. Check that the coordinates are within the board and that the selected cell is empty.
9. If the move is invalid, show an error and repeat the same player's turn.
10. Place the player's symbol on the board.
11. Check for a winning row, column, or diagonal. If found, display the winner and stop.
12. Otherwise, check whether the board is full. If full, declare a draw and stop.
13. Otherwise, switch players and repeat from step 4.

## 8. Build and Execution

From the repository root, compile with GCC:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic tictactoe.cpp -o game
```

Run on Linux / MSYS2:

```bash
./game
```

Run on Windows PowerShell:

```powershell
g++ -std=c++11 -Wall -Wextra -pedantic tictactoe.cpp -o game.exe
.\game.exe
```

## 9. Test Cases

Run and record the actual observed result for each case before submission.

| Test | Input / situation | Expected result |
|---|---|---|
| Valid move | Empty cell, row/column between 1 and 3 | Symbol is placed |
| Out-of-range move | Row 0 or column 4 | Move rejected; same player's turn continues |
| Occupied cell | Select a cell that already contains X or O | Move rejected; same player's turn continues |
| Non-numeric input | Enter letters instead of row/column numbers | Input error is cleared and the player is prompted again |
| Row win | One player fills a row | That player is declared winner |
| Column win | One player fills a column | That player is declared winner |
| Diagonal win | One player fills either diagonal | That player is declared winner |
| Draw | Fill all nine cells without a winning line | Game Draw is displayed |

**Evidence:** [Insert genuine gameplay, invalid-move, winner, and draw screenshots in the screenshots folder and link them here.]

## 10. Limitations and Future Scope

Current limitations:
- Only two human players are supported.
- The interface is console-based.
- There is no replay option or match score history.
- The program does not include a computer/AI opponent.

Possible future improvements:
- Add a replay option and score tracking.
- Add a computer opponent with difficulty levels.
- Add a graphical user interface.
- Separate class declarations and implementations into header and source files.

## 11. Conclusion

The project demonstrates how a small interactive game can be organized using object-oriented design in C++. It applies abstraction, inheritance, polymorphism, encapsulation, and class-object relationships while implementing turn handling, move validation, winner detection, and draw detection.

---

**Submission note:** Replace every bracketed placeholder with the correct academic details. Run the program and capture genuine screenshots. Do not state that tests passed until they have actually been run.
