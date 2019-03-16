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
			rh.insertWord(word);
			i++;
		}
		// Iterate through the word list
		// Use hashtable/hashmap to identify the suffixes that has at least k words.
		// In the hashtable/hashmap, keys are the suffixes and the values are lists of words
		map<string, vector<string>> table;

		// Get the suffixes
		for (int i = 0; i < rh.getWords().size(); i++)
		{
			string word = rh.getWords()[i];
			vector<string> suffixesArray = rh.getSuffixes(word);
			for (const auto suffix : suffixesArray)
			{
				// Insert suffixes into map, but the word list will be initially empty
				table.insert(std::pair<string, vector<string>>(suffix, {}));
			}
		}

		// Iterate through the rhyme order list
		// If the word in the rhyme order list contains the suffix (ending)
		// then insert the word into the map with its respective suffix
		rh.performRhymeOrderOperation();
		for (int i = 0; i < rh.getWords().size(); i++)
		{
			string word = rh.getWords()[i];
			// Iterate through the map and determine whether word ends with the suffix
			for (const auto pair : table)
			{
				string suffix = pair.first;
				if (rh.hasSuffix(word, suffix))
				{
					// Insert word into the table
					table[suffix].push_back(word);
				}
			}
		}

		// NOTE: part1input2suffix6-7-8.txt has very large inputs
		// It should take about a minute to complete
		// Don't think we can handle with the current algorithm that we have.
		// TODO: Check for redundant iterations...combine steps...

		// Print out map
		for (const auto pair : table)
		{
			string suffix = pair.first;
			vector<string> words = pair.second;
			bool first = true;
			if (words.size() >= K)
			{
				// The suffixes should be printed in increasing order, forunately map already sorts it.
				outputfile << suffix << " -> ";
				outputfile << "[";
				// The lists of word for each suffix will also be in rhyme order
				rh.qsort(words, 0, words.size() - 1);
				for (auto word : words)
				{
					if (first)
					{
						first = false;
					}
					else
					{
						outputfile << ", ";
					}
					outputfile << word;
				}
				outputfile << "]";
				outputfile << endl;
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
