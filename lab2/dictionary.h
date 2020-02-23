#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

constexpr auto MAXLENGTH = 25;

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
private:
	std::unordered_set<std::string> wordSet;
	std::vector<Word> trigramWords[MAXLENGTH];
	void add_trigram_suggestions(std::vector<std::string>& suggestions, const std::string& word) const;
	void rank_suggestions(std::vector<std::string>& suggestions, const std::string& word) const;
	void trim_suggestions(std::vector<std::string>& suggestions) const;
};

#endif
