/*
 Title			: Dictionary.h
 Author			: Vlad Shostak
 Created On		: October 20, 2016
 Description	: The Dictionary class is a pure abstract class with two pure abstract
 				  functions implmented in the Permutations class
 Modifications	:
	
	Notes		: this pure abstract class is implmented in the Permutations class
*/

#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Dictionary
{
public:
		
	/*	populateDictionary()
		fills dictionary object with words from the given input
		file stream
		@pre 	file stream must be opened for reading && must have one word
				per line and be in sorted order
		@post 	dictionary oject is filled with words from file in sorted order
		@param 	ifstream & file [inout] stream to read
	*/
	virtual void populateDictionary(ifstream & file) = 0;

	/*	search()
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

	virtual int search(string keyword,
			size_t prefix_length
			) = 0;
};
#endif
