#ifndef SUDOKU_READER_H
#define SUDOKU_READER_H

#include "sudoku_solver.h"

class SudokuReader: public SudokuSolver {
    public:
        SudokuReader();
        void SetSudoku(const std::string &sudoku_file);
};

#endif