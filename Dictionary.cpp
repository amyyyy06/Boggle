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
    //Node*root = new Node;
    root = new Node;
    for(int i = 0; i < NUM_CHARS; i++){
        root->letters[i]= nullptr;
    }
    root->isWord = false;

    numWords = 0;

}

Dictionary::~Dictionary() {

}

Dictionary::Dictionary(string filename) {
   // root = new Node();
    root = new Node;
    for(int i = 0; i < NUM_CHARS; i++){
        root->letters[i]= nullptr;
    }

    string word;

    ifstream inputFile(filename);
    while(inputFile>>word){
        AddWord(word);
    }

    inputFile.close();


}

Dictionary &Dictionary::operator=(const Dictionary &otherDict) {
    //copyHelper(root, otherTree.root);
    //Make this of the instance empty
   // MakeEmpty();

    numWords = otherDict.numWords;


    for(int i = 0; i < NUM_CHARS; i++){
        copyHelper(root->letters[i], otherDict.root->letters[i]);
        //copyHelper(root, otherDict.root->letters[i]);
    }
    return *this; //<#initializer
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
        throw DictionaryError (filename+"failed to open");
    }
    SaveDictionaryHelper(root, " ", outFile);
    outFile.close();

}

void Dictionary::AddWord(string word) {
    Node* curr = root;
    for(int i = 0; i < word.size(); i++){
        int index = (int) word[i] - (int) 'a';
        if(curr -> letters[index]==nullptr) {
            curr -> letters[index] = new Node();
            curr->isWord = false;
        }

        curr = curr -> letters[index];
        if(index<0||index>26){
            throw DictionaryError("Invalid character");
        }
    }


    curr->isWord = true;
    numWords++;

}

void Dictionary::MakeEmpty() {  //??
    destroyHelper(root);
    Dictionary();

}

bool Dictionary::IsWord(string word) {
    Node*curr= root;
    for(int i = 0; i < word.size(); i++){
        //int index = (word[i]-'a');
        int index = (int) word[i] - (int) 'a';
        if(curr->letters[index]==nullptr)//{
            return false;

       // }
        curr = curr -> letters[index];
        if(index<0||index>26){
            throw DictionaryError("Invalid character");
        }
    }
    return curr->isWord==true;



}

bool Dictionary::IsPrefix(string word) {
    Node*curr= root;
    for(int i = 0; i < word.size(); i++){
        //int index = (word[i]-'a');
        int index = (int) word[i] - (int) 'a';
        if(curr->letters[index]==nullptr){
            return false;
        }
        curr = curr -> letters[index];
        if(index<0||index>26){
            throw DictionaryError("Invalid character");
        }
    }
    return true;
}

int Dictionary::WordCount() {
    return 0;
}

void Dictionary::destroyHelper(Dictionary::Node *thisTree) {

    if (thisTree == nullptr)
        return;

    for (int i; i< NUM_CHARS; i++){
        destroyHelper(thisTree-> letters[i] );
    }

    delete thisTree;
    //Dictionary();
    // root = nullptr;
    //  numWords = 0;


}

void Dictionary::copyHelper(Dictionary::Node *&thisTree, Dictionary::Node *&otherTree) {
    if (otherTree == nullptr) {
        thisTree = nullptr;
        return;
    }

    thisTree = new Node;
    thisTree->isWord = otherTree->isWord;
    //26 branch
    for(int i = 0; i<NUM_CHARS; i++){
        copyHelper(thisTree->letters[i], otherTree->letters[i]);

    }

    //CopyHelper(thisTree->left, otherTree->left);
    // CopyHelper(thisTree->right, otherTree->right);


}

void Dictionary::SaveDictionaryHelper(Dictionary::Node *curr, string currPrefix, ofstream &outFile) {

    if (curr == nullptr)
        return;

    if (curr->isWord) {
        outFile << currPrefix << endl;
    }
      for(int i = 0; i < NUM_CHARS; i++){
          //  if(curr->letters[i]!=nullptr){
          SaveDictionaryHelper(curr->letters[i],currPrefix+(char)(i+(int)'a'), outFile);

          //  }

          // SaveDictionaryHelper(curr->letters[i], currPrefix+,outFile);

      }


}

