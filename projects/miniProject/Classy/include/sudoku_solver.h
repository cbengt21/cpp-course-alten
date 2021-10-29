#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

#include <iostream>

typedef struct Cell {   // keep in same file as only one type, otherwise use namespace and separate file..
    int value = 0;
    int nr_of_possible_values_ = 0;
    bool arr_possible_values_[9] = {false, false, false, false, false, false, false, false, false};
} Cell_t;


class SudokuSolver {
    protected:
        Cell_t sudoku[9][9];
        int nr_of_empty_cells_ = 0;

        bool CheckIfEmptyCells(int &row, int &col) const;
        bool LoopThroughEmptyCells();
        bool IsValidPlace(const int &row, const int &col, const int &num) const;
        bool FindPossibleValues();
        bool CheckAndFillPossibleVal(const int &row, const int &col);
        bool CheckAndFillUniqueNr();
        bool IsUniqueInCol(const int &col,const int &row_skip, const int &num) const;
        bool IsUniqueInRow(const int &row, const int &col_skip, const int &num) const;
        bool IsUniqueInBox(const int &box_start_row, const int &box_start_col,const int &row_skip,const int &col_skip, const int &num) const;
        bool IsPresentInCol (const int &col, const int &num) const;
        bool IsPresentInRow (const int &row, const int &num) const;
        bool IsPresentInBox (const int &box_start_row, const int &box_start_col, const int &num) const;
        bool RecursiveSearch();

    public:
        SudokuSolver();
        virtual void SetSudoku(const std::string &sudoku_file);
        bool SolveSudoku();
        void Print(const std::string &sudoku_status) const;
};

#endif