// good luck twin

#include "words.hpp"

const int ALPHABET_NUM = 26;

using namespace std;

int checkForcheck(string &word);
int factorial(int n);
void permute(string s, int start, int end, set<string> &allWords);
bool dicCheck(string word);



int main() {
    string word = "ayqr?be";
    int wordLength = word.length();
    sort(word.begin(), word.end());
    cout << word;
    int min, max = 0;
    int qMarks = checkForcheck(word);

    if (qMarks > 0) {
        // 26^q * (n-q)!
        // 26 letter options for each question mark,
        // factorial the rest of the letter options, minus the question marks
        max = pow(ALPHABET_NUM, qMarks) * factorial(wordLength - qMarks);
    } else {
        max = factorial(wordLength);
    }

    // reserve space in vector
    set<string> allWords;
    // allWords.reserve(max);

    string newWord = "";
    for (int i = 0; i < wordLength; i++) {
        newWord += word[i];
        permute(newWord, 0, newWord.length(), allWords);
    }

    for (auto x: allWords) {
        cout << x << "\n";
    }
    

  

    return 0;
}