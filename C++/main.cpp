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

	if (operationType == "1")
	{
		Rhymer rh;
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
		// Reverse each word
		rh.reverseWords();
		// Perform quicksort
		rh.qsort();
		rh.reverseWords();
		for (auto w : rh.getWords()) {
			outputfile << w << endl;
		}
		// Reverse each word again to their original state
		// The current words vector will be the correct rhyme order
	}
	else if (operationType == "2")
	{
		outputfile << "Doing Suffix Sharing Operation" << endl;
		// Perform rhyme order operation
		// Iterate through the rhyme ordered vector and find suffixes that has minimum k words
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
