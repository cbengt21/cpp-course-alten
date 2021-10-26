#include "sudoku_reader.h"
#include <fstream>

SudokuReader::SudokuReader(){}

void SudokuReader::SetSudoku(const std::string &file){
    std::ifstream sudoku_file;
    sudoku_file.open(file);

    if (!sudoku_file){
        std::cout << "Error opening the file" << std::endl;
        exit(-1);
    } else {
        std::string line;
        int num;
        std::getline(sudoku_file, line);
        //std::cout << line << std::endl;
        //while (std::getline(sudoku_file, line)) {     // let's see later if we can run multiple sudokus from same file..
            int line_pos=0;
            for(int i = 0; i < 9; i++){
                for(int j=0; j < 9; j++){
                    if (line[line_pos]<= '9' && line[line_pos]>= '0'){
                        num = std::stoi(line.substr(line_pos,1));
                        sudoku[i][j].value=num;
                    }
                    line_pos+=1;
                }
            }
        
        //}
        sudoku_file.close();
    }
    return;
}