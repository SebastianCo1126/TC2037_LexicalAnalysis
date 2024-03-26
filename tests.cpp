#include <iostream>
#include "DFA_2.h"

using namespace std;

int main () {

    
    int testCount = 0;

    // Test 1
    if (accepts_word("%ar") == true) {
        cout << "Test 1 passed\n\n";
        testCount++;
    } else {
        cout << "Test 1 failed\n\n";
    }

    // Test 2
    if (accepts_word("echor") == true) {
        cout << "Test 2 passed\n\n";
        testCount++;
    } else {
        cout << "Test 2 failed\n\n";
    }

    // Test 3
    if (accepts_word("echuir") == true) {
        cout << "Test 3 passed\n\n";
        testCount++;
    } else {
        cout << "Test 3 failed\n\n";
    }

    // Test 4
    if (accepts_word("edain") == true) {
        cout << "Test 4 passed\n\n";
        testCount++;
    } else {
        cout << "Test 4 failed\n\n";
    }

    // Test 5
    if (accepts_word("edhel") == true) {
        cout << "Test 5 passed\n\n";
        testCount++;
    } else {
        cout << "Test 5 failed\n\n";
    }

    // Test 6
    if (accepts_word("ear") == false) {
        cout << "Test 6 passed\n\n";
        testCount++;
    } else {
        cout << "Test 6 failed\n\n";
    }

    // Test 7
    if (accepts_word("%chuir") == false) {
        cout << "Test 7 passed\n\n";
        testCount++;
    } else {
        cout << "Test 7 failed\n\n";
    }

    // Test 8
    if (accepts_word("%chor") == false) {
        cout << "Test 8 passed\n\n";
        testCount++;
    } else {
        cout << "Test 8 failed\n\n";
    }

    // Test 9
    if (accepts_word("%dain") == false) {
        cout << "Test 9 passed\n\n";
        testCount++;
    } else {
        cout << "Test 9 failed\n\n";
    }

    // Test 10
    if (accepts_word("%dhel") == false) {
        cout << "Test 10 passed\n\n";
        testCount++;
    } else {
        cout << "Test 10 failed\n\n";
    }

    cout << "passed " << testCount << " out of 10 tests.";

    return 0;
}