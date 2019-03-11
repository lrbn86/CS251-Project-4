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
	void qsort(list<S> seq)
	{
		// TODO: Need to think about whether to use a vector or a list...
		// TODO: This is more tougher than I thought.
		vector<S> sequence = ;

		if (sequence.size() <= 1)
		{ // List is already sorted
			return;
		}

		// Choose pivot to be the last element
		S pivot = sequence.back();

		list<S> e_list; // elements in this list are equal to the pivot
		list<S> l_list; // elements in this list are less than the pivot
		list<S> g_list; // elements in this list are greater than the pivot

		// Dividing the list into the three lists
		while (!sequence.empty())
		{
			if (sequence.back() < pivot)
			{
				l_list.push_back(sequence.back());
				sequence.pop_back();
			}
			else if (sequence.back() == pivot)
			{
				e_list.push_back(sequence.back());
				sequence.pop_back();
			}
			else
			{
				g_list.push_back(sequence.back());
				sequence.pop_back();
			}
		}

		// Apply recursion with the three lists
		qsort(l_list);
		qsort(g_list);

		while (!l_list.empty()) 
		{
			sequence.push_back(l_list.front());
			l_list.pop_front();
		}

		while (!e_list.empty())
		{
			sequence.push_back(e_list.front());
			e_list.pop_front();
		}

		while (!g_list.empty())
		{
			sequence.push_back(g_list.front());
			g_list.pop_front();
		}

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
		qsort(this->words);
		reverseWords();
	}

private:
	vector<S> words;
};

#endif // Rhymer_hpp
