# TC2037_LexicalAnalysis

## Description
This repository makes a lexical analysis on a language composed of five elvish words from the fantasy series 'The Lord of the Rings'. The language is composed of the following letters Σ = {ë, a, r, c, h, o, u, i, d, n, e, l}, looking to only accept the words _ëar, echor, echuir, edain, edhel._

I built a Non-Deterministic Finite Automata (DFA) to implement my lexical analysis. My solution was modeled with 12 states represented by the letter q.
- q0, q1, q2... q11

## Model of the solution
I chose to do a DFA since a DFA only needs one go to determine whether a string is accepted or not. Furthermore, in a DFA, for each state and each input, there is exactly one transition to another state. This means that there is no ambiguity in how an input string is processed, making it easier to identify specific words. And DFAs are simpler to implement and understand than Non-Deterministic Finite Automata (NFA). Each state in a DFA has a clear and unique transition for each possible input

A DFA appeared to be a good solution, since it adapts to the problem quite well. In a DFA we have exactly one transition from one state to another.
This makes this problem quite logical, as there are no alternate ways. Everything is predefined as simple possible pathways to take hence no ambiguity. 
An input word in the form of a string will simply be processed from left to right, character by character, determining whether or not a pathway for said
word exists. For this very specific, and bounded problem the DFA fits perfectly for this problem, in contrast to its brother the NFA (Non-Deterministic Finite
Automata). Even though very efficient, for this simple problem it would have needed a lot more work to be done. 

Now I present the DFA I created. <br>
![](/images/automata_DFA.jpg)

The presented automata is also equivalent to the following regular expression, in which the special character
'ë' was substituted with the character '%' for simplicity:

- RE: ^%ar$|^ech(or|uir)$|^ed(ain|hel)$

This Regex was tested using the standard Regex library in c++. The following is the code used to test it, but the 
implementation chosen was the DFA. 

    ```
        #include <iostream>
        #include <string>
        #include <regex>
        
        using namespace std;
        
        
        /**
         * main function to run the program
         * 
         * @param n/A
         * @return n/A
        */
        int main() {
            // REGEX expression that substitutes 'ë' with '%'
            std::regex pattern(R"(^%ar$|^ech(or|uir)$|^ed(ain|hel)$)");
        
            // Test strings
            string test1 = "%ar";
            string test2 = "echor";
            string test3 = "echuir";
            string test4 = "edain";
            string test5 = "edhel";
            string test6 = "invalid";
        
            // Check if the test strings match the pattern
            auto testString = [&pattern](const std::string& str) {
                if (std::regex_match(str, pattern)) {
                    cout << str << " matches the pattern." << endl;
                } else {
                    cout << str << " does not match the pattern." << endl;
                }
            };
        
            testString(test1);
            testString(test2);
            testString(test3);
            testString(test4);
            testString(test5);
            testString(test6);
        
            return 0;
        }

    ```

## Implementation 
For my implementation, I decided to use C++. The file DFA_2.cpp contains the code that models 
after the DFA presented in the 'Model of the Solution' section. The model can be found as the 
image called: "automata_DFA.jpg".

_note:_ in this implementation, the words are implemented to be case sensitive. Only lowercase words are accepted. 
And for the special character 'ë' the symbol '%' was used in its place. So if you want to write the word 'ëar' that
is within the language, you must write it as '%ar'. 

My final DFA in constructed in the file "DFA_2.h", and the tests are located in the "tests.cpp" file. To use the automate
you'll need to have a C++ compiler. As an example, I use MinGW-w64 compiler. Both of the aforementioned files **need** to
be located in the same directory. Using the command prompt, one should navigate to the directory in which the files are 
located, and compile like so: 

    g++ ["tests.cpp"] -o ["_any_file_name_you_want.exe_"]

This shoul generate a .exe file which you can the run to see the results in the console. 

The "tests.cpp" file was written to run 10 different tests, and will output: "Test x passed" if the test was successful, 
or "Test x failed" if the test was not successful.

Some examples of inputs and outputs are:

- echor -> Test 2 passed (true)
- %chuir -> Test 7 passed (false)
- %dhel -> Test 10 passed (false)
- edain -> Test 4 passed (true)

## Tests 
The file _tests.cpp_ contais all the cases tested for the DFA. Including tests for all the words in the language, and for slight variations of the 
words, which are 'more likely' to make the model fail, as oppsoed to very different words, with different letters. 

## Analysis
The **time complexity** of the model is O(n) as it is only defined by the length of the string, which is parsed once. 

    for i < n // n being the lenght of the string 
        if i in n 
            i++ // parsing continues 
        else 
            break;
My approach was using a switch case, that gets input from the characters in the word as the value of the node. Each node contains a possible next 
in accordance to the modeled automata. If there are no possible next steps, the case breaks and returns a message saying that the word IS NOT in the 
language. 

### Efficiency 

This can be demosntrated to be an optimal solution due to some factor that I've identified. 

**Minimal states and transition complexity**
- The design minimizes the number of states and transitions required, avoiding unnecessary complexity and potential points of failure. The model was generated to use the least number of nodes possible for the parsing to function accordinf to the language. 

**Single Pass Processing**
- By processing each character in a single pass and using a direct acceptance check, my DFA ensures a fast and efficient determination of whether a word is accepted or not.

**Default Reset Mechanism**
- The default transition to q0 on invalid input provides a quick way to reject strings without further processing, enhancing efficiency.

## Detailed overview

My DFA was created to accept only the following words: ëar, echor, echui, edain, and edhel. (though the special character 'ë' was substituted by the character '%' for the program to recognize the character and avoid any problems). The DFA operates by transitioning through a series of states based (q) on the input characters of the word being parsed. The final state determines if the word is accepted or not. 

**Structure and State Transitions**

The DFA is defined by a set of states, transitions, an initial state, and a set of accepting states. In my C++ code, it looks as follows: 

- _States_: The states (q0 to q10 and qf) represent different stages of parsing the input, declared in an enumeration. 
- _Initial State_: q0, the first state where the parsing begins. 
- _Accepting State_: qf, a state reached if the word is accepted.
- _Transitions_: Defined by the function transition(State state, char input), which specifies how the DFA moves from one state to another based on the input character.

**Theoretical and Mathematical Backing**

Deterministic Finite Automata (DFA) Theory

A DFA is a theoretical model of computation used to represent and recognize regular languages. It consists of:

    A finite set of states (Q)
    An input alphabet that contains the accepted symbols (Σ)
    A transition function (δ: Q × Σ → Q)
    A start state, belonging to Q (q0 ∈ Q)
    A set of all accepting states (F)

Reference: Dylan. (Sept 10, 2023). _Finite Automata And Deterministic Finite Automata_. Medium.

In my DFA:

    Q = {q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, qf}
    Σ = {'%', 'a', 'e', 'c', 'h', 'o', 'u', 'i', 'd', 'r', 'l', 'n'}
    δ is defined in the transition function
    q0 is the initial state
    F = {qf}

This DFA minimizes state usage by reusing states where possible and avoiding redundancy. For example, state q1 branches into different paths for words starting with 'e', while state q10 handles the unique '%' start.
Each input character is processed only once, resulting in a time complexity of O(n), where n is the length of the input string. This ensures efficient performance in this small set of valid words. 


## Investigation and References
The word _elvish_ refers to those that are a part of the Elves. The most common tongue spoken amongst the elves during the third age was **Sindarin**. All of this belong to the fantasy world of _'The Lord of the Rings'_. A famous fantasy book series written by John Ronald Reuel Tolkein (J.R.R Tolkien). 

His work was always really inspired by lanauge, and his stories drew inspiration from them. Experimenting with the creation languages during his youth lead him to inlcude them in his _magnum opus_. This lead to a whole area of study, and several academics around the world have dedicated their lives to understanding the depth behind this fictional languages. 

1. n/a. (Mar 2nd, 2023). _Elvish_. Tolkien Getway. https://tolkiengateway.net/wiki/Elvish
2. Dylan. (Sept 10, 2023). _Finite Automata And Deterministic Finite Automata_. Medium.


