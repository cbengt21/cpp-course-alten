#include <iostream>
//#include <fstream>
#include <chrono>
#include "sudoku_solver.h"
#include "sudoku_reader.h"

template <class T1>
void RunSudoku (T1 a){
    a.Print("Base grid!"); 
    auto start = std::chrono::high_resolution_clock::now();
    if (a.SolveSudoku()==true){
        //TODO: check that solved puzzle is correct
        auto stop = std::chrono::high_resolution_clock::now();
        a.Print("Solved grid!");
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "\n\nTimestamp: " << duration.count() << " microseconds\n" << std::endl;
    } else{
        std::cout << "No solution found";
        a.Print("Unsolved grid!");
    }
    return;
}

int main(int argc, char** argv){
    //std::string s = "..74.1.2.8.......7.....3....5....6....82.7.1.....9......4.3........8..9.6..9.41..";

    if (argc == 1){ //if no input file, take one from directory
        SudokuSolver S;
        S.SetSudoku("sudokus/evil.txt");
        RunSudoku(S);
    } else if (argc == 2){ //if input file provided in command line, take that file
        std::string s = argv[1];
        SudokuReader R;
        R.SetSudoku(s);
        RunSudoku(R);
    }
}