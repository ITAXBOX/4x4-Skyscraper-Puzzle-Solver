# 4x4 Skyscraper Puzzle Solver

A C program that solves 4x4 Skyscraper puzzles using backtracking.

## Table of Contents
- [Description](#description)
- [How It Works](#how-it-works)
- [Installation](#installation)
- [Usage](#usage)
- [Input Format](#input-format)
- [Examples](#examples)
- [File Structure](#file-structure)
- [Algorithm](#algorithm)
- [Limitations](#limitations)
- [Future Improvements](#future-improvements)
- [Contributing](#contributing)
- [License](#license)

## Description

This program takes a set of Skyscraper puzzle constraints as input and outputs a valid 4x4 grid solution that satisfies all the constraints. The puzzle follows standard Skyscraper rules:
- Each row and column must contain numbers 1-4 without repetition.
- Numbers represent building heights (1 = shortest, 4 = tallest).
- The clues indicate how many buildings are visible from that direction.

## How It Works

The solver uses a recursive backtracking algorithm to:
1. Try all valid numbers (1-4) in each cell.
2. Check that numbers are unique in their row and column.
3. Verify the solution matches all visibility constraints.
4. Return the first valid solution found.

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/ITAXBOX/4x4-Skyscraper-Puzzle-Solver.git
    cd 4x4-Skyscraper-Puzzle-Solver
    ```

2. Compile the program:
    ```bash
    gcc -o skyscraper main.c valid.c solve.c check.c
    ```

## Usage

Run the program with the input constraints as a single string:
```bash
./skyscraper "1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4"
```

## Input Format

The input must be a single string of 16 numbers (1-4) separated by spaces, representing the constraints in this order:
- **First 4 numbers**: Top view constraints (columns, top-to-bottom).
- **Next 4 numbers**: Bottom view constraints (columns, bottom-to-top).
- **Next 4 numbers**: Left view constraints (rows, left-to-right).
- **Last 4 numbers**: Right view constraints (rows, right-to-left).

### Example Input:
```plaintext
"1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4"
```

## Examples

### Simple Puzzle:
```bash
./skyscraper "1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4"
```

## File Structure

```
4x4-Skyscraper-Puzzle-Solver/
├── main.c        # Program entry point, I/O handling
├── valid.c       # Input validation functions
├── solve.c       # Backtracking solver implementation
├── check.c       # Constraint checking functions
└── README.md     # This documentation
```

## Algorithm

### Input Validation:
- Verify the input string has exactly 16 numbers (1-4) with proper spacing.

### Backtracking Solver:
1. Fill the grid cell by cell.
2. For each cell, try numbers 1-4 that don't conflict with existing numbers in the row/column.
3. When the grid is complete, check all visibility constraints.

### Constraint Checking:
- For each row/column, count visible skyscrapers from both directions.
- Verify counts match the input clues.

## Limitations

- Only handles 4x4 grids.
- Input format is strict (exactly one space between numbers).
- No optimization for harder puzzles.
- Only finds one solution (even if multiple exist).

## Future Improvements

- Support for larger grid sizes (6x6, 8x8).
- More flexible input handling.
- Optimized solving algorithm.
- Better error messages.
- Visual output format.
- Puzzle generator.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
