#include "Dictionary.h"

// Your code here


// The copy constructor is complete.
// However, the operator= must be completed for it to work.
Dictionary::Dictionary(const Dictionary &otherDict) {
    root = new Node;
    numWords = 0;
    *this = otherDict;
}



