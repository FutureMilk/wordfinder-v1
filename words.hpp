#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <fstream>
#include <vector>
#include <set>

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

//find the diff permutations
void permute(string s, int start, int end) {
    // base case, if we are looking at the same letter/index
    if (start == end) {
        cout << s << "\n";
    } else {
        for (int i = start; i <= end; i++) {
            swap(s[start], s[i]);
            permute(s, start + 1, end);
            // backtrack
            swap(s[start], s[i]);
        }
    }
}

bool dicCheck(string word) {
    ifstream dictionary("words.txt");
    string _word = "";
    while (dictionary >> _word) {
        if (_word == word) {return true;}
    }
    return false;
}