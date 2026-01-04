// good luck twin
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

const int ALPHABET_NUM = 26;

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

// calculate the factorial of the number w/ recursion
int factorial(int n) {
  if (n > 1)
    return n * factorial(n - 1);
  else
    return 1;
}



int main() {
    string testWord = "ayqr?be";
    int wordLength = testWord.length();
    sort(testWord.begin(), testWord.end());
    cout << testWord;
    int min, max = 0;
    int qMarks = checkForcheck(testWord);

    if (qMarks > 0) {
        // 26^q * (n-q)!
        // 26 letter options for each question mark,
        // factorial the rest of the letter options, minus the question marks
        max = pow(ALPHABET_NUM, qMarks) * factorial(wordLength - qMarks);
    } else {
        max = factorial(wordLength);
    }

    return 0;
}