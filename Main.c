#include <stdio.h>

#define N 9

// Function declarations
void displayGrid(int grid[N][N]);
int isSafe(int grid[N][N], int row, int col, int num);
int solveSudoku(int grid[N][N]);
int isValidGrid(int grid[N][N]);
void loadSample(int grid[N][N]);
void enterPuzzle(int grid[N][N]);
void showStatistics(int grid[N][N]);
void giveHint(int grid[N][N]);
void resetPuzzle(int grid[N][N]);
void copyGrid(int source[N][N], int dest[N][N]);

// NEW FUNCTION DECLARATIONS
void startInteractiveGame(int grid[N][N]);
void enterAnswer(int grid[N][N], int original[N][N], int solution[N][N]);
int countEmptyCells(int grid[N][N]);
int readInteger(const char *message, int *value);


// Display Sudoku grid
void displayGrid(int grid[N][N])
{
    int i, j;

    printf("\n");
    printf("       SUDOKU GRID\n");
    printf("   ---------------------\n");

    for (i = 0; i < N; i++)
    {
        printf("   ");

        for (j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
                printf(". ");
            else
                printf("%d ", grid[i][j]);

            if ((j + 1) % 3 == 0 && j != 8)
                printf("| ");
        }

        printf("\n");

        if ((i + 1) % 3 == 0 && i != 8)
            printf("   ------+-------+------\n");
    }

    printf("\n");
}


// Check whether a number can be placed safely
int isSafe(int grid[N][N], int row, int col, int num)
{
    int i, j;

    // Check row
    for (j = 0; j < N; j++)
    {
        if (grid[row][j] == num)
            return 0;
    }

    // Check column
    for (i = 0; i < N; i++)
    {
        if (grid[i][col] == num)
            return 0;
    }

    // Check 3x3 box
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[row - row % 3 + i]
                     [col - col % 3 + j] == num)
                return 0;
        }
    }

    return 1;
}


// Check whether the existing puzzle has conflicts
int isValidGrid(int grid[N][N])
{
    int i, j, num;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            num = grid[i][j];

            if (num < 0 || num > 9)
                return 0;

            if (num != 0)
            {
                grid[i][j] = 0;

                if (!isSafe(grid, i, j, num))
                {
                    grid[i][j] = num;
                    return 0;
                }

                grid[i][j] = num;
            }
        }
    }

    return 1;
}


// Copy one Sudoku grid into another
void copyGrid(int source[N][N], int dest[N][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            dest[i][j] = source[i][j];
        }
    }
}


// Solve Sudoku using backtracking
int solveSudoku(int grid[N][N])
{
    int row, col, num;
    int found = 0;

    // Find an empty cell
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
            {
                found = 1;
                break;
            }
        }

        if (found)
            break;
    }

    // Puzzle is complete
    if (!found)
        return 1;

    // Try numbers from 1 to 9
    for (num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return 1;

            // Undo unsuccessful choice
            grid[row][col] = 0;
        }
    }

    return 0;
}


// Load a sample puzzle
void loadSample(int grid[N][N])
{
    int sample[N][N] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    copyGrid(sample, grid);

    printf("\nSample puzzle loaded successfully!\n");
    displayGrid(grid);
}


// Enter a custom puzzle
void enterPuzzle(int grid[N][N])
{
    int i, j, value;
    int temp[N][N];

    printf("\nEnter the Sudoku row by row.\n");
    printf("Use 0 for empty cells.\n");
    printf("Enter 9 numbers per row, separated by spaces.\n\n");

    for (i = 0; i < N; i++)
    {
        printf("Enter row %d: ", i + 1);

        for (j = 0; j < N; j++)
        {
            if (scanf("%d", &value) != 1)
            {
                printf("Invalid input! Please enter integers only.\n");

                while (getchar() != '\n')
                    ;

                return;
            }

            if (value < 0 || value > 9)
            {
                printf("Invalid number! Use values from 0 to 9.\n");
                return;
            }

            temp[i][j] = value;
        }
    }

    if (!isValidGrid(temp))
    {
        printf("\nInvalid Sudoku! Conflicting numbers found.\n");
        printf("The previous puzzle has been preserved.\n");
        return;
    }

    copyGrid(temp, grid);

    printf("\nPuzzle entered successfully!\n");
    displayGrid(grid);
}


// Display puzzle statistics
void showStatistics(int grid[N][N])
{
    int i, j;
    int filled = 0, empty = 0;
    float percentage;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
                empty++;
            else
                filled++;
        }
    }

    percentage = (filled * 100.0f) / 81;

    printf("\n===== PUZZLE STATISTICS =====\n");
    printf("Total cells       : 81\n");
    printf("Filled cells      : %d\n", filled);
    printf("Empty cells       : %d\n", empty);
    printf("Filled percentage : %.2f%%\n", percentage);

    if (empty == 0)
        printf("Status            : Grid is complete\n");
    else
        printf("Status            : Puzzle is incomplete\n");

    printf("=============================\n");
}


// Give a hint for the first empty cell
void giveHint(int grid[N][N])
{
    int i, j;
    int solution[N][N];

    if (!isValidGrid(grid))
    {
        printf("\nCannot provide a hint: invalid puzzle.\n");
        return;
    }

    copyGrid(grid, solution);

    if (!solveSudoku(solution))
    {
        printf("\nNo solution exists for this puzzle.\n");
        return;
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                grid[i][j] = solution[i][j];

                printf("\nHint: Row %d, Column %d = %d\n",
                       i + 1, j + 1, solution[i][j]);

                displayGrid(grid);
                return;
            }
        }
    }

    printf("\nThe Sudoku is already complete!\n");
}


// Reset the puzzle
void resetPuzzle(int grid[N][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            grid[i][j] = 0;
        }
    }

    printf("\nPuzzle reset successfully!\n");
}


// =================================================
// NEW SECTION: INTERACTIVE SUDOKU GAME
// =================================================


// NEW: Safely read an integer
int readInteger(const char *message, int *value)
{
    int ch;

    printf("%s", message);

    if (scanf("%d", value) != 1)
    {
        printf("\nInvalid input! Please enter an integer.\n");

        while ((ch = getchar()) != '\n' && ch != EOF)
            ;

        return 0;
    }

    return 1;
}


// NEW: Count remaining empty cells
int countEmptyCells(int grid[N][N])
{
    int i, j;
    int empty = 0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
                empty++;
        }
    }

    return empty;
}


// NEW: Enter and validate one answer
void enterAnswer(int grid[N][N],
                 int original[N][N],
                 int solution[N][N])
{
    int row, col, num;

    printf("\n----- ENTER YOUR ANSWER -----\n");

    if (!readInteger("Enter row (1-9): ", &row))
        return;

    if (!readInteger("Enter column (1-9): ", &col))
        return;

    if (!readInteger("Enter your answer (1-9): ", &num))
        return;

    // Check row and column range
    if (row < 1 || row > 9 ||
        col < 1 || col > 9)
    {
        printf("\nInvalid row or column!\n");
        return;
    }

    // Check number range
    if (num < 1 || num > 9)
    {
        printf("\nInvalid number! Enter a number from 1 to 9.\n");
        return;
    }

    // Convert to array indexing
    row--;
    col--;

    // Protect original puzzle numbers
    if (original[row][col] != 0)
    {
        printf("\nThis cell contains a fixed clue!\n");
        printf("You cannot modify this number.\n");
        return;
    }

    // Prevent overwriting an existing answer
    if (grid[row][col] != 0)
    {
        printf("\nThis cell is already filled!\n");
        printf("Choose another empty cell.\n");
        return;
    }

    // Compare answer with actual solution
    if (num == solution[row][col])
    {
        grid[row][col] = num;

        printf("\nCorrect answer! Well done!\n");

        // Display updated grid
        displayGrid(grid);

        printf("Remaining empty cells: %d\n",
               countEmptyCells(grid));
    }
    else
    {
        printf("\nIncorrect answer! Try again.\n");
        printf("Don't give up. Choose another answer!\n");
    }
}


// NEW: Start interactive Sudoku game
void startInteractiveGame(int grid[N][N])
{
    int original[N][N];
    int solution[N][N];

    int choice;
    int i, j;
    int filled = 0;

    // Check whether a puzzle exists
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] != 0)
                filled++;
        }
    }

    if (filled == 0)
    {
        printf("\nPlease load or enter a Sudoku puzzle first!\n");
        return;
    }

    // Validate original puzzle
    if (!isValidGrid(grid))
    {
        printf("\nCannot start game: Invalid Sudoku puzzle.\n");
        return;
    }

    // Preserve original puzzle
    copyGrid(grid, original);

    // Generate solution using existing solver
    copyGrid(grid, solution);

    if (!solveSudoku(solution))
    {
        printf("\nNo solution exists for this puzzle!\n");
        return;
    }

    printf("\n================================\n");
    printf("       INTERACTIVE SUDOKU\n");
    printf("================================\n");

    printf("\nYour Sudoku puzzle:\n");

    displayGrid(grid);

    printf("INSTRUCTIONS:\n");
    printf("1. Select an empty cell.\n");
    printf("2. Enter its row and column.\n");
    printf("3. Enter your answer from 1 to 9.\n");
    printf("4. Correct answers will be accepted.\n");
    printf("5. Incorrect answers can be tried again.\n");
    printf("6. Original clues cannot be changed.\n");

    // Interactive game menu
    do
    {
        printf("\n================================\n");
        printf("       SUDOKU GAME MENU\n");
        printf("================================\n");

        printf("1. Enter an Answer\n");
        printf("2. Display Current Sudoku Grid\n");
        printf("3. Check Remaining Empty Cells\n");
        printf("4. Exit Interactive Game\n");

        printf("================================\n");

        if (!readInteger("Enter your choice: ", &choice))
            continue;

        switch (choice)
        {
            case 1:

                enterAnswer(grid, original, solution);

                // Check whether Sudoku is completed
                if (countEmptyCells(grid) == 0)
                {
                    printf("\n");
                    printf("================================\n");
                    printf("       CONGRATULATIONS!\n");
                    printf("================================\n");

                    printf("You have successfully solved Sudoku!\n");
                    printf("All 81 cells are correctly filled.\n");
                    printf("Thank you for playing!\n");

                    return;
                }

                break;


            case 2:

                printf("\nCURRENT SUDOKU GRID:\n");

                displayGrid(grid);

                break;


            case 3:

                printf("\n===== GAME PROGRESS =====\n");

                printf("Filled cells      : %d\n",
                       81 - countEmptyCells(grid));

                printf("Remaining cells   : %d\n",
                       countEmptyCells(grid));

                printf("Completion        : %.2f%%\n",
                       ((81 - countEmptyCells(grid)) * 100.0f) / 81);

                printf("=========================\n");

                break;


            case 4:

                printf("\nExiting interactive game...\n");
                printf("Your current progress is preserved.\n");

                break;


            default:

                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 4);
}


// =================================================
// END OF NEW INTERACTIVE SECTION
// =================================================


// Main function
int main()
{
    int grid[N][N] = {0};
    int choice;
    int solution[N][N];

    do
    {
        printf("\n================================\n");
        printf("       SUDOKU SOLVER PRO\n");
        printf("================================\n");

        printf("1. Load Sample Puzzle\n");
        printf("2. Enter Your Own Puzzle\n");
        printf("3. Display Sudoku Grid\n");
        printf("4. Validate Sudoku Grid\n");
        printf("5. Solve Sudoku Automatically\n");
        printf("6. Get a Hint\n");
        printf("7. View Puzzle Statistics\n");
        printf("8. Reset Puzzle\n");

        // NEW MENU OPTION
        printf("9. Play Sudoku (Interactive Mode)\n");

        printf("0. Exit\n");

        printf("================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            int ch;

            printf("Invalid input! Enter a menu number.\n");

            while ((ch = getchar()) != '\n' && ch != EOF)
                ;

            continue;
        }

        switch (choice)
        {
            case 1:

                loadSample(grid);
                break;


            case 2:

                enterPuzzle(grid);
                break;


            case 3:

                displayGrid(grid);
                break;


            case 4:

                if (isValidGrid(grid))
                    printf("\nSudoku grid is valid!\n");
                else
                    printf("\nInvalid Sudoku grid!\n");

                break;


            case 5:

                if (!isValidGrid(grid))
                {
                    printf("\nCannot solve: invalid puzzle.\n");
                    break;
                }

                copyGrid(grid, solution);

                if (solveSudoku(solution))
                {
                    copyGrid(solution, grid);

                    printf("\nSudoku solved successfully!\n");

                    displayGrid(grid);
                }
                else
                {
                    printf("\nNo solution exists for this puzzle.\n");
                }

                break;


            case 6:

                giveHint(grid);
                break;


            case 7:

                showStatistics(grid);
                break;


            case 8:

                resetPuzzle(grid);
                break;


            // NEW CASE: INTERACTIVE SUDOKU
            case 9:

                startInteractiveGame(grid);
                break;


            case 0:

                printf("\nThank you for using Sudoku Solver Pro!\n");
                break;


            default:

                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}