/*
 Title			: Permutations.h
 Author			: Vlad Shostak
 Created On		: October 22, 2016
 Description	: This is the specification(interface) for
 				  a concrete class derived from the Dictionary class which is a 
 			      pure abstract class with two pure abstract functions that are 
 			      implmented in this Permutations class
 Modifications	:
	
	Notes		: 
*/




#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

#include <string>
#include <vector>
#include <fstream>

#include "Dictionary.h"
using namespace std;


class Permutations : public Dictionary
{
public:
	// inline -default constructor
	Permutations() { }

	// constructor populates dicionary from  input file
	Permutations(ifstream &file);

	/*	search()
		@note: this is the implementation of the pure abstract function 
		from Dictionary.h abstract class
		@pre 	keyword != NULL and prefix_length >= 0
		@param 	string keyword [in] key to search for in dictionary
		@param 	size_t prefix_length [in] number of initial chars to match
		@return int
				If prefix_length > 0, then if there is a word W in the dictionary
				such that:
				W[0...prefix_length-1] is identical to keyword[0...prefix_length-1]
				then it returns its index in the dictionary, else -1.
				If prefix_length ==0, this returns and index if and only if the
				keyword matches a word in the list exactly, and -1 otherwise.
	*/
	int search(string keyword, size_t prefix_length);
		
	/*	populateDictionary()
		@note: this is the implementation of the pure abstract function 
		from Dictionary.h abstract class
		fills dictionary object with words from the given input
		file stream
		@pre 	file stream must be opened for reading && must have one word
				per line and be in sorted order
		@post 	dictionary oject is filled with words from file in sorted order
		@param 	ifstream & file [inout] stream to read
	*/
	void populateDictionary(ifstream &file);
	
	/*	sourceWordPermutationsAndSubstrings(string w, string z);
		find all permutations and substrings of source word using backtracking
		pushback to private vector resultsFromSourceWord
		@pre 	file stream must be opened for reading && must have one word
				per line and be in sorted order
		@post 	resultsFromSourceWord filled with all permutations and substrings of source word
		@param 	string w [in] empty prefix, 
		@para   string z [in] is the source word (suffix) 
	*/
	bool sourceWordPermutationsAndSubstrings(string w, string z);
	
	/*	displayWords()
		Displays words from resultsFromSourceWord private vector using cout stream
	*/
	void displayWords();

	/*	insertionSort()
		sorts in ascii collating sequence the resultsFromSourceWord privae vector
		using insertion sort
		@post resultsFromSourceWord privae vector sorted in ascii collating sequence
	*/
	void insertionSort();

	/*	displayWordsInFile(string sourceWord, ofstream &file);
		outputs words from resultsFromSourceWord private vector into
		an opened ofstream file, with the source word on top, all one per line.
		@pre file open for output
		@post output file is outputed the source word on top and the words from 
		 resultsFromSourceWord private vector, where all words are one word per line
	*/
	void displayWordsInFile(string sourceWord, ofstream &file);

	// inline - clears resultsFromSourceWord private vector, size becomes 0
	void clearResultsContainer()
	{	resultsFromSourceWord.clear();	}


private:
	// stores the words in the dictionary
	vector<string> dictionary;
	// stores the permutations and substrings
	vector<string> resultsFromSourceWord; 

};
#endif
