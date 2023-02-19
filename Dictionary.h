#ifndef BOGGLE_DICTIONARY_H
#define BOGGLE_DICTIONARY_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


const int NUM_CHARS = 26;

class DictionaryError{
public:
    explicit DictionaryError(string msg) {
        this->msg = msg;
    }
    string Msg(){
        return msg;  // returns king of flavor
    }
private:
    string msg;
};

class Dictionary
{

public:
    Dictionary();
    ~Dictionary();  // I will not require this
    Dictionary(const Dictionary& otherDict);    // copy constructor
    explicit Dictionary(string filename);       // The keyword explicit is used to tell the compiler
                                                // that this is not a conversion constructor.

    Dictionary& operator=(const Dictionary& otherDict);
    //Calls the recursive function copyHelper to copy a binary tree in class.
    void LoadDictionaryFile(string filename);
    // Post: Add all the words in the file to dictionary.
    void SaveDictionaryFile(string filename);
    // Calls the recursive function to save words to a file. It is a "Wrapper" for the SaveDictionaryHelper function.

    void AddWord(string word);
    // Pre: Tree has been initialized.
    // Post: Add a word to the tree.
    void MakeEmpty();
    // Call recursive function destroyHelper to destroy all the nodes in the tree. It is a wrapper function for the destroyHelper.

    bool IsWord(string word);
    // Pre:  Tree has been initialized.
    // Post: Check a provided word exists in the dictionary.
    bool IsPrefix(string word);
    // Pre:  Tree has been initialized.
    // Post: Check at least one word in the dictionary starts with a particular prefix.
    int WordCount();
    // Number of word in the tree.


private:
    class Node {
    public:
        // Your node structure here.
        // You can also use a struct if you like.

        Node* letters[NUM_CHARS];
        bool isWord;

        Node() { // added here
            isWord = false;
            for (int i = 0; i < NUM_CHARS; i++) {
                letters[i] = nullptr;
            }
        }

    };

    Node* root;
   // Node* letters[NUM_CHARS]; //branch
    int numWords;

    // Any private methods you need/want
    // You may change these helpers if you want, but you don't need to.
    void destroyHelper(Node* thisTree);
    //post: Tree is empty. Destroy all the nodes in the tree.

    void copyHelper(Node*& thisTree, Node*& otherTree);
    //post: Copy all of the values.

    void SaveDictionaryHelper(Node* curr, string currPrefix, ofstream& outFile);
    //post: Save words to a file.


};

#endif //BOGGLE_DICTIONARY_H
