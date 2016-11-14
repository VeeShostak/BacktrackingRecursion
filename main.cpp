
/*
 Title			: main.cpp
 Author			: Vlad Shostak
 Created On		: October 20, 2016
 Description	: main program file includes Permutations.h concrete class
 				  that's derived from Dictionary.h pure abstract class
 Purpose		: program runs according to the specifications in the project description
 Modifications	:
	
	Notes		: includes Permutations.h concrete class
 				  that's derived from Dictionary.h pure abstract class
*/


#include <iostream>
#include <fstream> // files
#include <string>
#include <vector>
#include <ctype.h> // tolower

#include "Permutations.h"

using namespace std;


int main(int argc, const char * argv[])
{

	if(argc == 1) // need at least 1 input file for program
    {
        cerr << "\nError: program " << argv[0] << " requires at least 1 argument - (1 input dictionary file, and(optional) 1 input sourcewords file)\n";
        return 0;
    }

    // open required dict file
    ifstream dictionaryFile;
    dictionaryFile.open(argv[1]); 
    if (dictionaryFile.fail())
    {
        cerr << "Error opening dictionaryFile file\n";
        return 0;
    }

	
    // =================================================
	// if one argument (the dictionary file), 
	// loop asking user for source word
	// =================================================

	if(argc == 2) 
    {
		// store the dictionary in vector from file
    	Permutations myPermutationSet;
    	myPermutationSet.populateDictionary(dictionaryFile);

    	char continueAnswer; // if holds y || Y then loop loops again
     
	    do {
	        // loop prompt user to enter string of at least 2 and at most 32 characters
			// if not display cerr wrong length
	    	string sourceWord = ""; // suffix source word
			string w = ""; // prefix

			bool validLength = false;
			while(!validLength)
			{
				cout << "\n Enter a source word (length: [2-32]):";
				cin >> sourceWord;
				if ( sourceWord.length() < 2 || sourceWord.length() > 32 )
				{
					cerr << "\nInvalid Length: Your Source Word: " << sourceWord << " is less than 2 or greater than 32 characters\n";
				}
				else 
				{
					validLength = true;
				}
			} 

			// if user enters uppercase letters, convert them to lower case first
			string temp = "";
			for (int i = 0; i < sourceWord.length(); i++)
			{
				temp += tolower(sourceWord[i]);
			}
			sourceWord = temp;

			// display these words (sort) in ascii collating sequence

			// find permuations and substrings
			myPermutationSet.sourceWordPermutationsAndSubstrings(w, sourceWord);
			// sort
			myPermutationSet.insertionSort();
			// print
			myPermutationSet.displayWords();
			// clear vector for next iteration
			myPermutationSet.clearResultsContainer();

			// when program has finished displaying words, ask user to continue or quit (terminate program)
			cout << "\nWould you like to continue? (y/n)\n";
			cin >> continueAnswer;

		} while(continueAnswer == 'y' || continueAnswer == 'Y');

		// we left do while loop, so terminate
		dictionaryFile.close();
		return 0;

    } // close if argc == 2


	// =================================================
	// if two aguments (the dictionary file and 
	// source words file), read source words from file
	// and compute permutations and substrings. Place
	// output in argv[2].out file
	// =================================================

	
    if(argc == 3) 
    {

    	// ipen sourceWords file for output
	    ifstream sourceWordsFile;
	    sourceWordsFile.open(argv[2]); 
	    if (sourceWordsFile.fail())
	    {
	        cerr << "Error opening sourceWordsFile file\n";
	    }

	    // open sourceWords.out file for output
	    ofstream displayPermutationsFile;
	    string displayFileName = argv[2];
	    displayFileName += ".out";

	    displayPermutationsFile.open(displayFileName.c_str()); 
	    if (displayPermutationsFile.fail())
	    {
	        cerr << "Error opening displayPermutationsFile file\n";
	    }

	    // store the dictionary in vector from file
    	Permutations myPermutationSet;
    	myPermutationSet.populateDictionary(dictionaryFile);

	    string sourceWord = ""; // suffix source word
		string w = ""; // prefix

		while (sourceWordsFile >> sourceWord)
		{
			// find permuations and substrings
			myPermutationSet.sourceWordPermutationsAndSubstrings(w, sourceWord);
			// sort
			myPermutationSet.insertionSort();
			// print to output file
			myPermutationSet.displayWordsInFile(sourceWord, displayPermutationsFile);
			// clear vector for next iteration
			myPermutationSet.clearResultsContainer();

		}

		sourceWordsFile.close();
		displayPermutationsFile.close();
    } // close if argc == 3

	dictionaryFile.close();
	


	return 0;
}




