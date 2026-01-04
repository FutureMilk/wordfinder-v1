// good luck twin
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

const int LETTER_COUNT = 26;

using namespace std;

// checks if there's and exclamation point in the word
int checkForcheck(string &word) {
    int ctr = 0;
    for (char letter : word) {
        if (letter == '?') {
            ctr++;
        }
    }
    return ctr;
}



int main() {
    string testWord = "ayqr?";
    sort(testWord.begin(), testWord.end());
    cout << testWord;
    int min, max = 0;
    int checks = checkForcheck(testWord);
    if (checks > 0) {
       max = pow(LETTER_COUNT, checks);
       
    }
    return 0;
}