#ifndef Rhymer_hpp
#define Rhymer_hpp

#include <iostream>
#include <string>
#include <vector>
#include <list>
// #include <algorithm>
using namespace std;
/*
	Note to grading instructor:
		Most of the test cases have different line endings such as "\r\n" or "\n" or even just "\r" (refer to part2input1case2.txt for "postorder")
		The current program will fail some test cases if the lines do not have consistent ending.
		For now, the program will try to match the given output files exactly.
*/
template <typename S>
class Rhymer
{
public:
	Rhymer() {}

	// Quicksort algorithm that sorts in place
	void qsort(vector<S> &words, int left, int right)
	{	
		if (left < right)
		{
			int index = partition(words, left, right);
			qsort(words, left, index-1);
			qsort(words, index, right);
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

	void clearWords() {
		this->words.clear();
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
	int partition(vector<S> &words, int left, int right)
	{
		S pivot = words[right];
		int high = right;

		while (left < high)
		{
			while (left < high && words[left] < pivot)
			{
				left++;
			}
			while (left < high && words[high] >= pivot)
			{
				high--;
			}
			std::swap(words[left],words[high]);
		}
		std::swap(words[left],words[right]);
		return left;
	}
};

#endif // Rhymer_hpp