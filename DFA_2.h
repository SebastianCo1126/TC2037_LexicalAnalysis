#include <iostream>
#include <unordered_set>
#include <string>

#ifndef DFA_2_H_
#define DFA_2_H_

using namespace std;

enum State {q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, qf};

bool accepting(State s) {
    return (s == qf)? true : false;
}

State transition(State state, char input) {
    switch (state) {
        case q0:
            if (input == 'e')
                return q1;
            else if (input == '%')
                return q10;
            break;
        case q1:
            if (input == 'c')
                return q3;
            else if (input == 'd')
                return q6;
            break;
        case q2:
            if (input == 'r')
                return qf;
            break;
        case q3:
            if (input == 'h')
                return q4;
            break;
        case q4:
            if (input == 'o')
                return q2;
            else if (input == 'u')
                return q5;
            break;
        case q5:
            if (input == 'i')
                return q2;
            break;
        case q6:
            if (input == 'h' || input == 'a')
                return q7;
            break;
        case q7:
            if (input == 'e')
                return q8;
            else if (input == 'i')
                return q9;
            break;
        case q8:
            if (input == 'l')
                return qf;
            break;
        case q9:
            if (input == 'n')
                return qf;
            break;
        case q10:
            if (input == 'a')
                return q2;
            break;
        default:
            break;
    }
    return q0; // Default transition for all other cases
}

bool accepts_word(const string& word) {
    State current_state = q0;
    for (char c : word) {
        current_state = transition(current_state, c);
    }
    return accepting(current_state);
}

// int main() {

//     cout << std::boolalpha; // outputs true or false for 1 || 0
//     cout << accepts_word("%ar") << endl;
//     cout << accepts_word("echor") << endl;
//     cout << accepts_word("echuir") << endl;
//     cout << accepts_word("edain") << endl;
//     cout << accepts_word("edhel") << endl;
//     cout << accepts_word("edhell") << endl; 

//     std::string usr_in;

//     while (true) {
//         cout << "Type a word or 0 to exit:";
//         cin >> usr_in;

//         if (usr_in != "0") {
//             accepts_word(usr_in)? cout << "Word IN the language.\n" : cout << "Word NOT IN the language.\n";
//         } else {
//             break;
//         }
//     }
//     return 0;
// }

#endif
