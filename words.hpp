#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

// Comparator struct
// struct CompareMyStruct {
//     bool operator()(const MyStruct& lhs, const MyStruct& rhs) const {
//         // Sort primarily by 'order', secondarily by 'data'
//         if (lhs.order != rhs.order) {
//             return lhs.order < rhs.order;
//         }
//         return lhs.data < rhs.data;
//     }
// };

int checkForcheck(string &word);
int factorial(int n);
void permute(string s, int start, int end, set<string> &allWords);
bool dicCheck(string word);

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
void permute(string s, int start, int end, set<string> &allWords) {
    // base case, if we are looking at the same letter/index
    if (start == end) {
        // cout << s << "\n";
        if (dicCheck(s)) {
            allWords.insert(s);
        }
    } else {
        for (int i = start; i <= end; i++) {
            swap(s[start], s[i]);
            permute(s, start + 1, end, allWords);
            // backtrack
            swap(s[start], s[i]);
        }
    }
}

// read the dictionary into a vector
void dicRead(vector<string> &dic) {
    ifstream dictionary("words.txt");
    string _word = "";
    while (dictionary >> _word) {
       dic.push_back(_word);
    }
}
