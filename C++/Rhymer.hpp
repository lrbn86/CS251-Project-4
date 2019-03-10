#ifndef Rhymer_hpp
#define Rhymer_hpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Rhymer
{
public:
	
	Rhymer() {}

	// Quicksort algorithm
	void qsort() {
		// TODO: Need to implement quicksort by hand...!!!
		// Use strcmp to compare strings 
		std::sort(this->words.begin(), this->words.end());
	}

	void printRhymeOrder() {

	}

	void insertWord(string word) {
		words.push_back(word);
	}

	vector<string> getWords() {
		return this->words;
	}

	void reverseWords() {
		for (int i = 0; i < this->words.size(); i++) {
			string word = this->words[i];
			reverse(word.begin(), word.end());
			this->words[i] = word;
		}
	}

private:
	vector<string> words;
};

#endif // Rhymer_hpp
