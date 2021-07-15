
#include "Dictionary.h"
#include "Boggle.h"

// Your code here


// This function is done.
Dictionary Boggle::GetDictionary() {
    return dict;
}

// This function is done.
Dictionary Boggle::WordsFound() {
    return wordsFound;
}

Boggle::Boggle() {
    Dictionary dict("dictionary.txt");
    board[BOARD_SIZE][BOARD_SIZE]=" ";
    visited[BOARD_SIZE][BOARD_SIZE]= false;


}

Boggle::Boggle(string filename) {

}

void Boggle::SetBoard(string (*board)[4]) {

}

void Boggle::SolveBoard(bool printBoard, ostream &output) {

}

void Boggle::SaveSolve(string filename) {

}

void Boggle::PrintBoard(ostream &output) {

}

int Boggle::SolveBoardHelper(int row, int col, ostream &output) {
    return 0;
}


