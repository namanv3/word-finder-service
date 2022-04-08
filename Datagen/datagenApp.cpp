#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define WORDS_FILENAME "Datagen/words.txt"

using namespace std;

vector<string> generateWordsVector() {
	ifstream wordsFileStream(WORDS_FILENAME);
	vector<string> words;
	if (wordsFileStream.is_open()) {
		string currentWord;
		while (getline(wordsFileStream, currentWord)) {
			words.push_back(currentWord);
		}
		wordsFileStream.close();
	}
	return words;
}

int main() {
	vector<string> words = generateWordsVector();
	
}