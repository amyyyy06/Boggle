#ifndef BOGGLE_BOGGLE_H
#define BOGGLE_BOGGLE_H

#include <string>
#include "Dictionary.h"

using namespace std;

const int BOARD_SIZE = 4;

class BoardNotInitialized {};

class Boggle {
public:
    Boggle();  // load "dictionary.txt" into dict
    explicit Boggle(string filename);  // load filename into dict

    void SetBoard(string board[BOARD_SIZE][BOARD_SIZE]);
    // Pre: Bord has been initialized.
    // Post: Copy each entry of board to this->board.

    void SolveBoard(bool printBoard, ostream& output);
    // Calls recursive function SolveBoardHelper to sore and save.

    void SaveSolve(string filename);   // Saves all the words from the last solve.
    // A wrapper function for SolveBoardHelper function.


    Dictionary GetDictionary();

    Dictionary WordsFound();

private:
    Dictionary dict;
    Dictionary wordsFound;
    string board[BOARD_SIZE][BOARD_SIZE];
    int visited[BOARD_SIZE][BOARD_SIZE];

    void PrintBoard(ostream& output);
    // Calls recursive function SolveBoardHelper to print out.
    int SolveBoardHelper(/* Put any parameters you want/need here */);
    // Post: Print out.
    //       All the words on the current board by board and save theses words to the dictionary.
};

#endif //BOGGLE_BOGGLE_H
