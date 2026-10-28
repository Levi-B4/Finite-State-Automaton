#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> constructDFA(string pattern) {
    int m = pattern.size();

    int alphabetLength = 128;                                                   // ascii

    vector<vector<int>> transitions(m + 1, vector<int>(alphabetLength));        // create vector of all states the size of the total alphabet

    transitions[0][pattern[0]] = 1;                                             // set first state (root) to have an entry point to the first char in the pattern

    int x = 0;                                                                  // the current state when reading the pattern
    for(int i = 1; i <= m; i++){                                                // loop through the pattern
        for(int j = 0; j < alphabetLength; j++){                                // loop through each char in each state, the alphabet
            transitions[i][j] = transitions[x][j];                              // if this letter is equal to the first letter in the patetrn, then we continue to that state. continue until the current suffix no longer matches the first part of the pattern
        }
        if(i < m) {                                                             // for all parts of the pattern but the last char
            transitions[i][pattern[i]] = i + 1;                                 // set the state that aligns to the pattern's current char to go to the next char in the pattern state
            x = transitions[x][pattern[i]];                                     // set x to be the next transition
        }
    }

    return transitions;
}

vector<int> dfaStringMatching(string pattern, string text){
    vector<int> occurrences;
    vector<vector<int>> dfa = constructDFA(pattern);


    int state = 0;
    for(int i = 0; i < text.size(); i++){
        state = dfa[state][text[i]];
        if(state == pattern.size()){
            occurrences.emplace_back(i - pattern.size() + 1);
        }
    }

    return occurrences;
}

/*
 * o = alphabet.size()
 * n = text.size()
 * m = pattern.size()
 *
 * space = O(m * o)
 *
 * creation time = O(m * o)
 * string matching = O(n)
 *
 * dfa string matching = o((m * o) + n)
 */


int main()
{

    vector<int> output = dfaStringMatching("Levi", "Hello Levi, my name is also Levi!");
    vector<int> test{6, 28};

    if(output == test){
        cout << "it worked!\n";
    } else {
        cout << "it didnt work :(\noutput: ";
        for(int i : output){
            cout << i << ", ";
        }
        cout << "\ntest: ";
        for(int i : test){
            cout << i << ", ";
        }
    }

    return 0;
}
