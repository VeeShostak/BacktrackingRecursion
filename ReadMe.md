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


##Program Tasks:

If there is just one argument, then after the program has read and stored the dictionary, it should repeatedly
prompt the user to enter a string of at least 2 and at most 32 characters. If the user enters a word that is
not of length between 2 and 32 characters, the program should display a suitable message to ask the user to
try again. 


Once the user has entered a word of the correct length, it displays all words that are substrings or
permutations of substrings of the user’s word that are also in the dictionary. If the user enters any uppercase
letters, the program should convert them to lowercase before it tries to form words. It should display these
words in sorted order using the ASCII collating sequence. If there are duplicates they should not be printed.


When the program has finished displaying the words, it asks the user whether she wants to continue or to
quit. If the user chooses to quit, the program terminates.


If there is a second argument, the program should not do anything interactively. Instead it should read the
words from the second file one at a time and compute the valid substrings and permutations in the same way
as is described in the preceding paragraph. For each source word, it should append the list of such words to
an output file whose name is the source word file with an extension “.out”.

