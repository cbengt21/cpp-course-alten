#include "sudoku_solver.h"
#include <iostream>
#include <fstream>

SudokuSolver::SudokuSolver(){}

void SudokuSolver::SetSudoku(const std::string &file){
    std::ifstream sudoku_file;
    sudoku_file.open(file);

    if (!sudoku_file){
        std::cout << "Error opening the file" << std::endl;
        exit(-1);
    } else {
        for(int i=0; i <9; ++i){
            for(int j=0; j <9; ++j){
                sudoku_file >> sudoku[i][j].value;
            }
        }
        sudoku_file.close();
    }
}
bool SudokuSolver::CheckIfEmptyCells(int &row, int &col) const{
    for (row=0; row < 9; row++) // go through sudoku to see if there is empty cells.
    {
        for (col = 0; col < 9; col++)
        {
            if (sudoku[row][col].value==0){
                return true;
            }
        }
    }
    return false;
}
bool SudokuSolver::RecursiveSearch(){
    int row, col;
    
    if (!CheckIfEmptyCells(row, col))
        return true;
    
    //find cell with least possible values:
    //findCellWithLeastPossibleNr(row, col);
    //while(CheckAndFillPossibleVal(row, col));
    //CheckRow(row, col);
    //CheckCol(row, col);
    //CheckBox(row - row%3 , col - col%3, row, col);

    /*for (int num=1; num<=9; num++){
        if (sudoku[row][col].arr_possible_values_[num-1]==true){
            sudoku[row][col].value=num;
            std::cout << row << "\t" << col <<"  writing value"<< "\n";
            if(RecursiveSearch()){
                return true;
            }    
            sudoku[row][col].value = 0;   
            std::cout << row << "\t" << col <<"  reseting value"<< "\n";
        }
    }*/
    for (int num=1; num<=9; num++){
        if (sudoku[row][col].arr_possible_values_[num-1]==true && IsValidPlace(row, col, num)){
            sudoku[row][col].value=num;
            //std::cout << row << "\t" << col <<"  writing value"<< "\n";
            if(RecursiveSearch()){
                return true;
            }    
            sudoku[row][col].value = 0;   
            //std::cout << row << "\t" << col <<"  reseting value"<< "\n";
        }
    }
    return false;
}
bool SudokuSolver::IsValidPlace(const int &row, const int &col, const int &num) const{
    return !IsPresentInRow(row, num) && !IsPresentInCol(col, num) && !IsPresentInBox(row - row%3 , col - col%3, num);
}
bool SudokuSolver::SolveSudoku (){ 
    while (FindPossibleValues()){
        if(!CheckAndFillUniqueNr()){ //if no unique nr was found then puzzle not possible to solve only with constraint propagation.
            /*for(int x=0;x<9;x++){   //copy start grid
                for(int y=0;y<9;y++){
                    sudoku_copy_[x][y]=sudoku[x][y];
                }
            }*/
            //Print("Grid before recursion!");
            if(RecursiveSearch()){
                return true;
            }
            return false;
        }
    }
    return true;
}
bool SudokuSolver::FindPossibleValues(){ //returns false if no empty place
    while(LoopThroughEmptyCells()); // loop until no value is set anymore, then check if there is still empty cells
    if (nr_of_empty_cells_ == 0){
        return false;
    } else{
        return true;
    }
}
bool SudokuSolver::LoopThroughEmptyCells(){
    for (int i=0; i < 9; i++) // go through sudoku to see if there is empty cells.
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j].value==0){
                if (CheckAndFillPossibleVal(i, j)==true){ // if value set, restart loop to check possible values again as it may be changed.
                    nr_of_empty_cells_ =0;
                    return true;
                } else {
                    nr_of_empty_cells_ += 1; //if cell is empty and no value is set, increment nr of empty cells.
                }
            }
        }
    }
    return false;
}
//int setValues =0; //for debugging only
bool SudokuSolver::CheckAndFillPossibleVal(const int &row, const int &col){ //Check cell for possible values, return true if value filled
    sudoku[row][col].nr_of_possible_values_ =0;
    for (int num=1; num<10; num++){
        if (IsValidPlace(row, col, num)){
            sudoku[row][col].arr_possible_values_[num-1]=true;
            sudoku[row][col].nr_of_possible_values_ +=1;        //add pointer to the cell with fewest possible values?
        } else{
            sudoku[row][col].arr_possible_values_[num-1]=false;
        }
    }
    if (sudoku[row][col].nr_of_possible_values_ == 1){ // set value if only one possible
        for (int num =0; num<10; num++){
            if (sudoku[row][col].arr_possible_values_[num-1] == true){
                sudoku[row][col].value = (num);
                //setValues += 1; //debugging only
                //std::cout << "Value was filled by CheckAndFillPossibleVal! " << setValues << std::endl; //debugging only
                return true;
            }
        }
    }
    return false;
}
bool SudokuSolver::CheckAndFillUniqueNr(){
    bool resBox = false;
    bool resRow = false;
    bool resCol = false;

    for (int row = 0; row<9; row++){
        for (int col=0; col<9; col++){
            if(sudoku[row][col].value==0){
                for(int num=1 ; num<10 ; num++){
                    if(sudoku[row][col].arr_possible_values_[num-1]==true){
                        resBox = IsUniqueInBox(row - row%3 , col - col%3, row, col, num);
                        resRow = IsUniqueInRow(row, col, num);
                        resCol = IsUniqueInCol(col, row, num);
                        if (resBox==true || resRow==true || resCol==true){
                            sudoku[row][col].value=num; // write value if unique
                            //std::cout << "Value was filled by CheckAndFillUniqueNr! "  << std::endl; //debugging only
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
bool SudokuSolver::IsUniqueInCol(const int &col, const int &row_skip, const int &num) const{ //check whether num is unique in col or not
    for (int row = 0; row < 9; row++)
    {
        if(row == row_skip){ //skip cell we are checking unique value for
            continue;
        }
        if(sudoku[row][col].value == 0){
            if (sudoku[row][col].arr_possible_values_[num-1] == true){ //check if value is amongst the possible values for the cell
                return false;
            }
        }
    }
    return true; //looped through and it's not there so yes, unique.
}
bool SudokuSolver::IsUniqueInRow(const int &row, const int &col_skip, const int &num) const{ //check whether num is unique in row or not
    for (int col = 0; col < 9; col++)
    {
        if(col == col_skip){ //skip cell we are checking unique value for
            continue;
        }
        if(sudoku[row][col].value == 0){
            if (sudoku[row][col].arr_possible_values_[num-1] == true){ //check if value is amongst the possible values for the cell
                return false;
            }
        }
    }
    return true; //looped through and it's not there so yes, unique.
}
bool SudokuSolver::IsUniqueInBox(const int &box_start_row, const int &box_start_col, const int &row_skip, const int &col_skip, const int &num) const{ //check whether num is unique in 3x3 box or not
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if(row_skip == (row+box_start_row) && col_skip==(col+box_start_col)){ //skip cell we are checking unique value for
                continue;
            }
            if(sudoku[row+box_start_row][col+box_start_col].value == 0){
                if (sudoku[row+box_start_row][col+box_start_col].arr_possible_values_[num-1] == true){ //check if value is amongst the possible values for the cell
                    return false;
                }
            }
        }
    }
    return true; //looped through and it's not there so yes, unique.
}
bool SudokuSolver::IsPresentInCol(const int &col, const int &num) const{ //check whether num is present in col or not
    for (int row = 0; row < 9; row++)
    {
        if (sudoku[row][col].value == num){ //value found
            return true;
        }
    }
    return false;
}
bool SudokuSolver::IsPresentInRow(const int &row, const int &num) const{ //check whether num is present in row or not
    for (int col = 0; col < 9; col++)
    {
        if (sudoku[row][col].value == num){ //value found
            return true;
        }
    }
    return false;
}
bool SudokuSolver::IsPresentInBox(const int &box_start_row, const int &box_start_col, const int &num) const{ //check whether num is present in 3x3 box or not
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (sudoku[row+box_start_row][col+box_start_col].value == num){ //value found
                return true;
            }
        }
    }
    return false;
}
void SudokuSolver::Print(const std::string &sudoku_status) const{
    std::cout <<"\nPrinting " << sudoku_status << std::endl;
    for (int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++){
            if(col == 3 || col == 6)
                std::cout << " | ";
            std::cout << sudoku[row][col].value <<" ";
        }
        if(row == 2 || row == 5){
            std::cout << std::endl;
            for(int i = 0; i<9; i++)
                std::cout << "---";
        }
        std::cout << std::endl;
    }
}