// good luck twin

#include "words.hpp"

const int ALPHABET_NUM = 26;

using namespace std;





int main() {
    string word = "ayqrbe";
    
    for (auto& x : word) {
        x = toupper(x);
    }

    int wordLength = word.length();
    sort(word.begin(), word.end());
    cout << word;
    int min, max = 0;
    int qMarks = checkForcheck(word);

    vector<string> dictionary;
    dictionary.reserve(267751);
    dicRead(dictionary);

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
        permute(newWord, 0, newWord.length(), allWords, dictionary);
    }

    for (auto x: allWords) {
        cout << x << "\n";
    }
    

  

    return 0;
}