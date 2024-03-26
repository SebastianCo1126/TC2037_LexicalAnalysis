# TC2037_LexicalAnalysis

## Description
This repository makes a lexical analysis on a langauge composed of five elvish words from the fantasy series 'The Lord of the Rings'. The language is composed of the following five words Σ = {ëar, echor echuir, edain, edhel}. 

I built a Non-Deterministic Finite Automata (DFA) to implement my lexical analysis. My solution was modeled with 12 states represented by the letter q.
- q0, q1, q2... q11

## Model of the solution
Now I present the DFA I created. <br>
![](/images/automata_DFA.jpg)

The presented automata is also equivalent to the following regular expression:

- ^Ë(ar) | ^Ech(or | uir) | ^Ed(ain | hel)

## Implementation 
For my implementation, I decided to use C++. The file DFA_2.cpp contains the code that models 
after the DFA presented in the 'Model of the Solution' section. 

_note:_ in this implementation, the words are implemented to be case sensitive. Only lowercase words are accepted. 
And for the special character 'ë' the symbol '%' was used in its place. So if you want to write the word 'ëar' that
is within the language, you must write it as '%ar'. 

Some examples of inputs and outputs are:

- echor -> Word IN the language. 
- %chuir -> Word NOT IN the language. 
- hola como estas -> Word NOT IN the language. 
- edain -> Word IN the language. 

## Tests 
    
## Analysis

