#include <iostream>
#include <fstream>

const int N = 9;

typedef struct Cell {
    int value = 0;
    bool arrPossibleValues[9] = {false, false, false, false, false, false, false, false, false};
    int nrOfPossibleValues = 0;
} Cell_t;

Cell_t sudoku_[9][9];

bool solveSudoku();
void print(const std::string &sudokuStatus);
bool findEmptyPlace();
bool isPresentInCol (const int &col, const int &num);
bool isPresentInRow (const int &row, const int &num);
bool isPresentInBox (const int &boxStartRow, const int &boxStartCol, const int &num);
bool checkAndFillPossibleVal(const int &row, const int &col);
void readTextFile();
bool checkForUniqueNr();
bool isUniqueInCol(const int &col,const int &rowSkip, const int &num);
bool isUniqueInRow(const int &row, const int &colSkip, const int &num);
bool isUniqueInBox(const int &boxStartRow, const int &boxStartCol,const int &rowSkip,const int &colSkip, const int &num);

int main(){

    readTextFile();
    print("Base grid!"); 
    if (solveSudoku()==true){
        //TODO: check that solved puzzle is correct
        print("Solved grid!");
    } else{
        std::cout << "No solution found";
        print("Unsolved grid!");
    }
}

void readTextFile(){
    std::ifstream sudokufile;
    sudokufile.open("evil.txt");

    if (!sudokufile){
        std::cout << "Error opening the file" << std::endl;
        exit(-1);
    } else {
        for(int i=0; i <9; ++i){
            for(int j=0; j <9; ++j){
                sudokufile >> sudoku_[i][j].value;
            }
        }
        sudokufile.close();
    }
    return;
}


bool solveSudoku (){  //TODO: while findEmptyPlace || findUniquepossibleNr was unsuccessful, continue altering 
    while (findEmptyPlace()){
        if(!checkForUniqueNr()){ //if no unique nr was found then dead end and no reason to continue, puzzle not possible to solve with the two ways.
            return false;
        }
    }
    return true;
}

bool findEmptyPlace(){ //returns false if no empty place
    int nrOfEmptyCells = 0;
    int i = 0;
    for (int i=0; i < 9; i++) // go through sudoku to see if there is empty cells.
    {
        for (int j = 0; j < 9; j++){
            if (sudoku_[i][j].value==0){
                if (checkAndFillPossibleVal(i, j)==true){ // if value set, restart loop to check possible values again as i may be changed.
                    j=0;
                    i=-1;
                    nrOfEmptyCells=0;
                    break;
                } else {
                    nrOfEmptyCells += 1; //if cell is empty and no value is set, increment nr of empty cells.
                }
            }
        }
    }
    if (nrOfEmptyCells == 0){
        return false;
    } else{
        return true;
    }
}
int setValues =0; //for debugging only
bool checkAndFillPossibleVal(const int &row, const int &col){ //Check cell for possible values, return true if value filled
    bool resBox = false;
    bool resRow = false;
    bool resCol = false;
    sudoku_[row][col].nrOfPossibleValues =0;
    for (int i=1; i<10; i++){
        resBox = isPresentInBox(row - row%3 , col - col%3, i);
        resRow = isPresentInRow(row, i);
        resCol = isPresentInCol(col, i);
        if (resBox==false && resRow==false && resCol==false){
            sudoku_[row][col].arrPossibleValues[i-1]=true;
            sudoku_[row][col].nrOfPossibleValues +=1; //:TODO add pointer to the cell with fewest possible values?
        } else{
            sudoku_[row][col].arrPossibleValues[i-1]=false;
        }
    }
    if (sudoku_[row][col].nrOfPossibleValues == 1){ // set value if only one possible
        for (int k =0; k<9; k++){
            if (sudoku_[row][col].arrPossibleValues[k] == true){
                sudoku_[row][col].value = (k+1);
                setValues += 1; //debugging only
                std::cout << "Value was filled by checkAndFillPossibleVal! " << setValues << std::endl;
                return true;
            }
        }
    }
    return false;
}

bool checkForUniqueNr(){
    //1) loop through row, cell and box for unique nr. Return true if unique nr found.
    bool resBox = false;
    bool resRow = false;
    bool resCol = false;

    for (int row = 0; row<9; row++){
        for (int col=0; col<9; col++){
            if(sudoku_[row][col].value==0){
                for(int k=0 ; k<9 ; k++){
                    if(sudoku_[row][col].arrPossibleValues[k]==true){
                        resBox = isUniqueInBox(row - row%3 , col - col%3, row, col, k+1);
                        resRow = isUniqueInRow(row, col, k+1);
                        resCol = isUniqueInCol(col, row, k+1);
                        if (resBox==true || resRow==true || resCol==true){
                            sudoku_[row][col].value=k+1;
                            std::cout << "Value was filled by checkForUniqueNr! "  << std::endl;
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
bool isUniqueInCol(const int &col, const int &rowSkip, const int &num){ //check whether num is present in col or not
    for (int row = 0; row < N; row++)
    {
        if(row == rowSkip){
            continue;
        }
        if(sudoku_[row][col].value == 0){
            if (sudoku_[row][col].arrPossibleValues[num-1] == true){
                return false;
            }
        }
    }
    return true; //looped through and it's not there so yes, unique.
}
bool isUniqueInRow(const int &row, const int &colSkip, const int &num){ //check whether num is present in row or not
    for (int col = 0; col < N; col++)
    {
        if(col == colSkip){
            continue;
        }
        if(sudoku_[row][col].value == 0){
            if (sudoku_[row][col].arrPossibleValues[num-1] == true){
                return false;
            }
        }
    }
    return true; //looped through and it's not there so yes, unique.
}
bool isUniqueInBox(const int &boxStartRow, const int &boxStartCol, const int &rowSkip, const int &colSkip, const int &num){ //check whether num is present in 3x3 box or not
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if(rowSkip == (row+boxStartRow) && colSkip==(col+boxStartCol)){
                continue;
            }
            if(sudoku_[row+boxStartRow][col+boxStartCol].value == 0){
                if (sudoku_[row+boxStartRow][col+boxStartCol].arrPossibleValues[num-1] == true){
                    return false;
                }
            }
        }
    }
    return true; //looped through and it's not there so yes, unique.
}
bool isPresentInCol(const int &col, const int &num){ //check whether num is present in col or not
    for (int row = 0; row < N; row++)
    {
        if (sudoku_[row][col].value == num){
            return true;
        }
    }
    return false;
}
bool isPresentInRow(const int &row, const int &num){ //check whether num is present in row or not
    for (int col = 0; col < N; col++)
    {
        if (sudoku_[row][col].value == num){
            return true;
        }
    }
    return false;
}
bool isPresentInBox(const int &boxStartRow, const int &boxStartCol, const int &num){ //check whether num is present in 3x3 box or not
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (sudoku_[row+boxStartRow][col+boxStartCol].value == num){
                return true;
            }
        }
    }
    return false;
}
void print(const std::string &sudokuStatus){
    std::cout <<"\nPrinting " << sudokuStatus << std::endl;
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){
            if(col == 3 || col == 6)
                std::cout << " | ";
            std::cout << sudoku_[row][col].value <<" ";
        }
        if(row == 2 || row == 5){
            std::cout << std::endl;
            for(int i = 0; i<N; i++)
                std::cout << "---";
        }
    std::cout << std::endl;
    }
    return;
}