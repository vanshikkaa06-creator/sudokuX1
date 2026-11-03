# sudokuX1
# PROJECT REPORT: SUDOKU SOLVER PRO

## 1. Introduction

Sudoku Solver Pro is a menu-driven application developed using the C programming language. It is designed to solve Sudoku puzzles automatically and also allows users to interact with and play Sudoku. The project demonstrates how programming concepts such as arrays, functions, loops, conditional statements, recursion, and backtracking can be used to solve a real-world logical problem.

The program works with a standard 9×9 Sudoku grid. The objective is to fill every empty cell so that each row, each column, and each 3×3 sub-grid contains the numbers from 1 to 9 without repetition.

## 2. Objectives of the Project

The main objectives of Sudoku Solver Pro are:

- To develop a Sudoku-solving application using C.
- To understand and implement the backtracking algorithm.
- To apply recursion to solve complex logical problems.
- To use two-dimensional arrays for storing and manipulating Sudoku grids.
- To implement input validation and error handling.
- To provide an interactive and user-friendly menu-driven interface.
- To strengthen problem-solving and logical-thinking skills.

## 3. Features of the Project

The project provides several useful features:

1. Load Sample Puzzle: Allows users to load a predefined Sudoku puzzle.
2. Enter Custom Puzzle: Users can enter their own Sudoku puzzle.
3. Display Sudoku Grid: Displays the current puzzle in a structured 9×9 format.
4. Validate Puzzle: Checks whether the entered puzzle follows Sudoku rules.
5. Solve Sudoku: Automatically solves the puzzle using a backtracking algorithm.
6. Get a Hint: Provides the correct value for an empty cell.
7. Show Statistics: Displays the number of filled and empty cells along with the completion percentage.
8. Reset Puzzle: Clears the current Sudoku grid.
9. Interactive Game Mode: Allows users to fill empty cells and check their progress.
10. Exit: Terminates the application.

## 4. Concepts of C Programming Used

This project uses several important concepts of the C programming language.

### 4.1 Header Files

The project uses the `stdio.h` header file to perform input and output operations. Functions such as `printf()` and `scanf()` are used to display information and accept input from the user.

### 4.2 Constants and Macros

The macro `N` is defined with the value 9. It represents the size of the Sudoku grid and helps maintain consistency throughout the program.

### 4.3 Two-Dimensional Arrays

A two-dimensional integer array is used to store the Sudoku puzzle in the form of a 9×9 grid. Each element represents a cell in the puzzle. The value 0 represents an empty cell.

### 4.4 User-Defined Functions

The program is divided into multiple functions, with each function performing a specific task. Examples include `displayGrid()`, `isSafe()`, `solveSudoku()`, `isValidGrid()`, `giveHint()`, and `showStatistics()`.

This modular approach makes the program easier to understand, test, maintain, and debug.

### 4.5 Recursion

Recursion is used in the `solveSudoku()` function. The function calls itself repeatedly to fill empty cells until the puzzle is solved or a possible solution fails.

### 4.6 Backtracking

Backtracking is the main algorithm used in this project. The program tries numbers from 1 to 9 in an empty cell. If a number follows Sudoku rules, it moves to the next empty cell. If a later placement creates a conflict, the program removes the previously placed number and tries another possibility.

### 4.7 Conditional Statements

The project uses `if`, `else`, and `switch` statements to make decisions. These are used for checking Sudoku rules, validating user input, controlling menu options, and determining whether the puzzle has been solved.

### 4.8 Loops

`for`, `while`, and `do-while` loops are used for traversing the Sudoku grid, checking rows and columns, accepting input, and repeatedly displaying the main menu.

### 4.9 Pointers

Pointers are used in the `readInteger()` function. The function accepts an integer pointer so that the entered value can be stored in the variable passed by the calling function.

### 4.10 Input Validation

The program checks whether the entered values are within the allowed range and whether they violate Sudoku rules. It also uses input-reading logic to handle invalid integer input.

### 4.11 Structures of Program Control

The program uses function calls, return statements, loops, and decision-making statements to control the flow of execution and connect different features.

## 5. Working of the Project

When the program starts, the main menu is displayed. The user can select an option according to their requirement.

If the user chooses to load a sample puzzle, the predefined Sudoku grid is loaded into the program. Alternatively, the user can enter a custom puzzle. The entered puzzle is checked for validity before it replaces the current grid.

When the solve option is selected, the program searches for an empty cell and tries numbers from 1 to 9. Before placing a number, it checks whether that number already exists in the same row, column, or 3×3 sub-grid.

If the number is valid, the program proceeds to the next empty cell. If no valid number can be placed, it goes back to the previous cell and tries another number. This process continues until the complete Sudoku puzzle is solved.

The hint feature uses the solving algorithm on a copy of the current grid and fills one empty cell with its correct value. The interactive mode allows users to enter answers and monitor their progress.

## 6. Algorithm Used

The project uses the Backtracking Algorithm, which is a recursive problem-solving technique.

The basic steps are:

1. Find an empty cell in the Sudoku grid.
2. Try placing a number from 1 to 9.
3. Check whether the number is valid in the corresponding row, column, and 3×3 sub-grid.
4. If the number is valid, place it in the cell.
5. Recursively move to the next empty cell.
6. If no valid number works, reset the cell to 0 and return to the previous step.
7. Repeat the process until the puzzle is completely solved.

This algorithm systematically explores possible solutions while eliminating invalid choices.

## 7. Important Functions Used

| Function                 | Purpose                                               |
| ------------------------ | ----------------------------------------------------- |
| `displayGrid()`          | Displays the Sudoku grid.                             |
| `isSafe()`               | Checks whether a number can be placed safely.         |
| `solveSudoku()`          | Solves the puzzle using recursion and backtracking.   |
| `isValidGrid()`          | Checks whether the current grid follows Sudoku rules. |
| `loadSample()`           | Loads a predefined Sudoku puzzle.                     |
| `enterPuzzle()`          | Accepts a custom Sudoku puzzle from the user.         |
| `showStatistics()`       | Displays puzzle statistics.                           |
| `giveHint()`             | Provides a correct value for an empty cell.           |
| `resetPuzzle()`          | Clears the current puzzle.                            |
| `copyGrid()`             | Copies the contents of one Sudoku grid into another.  |
| `startInteractiveGame()` | Starts the interactive Sudoku game mode.              |
| `countEmptyCells()`      | Counts the empty cells in the grid.                   |
| `readInteger()`          | Reads and validates integer input.                    |

## 8. Advantages of the Project

- Provides an automatic solution to Sudoku puzzles.
- Demonstrates the practical application of recursion and backtracking.
- Helps improve logical reasoning and problem-solving skills.
- Supports both predefined and custom Sudoku puzzles.
- Uses modular programming for better code organization.
- Includes input validation to reduce incorrect entries.
- Provides an interactive mode for users who want to solve puzzles themselves.

## 9. Limitations

- The application uses a text-based console interface.
- The sample puzzle is predefined in the program.
- The program does not save puzzles permanently.
- The solver finds a solution but does not check whether the puzzle has multiple possible solutions.
- The interactive game checks entered answers against the computed solution.

## 10. Future Scope

The project can be improved further by introducing a graphical user interface, difficulty levels, a larger collection of sample puzzles, file handling for saving and loading puzzles, and a timer to track solving time. Additional features such as solution uniqueness checking and improved hints can also be implemented.

## 11. Conclusion

Sudoku Solver Pro is a practical application of the C programming language that combines logical problem-solving with important programming concepts. Through this project, concepts such as two-dimensional arrays, functions, recursion, pointers, loops, conditional statements, and input validation are implemented in a meaningful way.

The use of the backtracking algorithm makes it possible to solve Sudoku puzzles efficiently by exploring valid possibilities and reversing incorrect choices. Overall, this project provides valuable practical experience in algorithm development, modular programming, debugging, and logical thinking.
<img width="960" height="600" alt="Screenshot 2026-11-03 122139" src="https://github.com/user-attachments/assets/0d4897de-d5ed-4a20-acb2-e72e8cf0accc" />
<img width="960" height="600" alt="Screenshot 2026-11-03 122159" src="https://github.com/user-attachments/assets/2f09a11a-bb26-4fc5-a78a-f33c4502e9b2" />
<img width="1366" height="768" alt="Screenshot (48)" src="https://github.com/user-attachments/assets/f5a2b345-4ddd-4a63-9872-31a1820adfa2" />
<img width="1366" height="768" alt="Screenshot (49)" src="https://github.com/user-attachments/assets/9f1d4de8-26fb-47bf-a1b8-bd533a31a7b3" />
<img width="1366" height="768" alt="Screenshot (50)" src="https://github.com/user-attachments/assets/6aa4a6fd-0fa1-4e44-bf31-63cf3fd75ea0" />
<img width="1366" height="768" alt="Screenshot (51)" src="https://github.com/user-attachments/assets/edb24538-a25a-4263-a949-2185db41dff8" />
<img width="1366" height="768" alt="Screenshot (52)" src="https://github.com/user-attachments/assets/2554a00c-00f2-443c-a543-b6c2b8ae7bbd" />
<img width="1366" height="768" alt="Screenshot (53)" src="https://github.com/user-attachments/assets/46c8a735-4053-4f88-8775-2556da4814cb" />
