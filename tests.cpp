// =========================================================
// File: tests.cpp
// Author: Sebastián Colín
// Last modification date: 02/06/2024
// Description: This file defines runs tests for the 
// DFA created in the DFA_2.h file
// =========================================================

#include <iostream>
#include "DFA_2.h"

using namespace std;


/**
 * main function to run the program
 * 
 * @param n/A
 * @return n/A
*/
int main () {

    // Variable to count number of passed test cases
    int testCount = 0;

    // Test 1
    if (acceptsWord("%ar") == true) {
        cout << "Test 1 passed\n\n";
        testCount++;
    } else {
        cout << "Test 1 failed\n\n";
    }

    // Test 2
    if (acceptsWord("echor") == true) {
        cout << "Test 2 passed\n\n";
        testCount++;
    } else {
        cout << "Test 2 failed\n\n";
    }

    // Test 3
    if (acceptsWord("echuir") == true) {
        cout << "Test 3 passed\n\n";
        testCount++;
    } else {
        cout << "Test 3 failed\n\n";
    }

    // Test 4
    if (acceptsWord("edain") == true) {
        cout << "Test 4 passed\n\n";
        testCount++;
    } else {
        cout << "Test 4 failed\n\n";
    }

    // Test 5
    if (acceptsWord("edhel") == true) {
        cout << "Test 5 passed\n\n";
        testCount++;
    } else {
        cout << "Test 5 failed\n\n";
    }

    // Test 6
    if (acceptsWord("ear") == false) {
        cout << "Test 6 passed\n\n";
        testCount++;
    } else {
        cout << "Test 6 failed\n\n";
    }

    // Test 7
    if (acceptsWord("%chuir") == false) {
        cout << "Test 7 passed\n\n";
        testCount++;
    } else {
        cout << "Test 7 failed\n\n";
    }

    // Test 8
    if (acceptsWord("%chor") == false) {
        cout << "Test 8 passed\n\n";
        testCount++;
    } else {
        cout << "Test 8 failed\n\n";
    }

    // Test 9
    if (acceptsWord("%dain") == false) {
        cout << "Test 9 passed\n\n";
        testCount++;
    } else {
        cout << "Test 9 failed\n\n";
    }

    // Test 10
    if (acceptsWord("%dhel") == false) {
        cout << "Test 10 passed\n\n";
        testCount++;
    } else {
        cout << "Test 10 failed\n\n";
    }

    cout << "passed " << testCount << " out of 10 tests.";

    return 0;
}