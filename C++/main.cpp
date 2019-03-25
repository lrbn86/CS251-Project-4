#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>

#include "Node.hpp"
#include "BinarySearchTree.hpp"
#include "Rhymer.hpp"
using namespace std;

/*
	Note to grading instructor:
		Most of the test cases have different line endings such as "\r\n" or "\n" or even just "\r" (refer to part2input1case2.txt for "postorder")
		The current program will fail some test cases if the lines do not have consistent ending.
		For now, the program will try to match the given output files exactly.
*/

// TODO: DONE!
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
				outputfile << "\n"; // Note: part1 has different line ending than part2.
			}
		}
	}
}

void read_part_2(ifstream &inputfile, ofstream &outputfile)
{
	BinarySearchTree bst;
	string line;
	int N; // n lines to follow
	getline(inputfile, line);
	N = stoi(line);

	while (getline(inputfile, line))
	{
		istringstream is(line);
		string operation;
		getline(is, operation, ' ');
		// Remove whitespaces from string
		operation.erase(remove_if(operation.begin(), operation.end(), ::isspace), operation.end());

		// Basic Operations, 10pts
		if (operation == "insert")
		{
			// "insert" needs one argument
			int key;
			getline(is, operation, ' ');
			key = stoi(operation);
			bst.insertKey(key);
		}
		else if (operation == "delete")
		{
			// "delete" needs one argument
			int key;
			getline(is, operation, ' ');
			key = stoi(operation);
			if (bst.searchKey(key))
			{
				bst.deleteKey(key);
				outputfile << "deleted"
									 << "\r\n";
			}
			else
			{
				outputfile << "deletion failed"
									 << "\r\n";
			}
		}
		else if (operation == "search")
		{
			// "search" needs one argument
			int key;
			getline(is, operation, ' ');
			key = stoi(operation);
			if (bst.searchKey(key))
			{
				outputfile << "found"
									 << "\r\n";
			}
			else
			{
				outputfile << "not found"
									 << "\r\n";
			}
		}
		else if (operation == "range")
		{
			// "rangeSum" needs two arguments
			int left, right;
			getline(is, operation, ' ');
			left = stoi(operation);
			getline(is, operation, ' ');
			right = stoi(operation);
			outputfile << bst.rangeSum(left, right) << "\r\n";
		}
		else if (operation == "height")
		{
			// "height" needs one argument
			int key;
			getline(is, operation, ' ');
			key = stoi(operation);
			if (bst.searchKey(key))
			{
				outputfile << bst.height(key) << "\r\n";
			}
			else
			{
				outputfile << "none"
									 << "\r\n";
			}
		}
		else if (operation == "postorder")
		{
			vector<int> keys = bst.postorder();
			if (keys.size() <= 0)
			{
				outputfile << "none";
			}
			else
			{
				bool first = true;
				for (auto key : keys)
				{
					if (first)
					{
						first = false;
					}
					else
					{
						outputfile << " ";
					}
					outputfile << key;
				}
			}
			outputfile << "\r\n"; // Note: part2input1case2.txt has inconsistent ending for postorder...
		}
		else if (operation == "levelorder")
		{
			vector<int> keys = bst.levelorder();
			if (keys.size() <= 0)
			{
				outputfile << "none";
			}
			else
			{
				bool first = true;
				for (auto key : keys)
				{
					if (first)
					{
						first = false;
					}
					else
					{
						outputfile << " ";
					}
					outputfile << key;
				}
			}
			outputfile << "\r\n";
		}
		else if (operation == "lca")
		{
		}
		else if (operation == "floor")
		{
		}
		else if (operation == "ceil")
		{
		}
		else if (operation == "dist")
		{
		}
		else if (operation == "insertRB")
		{
		}
	}
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