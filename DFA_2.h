// =========================================================
// File: DFA_2.h
// Author: Sebastián Colín
// Last modification date: 02/06/2024
// Description: This file defines a DFA that accepts only 
// five words from an elven langauge.  
// =========================================================


#ifndef DFA_2_H_
#define DFA_2_H_

// Libraries 
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

// Enumeration to hold states (transition states and final state)
enum State {q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, qf};


/**
 * Determines whether the final state
 * is an accepted one
 * 
 * @param State: at a certain node in the DFA
 * @return bool: value for word in language or not
*/
bool accepting(State s) {
    return (s == qf)? true : false;
}

/**
 * Transitions from states by getting 
 * char inputs
 * 
 * @param State: current node in DFA, char: current character in the parsed word
 * @return State: the value of a node in DFA
*/
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


/**
 * Parses a word and determines wheter it is 
 * contained in the language or not
 * 
 * @param string: word to be parsed
 * @return bool: value for word in language or not
*/
bool acceptsWord(const string& word) {
    State currentState = q0;
    for (char c : word) {
        currentState = transition(currentState, c);
    }
    return accepting(currentState);
}

#endif
