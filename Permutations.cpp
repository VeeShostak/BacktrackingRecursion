/*
 Title			: Permutations.h
 Author			: Vlad Shostak
 Created On		: October 22, 2016
 Description	: This is the implementation for
 				  a concrete class derived from the Dictionary class which is a 
 			      pure abstract class with two pure abstract functions that are 
 			      implmented in this Permutations class
 Modifications	:
	
	Notes		: 
*/

#include <string>
#include <vector>
#include <fstream>
#include <iostream>


#include "Permutations.h"
using namespace std;


Permutations::Permutations(ifstream &file)
{
	string dictWord = "";

	while (file >> dictWord)
	{
		dictionary.push_back(dictWord);
	}

	return;
}


// ===
int Permutations::search(string keyword, size_t prefix_length )
{


	int index = -1;
	if (prefix_length > 0)
	{
		
		string keyWordPrefix = "";
		for (int i = 0; i < prefix_length; i++)
		{
			keyWordPrefix += keyword[i];
		}

		bool match = false;
		for (int i = 0; i < dictionary.size(); i++)
		{
			if (dictionary[i].length() - 1 >= keyWordPrefix.length()) // if false go to next word
			{
				// are first prefix_lenght-1 words of keyword a prefix of first prefix_length-1 words of each word in dictionary
				string tempPrefix = "";
				for (int j = 0; j < keyWordPrefix.length(); j++)
				{
					tempPrefix += dictionary[i].at(j);
				}

				if (keyWordPrefix == tempPrefix)
				{
					// match = true not needed
					return i; // return index
				}
			} 
		}
		if (!match)
		{
			return -1;
		}

	}

	bool match = false;
	if (prefix_length == 0)
	{
		for (int i = 0; i < dictionary.size(); i++)
		{
			if (keyword == dictionary[i])
			{
				// match = true not needed
				return i;
			}
		}

		if (!match)
		{
			return -1;
		}

	}

	return index;
}


// ===
void Permutations::populateDictionary(ifstream & file)
{
	string dictWord = "";

	while (file >> dictWord)
	{
		dictionary.push_back(dictWord);
	}

	return;
}

// ===
bool Permutations::sourceWordPermutationsAndSubstrings(string w, string z)
{
	bool prefixFound = false;
	for (int k = 0; k < z.length() && !prefixFound; k++)
	{
		string newPrefix = z.substr(k,1);
		w += newPrefix;

		string first = z.substr(0, k);
		string second = z.substr(k + 1);
		z = first + second;	

		// === 1st check if w is in dictonary
		for (int i = 0; i < dictionary.size(); i++)
		{
			if (dictionary[i] == w)
			{
				bool repeat = false; // make sure we are not repeating
				for (int check = 0; check < resultsFromSourceWord.size(); check++)
				{
					if (resultsFromSourceWord[check] == w)
					{
						repeat = true;
					}
				}
				if (!repeat)
				{
					resultsFromSourceWord.push_back(dictionary[i]);
				}
			}
		}
		// === 2nd possibility, at least one word in dict is a prefix
		bool wordMatchedWithPrefix = false;
		for (int i = 0; i < dictionary.size() && !wordMatchedWithPrefix; i++) // && !prefixFound
		{
			if (dictionary[i].length() - 1 >= w.length()) // if false go to next word
			{
				// are first k words of w a prefix of first k words of each word in dictionary
				string tempPrefix = "";
				for (int j = 0; j < w.length(); j++)
				{
					tempPrefix += dictionary[i].at(j);
				}

				if (w == tempPrefix)
				{
					wordMatchedWithPrefix = true;
					prefixFound = sourceWordPermutationsAndSubstrings(w, z);
				}
			} 

		}
		// === tried all prefixes (backtracked through all)
		// return false to keep on backtracking so that each recursive call collapses
		if (!prefixFound && (k == z.length() ))
		{
			return false;
		}

		// === BACKTRACK if prefix not found or if tried all prefixes
		if (!prefixFound) 
		{
			// subtract last cahr of w
			// and add back to z
			string temp = "";
			for (int i = 0; i < w.length() - 1; i++)
			{
				temp += w[i];

			}
			w = temp;
			z = newPrefix + z;
			// debug: cout << "\nbacktracking removed last char w: " << w <<  "  z: " << z <<endl;
		}	

	} // end for loop

	return prefixFound;
}


// ===
void Permutations::displayWords()
{
	for (int i = 0; i < resultsFromSourceWord.size(); i++)
	{
		
		cout << resultsFromSourceWord[i] << endl;
	}

	return;
}


// ===
void Permutations::displayWordsInFile(string sourceWord, ofstream &file)
{
	file << sourceWord << "\n";
	for (int i = 0; i < resultsFromSourceWord.size(); i++)
	{
		file << resultsFromSourceWord[i] << "\n";
	}
	file << "\n";

	return;
}


// ===
void Permutations::insertionSort()
{
	int j, i;
	int numLength = resultsFromSourceWord.size();
	string key;

	for(j = 1; j < numLength; j++)   
    {
        key = resultsFromSourceWord[j];

        for(i = j - 1; (i >= 0) && (resultsFromSourceWord[i] > key); i--)
        {
            resultsFromSourceWord[i+1] = resultsFromSourceWord[i];
        }
        // Put key into its proper location
        resultsFromSourceWord[i+1] = key;    
       
     }

	return;
}








