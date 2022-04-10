#ifndef __WRITE_TO_FILE_INCLUDED__
#define __WRITE_TO_FILE_INCLUDED__

#include <fstream>
#include <string>

#include "trieFileConstants.h"
#include "../Beans/trieNode.h"
#include "../Beans/suggestion.h"

using namespace std;

string convertNodeToString(TrieNode* trieNode);

void generateFileContent(TrieNode* trieNode, string& content);


void writeTrieToFile(TrieNode* trieNode, string filename) {
	string trieContent = "";
	generateFileContent(trieNode, trieContent);
	printf("%s\n", trieContent.c_str());

	ofstream outputFile;
	outputFile.open(filename);
	outputFile << trieContent;
 	outputFile.close();
}

void generateFileContent(TrieNode* trieNode, string& content) {
	if (trieNode == NULL) {
		return;
	}
	content += convertNodeToString(trieNode);
	TrieNode** children = trieNode->getChildren();
	for (int i = 0; i< ALPHABET_SIZE; i++) {
		TrieNode* childNode = children[i];
		generateFileContent(childNode, content);
	}
}

string convertNodeToString(TrieNode* trieNode) {
	string nodeString = "";
	// add letter
	nodeString += trieNode->getLetter();

	// add suggestions
	Suggestion** suggestions = trieNode->getTopSuggestions();
	for (int i = 0; i < NUM_SUGGESTIONS; i++) {
	    Suggestion* s = suggestions[i];
	    if (s == NULL) {
	    	nodeString += NO_SUGGESTION;
	    	continue;
	    }
		nodeString += s->getSuggestedWord() + to_string(s->getCount());
	}
	// add endOfWord flag
	nodeString += trieNode->isEndOfWord() ? IS_END_OF_WORD_FLAG : IS_NOT_END_OF_WORD_FLAG;

	// add number of children
	nodeString += to_string(trieNode->getNumberOfNonNullChilden());
	return nodeString;
}


#endif