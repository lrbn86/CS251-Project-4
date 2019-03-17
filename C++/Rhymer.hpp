#ifndef Rhymer_hpp
#define Rhymer_hpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

template <typename S>
class Rhymer
{
public:
	Rhymer() {}

	// Quicksort algorithm that sorts in place
	void qsort(vector<S> &listOfWords, int a, int b)
	{
		if (a >= b)
		{
			return;
		}
		S pivot = listOfWords[b];
		int l = a;
		int r = b - 1;

		while (l <= r)
		{
			while (l <= r && listOfWords[l] <= pivot)
				l++;
			while (r >= l && listOfWords[r] >= pivot)
				r--;
			if (l < r)
			{
				swapC(listOfWords[l], listOfWords[r]);
			}
		}
		swapC(listOfWords[l], listOfWords[b]);
		qsort(listOfWords, a, l - 1);
		qsort(listOfWords, l + 1, b);
	}

	void insertWord(string word)
	{
		words.push_back(word);
	}

	vector<S> getWords()
	{
		return this->words;
	}

	void reverseWords()
	{
		for (int i = 0; i < this->words.size(); i++)
		{
			string word = this->words[i];
			reverse(word.begin(), word.end());
			this->words[i] = word;
		}
	}

	void performRhymeOrderOperation()
	{
		reverseWords();
		qsort(this->words, 0, this->words.size() - 1);
		reverseWords();
	}

	vector<string> getSuffixes(string word)
	{
		vector<string> ret;
		for (int l = word.length() - 1; l >= 0; l--)
		{
			ret.push_back(word.substr(l, word.length()));
		}
		return ret;
	}

	bool hasSuffix(string word, string suffix)
	{
		if (word.length() >= suffix.length())
		{
			return (0 == word.compare(word.length() - suffix.length(), suffix.length(), suffix));
		}
		return false;
	}

private:
	vector<S> words;
	template <class T>
	void swapC(T &a, T &b)
	{
		T c(a);
		a = b;
		b = c;
	}
};

#endif // Rhymer_hpp