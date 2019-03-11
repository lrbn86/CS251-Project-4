#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

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
		while (i < N) {
			getline(inputfile, word);
			rh.insertWord(word);
			i++;
		}
		rh.performRhymeOrderOperation();
		// Output to file
		for (auto w : rh.getWords()) {
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
		while (i < N) {
			getline(inputfile, word);
			rh.insertWord(word);
			i++;
		}
		// Perform rhyme order operation
		rh.performRhymeOrderOperation();
		// Iterate through the rhyme ordered vector
		// Use hashtable/hashmap to identify the suffixes that has at least k words.
		// In the hashtable/hashmap, keys are the suffixes and the values are lists of words
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
		// TODO: MODIFIED IO
		// if (inputfile.fail()) {
		// 	cout << "FILE DOES NOT EXIST" << endl;
		// }
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
