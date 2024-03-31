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

## Investigation and References
The word _elvish_ refers to those that are a part of the Elves. The most common tongue spoken amongst the elves during the third age was **Sindarin**. All of this belong to the fantasy world of _'The Lord of the Rings'_. A famous fantasy book series written by John Ronald Reuel Tolkein (J.R.R Tolkien). 

His work was always really inspired by lanauge, and his stories drew inspiration from them. Experimenting with the creation languages during his youth lead him to inlcude them in his _magnum opus_. This lead to a whole area of study, and several academics around the world have dedicated their lives to understanding the depth behind this fictional languages. 

1. n/a. (Mar 2nd, 2023). _Elvish_. Tolkien Getway. https://tolkiengateway.net/wiki/Elvish


