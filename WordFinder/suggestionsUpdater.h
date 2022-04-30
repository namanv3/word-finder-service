#ifndef __SUGGESTIOS_UPDATER__
#define __SUGGESTIOS_UPDATER__

void updateSuggestionTillRoot(TrieNode* node, string word) {
	if (node == NULL) {
		return;
	}

	node->addNewSuggestionOrIncrement(word);
	updateSuggestionTillRoot(node->getParent(), word);
}

#endif