

#include "Dictionary.h"

// Your code here


// The copy constructor is complete.
// However, the operator= must be completed for it to work.
Dictionary::Dictionary(const Dictionary &otherDict) {

    root = new Node;
    numWords = 0;
    *this = otherDict;
}

Dictionary::Dictionary() {
    root = new Node;
    numWords = 0;

}

Dictionary::~Dictionary() {
}

Dictionary::Dictionary(string filename) {
    root = new Node;
    LoadDictionaryFile(filename);

}

Dictionary &Dictionary::operator=(const Dictionary &otherDict) {

    root = new Node;
    numWords = otherDict.numWords;

    for(int i = 0; i < NUM_CHARS; i++)
    {
        copyHelper(root->letters[i], otherDict.root->letters[i]);
    }

    return *this;

}

void Dictionary::LoadDictionaryFile(string filename) {
    string word;

    ifstream inputFile(filename);
    while(inputFile>>word){
        AddWord(word);

    }

     inputFile.close();

}

void Dictionary::SaveDictionaryFile(string filename) {

    ofstream outFile(filename);
    if(outFile.fail()){
        throw DictionaryError (filename+" failed to open");
    }
    SaveDictionaryHelper(root, " ", outFile);
    outFile.close();

}

void Dictionary::AddWord(string word) {
    Node* curr = root;
    for(int i = 0; i < word.length(); i++){
        int index = (int) word[i] - (int) 'a';

        if(index<0||index >= NUM_CHARS){ //index<0||index>26
            throw DictionaryError("Invalid character");
        }

        if(curr -> letters[index]==nullptr) {
            curr -> letters[index] = new Node();
        }

        curr = curr -> letters[index];
    }


    curr->isWord = true;
    numWords++;

}

void Dictionary::MakeEmpty() {
    destroyHelper(root);
    root = new Node;
    numWords = 0;
}



bool Dictionary::IsWord(string word) {
    Node*curr= root;
    for(int i = 0; i < word.length(); i++){
        int index = (int) word[i] - (int) 'a';

        if(index<0||index>NUM_CHARS){
            throw DictionaryError("Invalid character");
        }

        if(curr->letters[index]==nullptr){
            return false;
        }
        curr = curr -> letters[index];

    }
    return curr->isWord;


}

bool Dictionary::IsPrefix(string word) {
    Node*curr= root;
    for(int i = 0; i < word.length(); i++){
        int index = (int) word[i] - (int) 'a';

        if(index<0||index>NUM_CHARS){
            throw DictionaryError("Invalid character");
        }

        if(curr->letters[index]==nullptr){
            return false;
        }
        curr = curr -> letters[index];

    }
    return true;
}

int Dictionary::WordCount() {
    //return 0;
    return numWords;
}

void Dictionary::destroyHelper(Dictionary::Node *thisTree) {
    if(thisTree == nullptr)
    {
        return;
    }

    for (int i = 0; i < NUM_CHARS; i++){
        destroyHelper(thisTree-> letters[i] );
        thisTree->letters[i] = nullptr;
    }

    delete thisTree;


}

void Dictionary::copyHelper(Dictionary::Node *&thisTree, Dictionary::Node *&otherTree) {
    if (otherTree == nullptr)
    {
        thisTree = nullptr;
        return;
    }

    thisTree = new Node;
    for(int i = 0; i < NUM_CHARS; i++)
    {
        thisTree->letters[i] = otherTree->letters[i];
        copyHelper(thisTree->letters[i], otherTree->letters[i]);
    }
    thisTree->isWord = otherTree->isWord;

}

void Dictionary::SaveDictionaryHelper(Dictionary::Node *curr, string currPrefix, ofstream &outFile) {

    if (curr == nullptr)
        return;

    if (curr->isWord) {
        outFile << currPrefix << endl;
    }
    for(int i = 0; i < NUM_CHARS; i++){
        SaveDictionaryHelper(curr->letters[i], currPrefix + (char)(i + (int)'a'),outFile);
    }


}

