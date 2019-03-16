#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>

#include "Node.hpp"
#include "BinarySearchTree.hpp"
#include "Rhymer.hpp"
using namespace std;

void read_part_1(ifstream &inputfile, ofstream &outputfile)
{
	string line;
	string operationType;
	getline(inputfile, operationType);

	Rhymer<string> rh; // Rhymer is implemented with generics template

	if (operationType == "1")
	{
		int N;
		getline(inputfile, line);
		N = stoi(line);
		int i = 0;
		string word;
		// Read in words
		while (i < N)
		{
			getline(inputfile, word);
			rh.insertWord(word);
			i++;
		}
		rh.performRhymeOrderOperation();
		// Output to file
		for (auto w : rh.getWords())
		{
			outputfile << w << endl;
		}
	}
	else if (operationType == "2")
	{
		map<string, vector<string>> table;
		int K = 0; // K is the minimum number of words that ends with the suffixes that we must identify.
		getline(inputfile, line);
		K = stoi(line);
		int N;
		getline(inputfile, line);
		N = stoi(line);
		int i = 0;
		string word;
		while (i < N)
		{
			getline(inputfile, word);
			// Remove whitespaces from string
			word.erase(remove_if(word.begin(), word.end(), ::isspace), word.end());
			// Get the suffixes of the word
			vector<string> suffixesArray = rh.getSuffixes(word);
			for (auto suffix : suffixesArray)
			{
				// Insert suffix into table
				// The wordList will have the word itself be the first element
				table[suffix].push_back(word);
			}
			i++;
		}

		// Print out map
		// TODO: Code below produces some sort of segfault.. Hmm
		for (const auto pair : table)
		{
			string suffix = pair.first;
			vector<string> words = pair.second;
			bool first = true;
			if (words.size() >= K)
			{
				// The suffixes should be printed in increasing order, forunately map already sorts it.
				// outputfile << suffix << " -> ";
				// outputfile << "[";
				// The lists of word for each suffix will also be in rhyme order

				// TODO: Culprit found. The qsort is accessing/writing restricted memory and thus causing a segfault. Check qsort implementation.
				rh.qsort(words, 0, words.size() - 1);
				// for (auto word : words)
				// {
				// 	if (first)
				// 	{
				// 		first = false;
				// 	}
				// 	else
				// 	{
				// 		// outputfile << ", ";
				// 	}
				// 	// outputfile << word;
				// 	// cout << word << endl;
				// }
				// outputfile << "]";
				// outputfile << endl;
			}
		}
	}
}

void read_part_2(ifstream &inputfile, ofstream &outputfile)
{
	//handle input, output from file
	// Binary Search
}

int main(int argc, char *argv[])
{
	//Read in the test case
	ifstream inputfile;
	ofstream outputfile;

	if (argc == 3)
	{
		inputfile.open(argv[1]);
		outputfile.open(argv[2]);
	}
	else
	{
		cout << "Not enough arguments" << endl;
	}

	string str;

	getline(inputfile, str);
	int part;
	stringstream convert(str);
	convert >> part;

	switch (part)
	{
	case 1:
		read_part_1(inputfile, outputfile);
		break;
	case 2:
		read_part_2(inputfile, outputfile);
		break;
	}

	return 0;
}




/*

	Suffix Sharing Algorithm

	1. Use one loop to insert all of the possible suffixes into the table associated with the word itself being the first element in the word list




*/