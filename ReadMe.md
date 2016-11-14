#BacktrackingRecursion

##Program Description:

This program uses recursion to solve  the given problem.
The program is run from the command line and is given at least one argument, which is the name of a file 
containing a list of words. We will call this file the dictionary. If there is just one argument on the 
command line, the program enters an interactive loop in which it repeatedly prompts the user to enter a 
string of characters. The string may be any sequence of characters that can be typed on the keyboard. 
Henceforth we call this string the source word. 

**The program implements the backtracking paradigm using recursion**

**The objective of the program, having been given a source word, is to find all words that are rearrangements of
one or more of the characters in the source word, that are also in the dictionary**


For example, if the source word is
**carat**
and the dictionary contains the words: *at, arc, art, car, cart, cat, rat, and tar*, then the program would
display each of these words, one per line, in sorted order:
```
arc
art
at
car
cart
cat
rat
tar
```
The words it displays are words in the dictionary that are either substrings of the source word or words
that are permutations of the substrings. We will call these words solutions. A word is a solution if it is
a substring of the source word or a permutation of a substring. The program must not display duplicate
solutions.
The optional second command-line argument is the pathname of a file that contains a list of words to use as
source words, one per line. If it is present, the program does not enter the above-described interactive loop.
Instead it reads from this file and processes the words in it one by one.