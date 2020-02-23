#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"


using std::vector;
using std::string;

Word::Word(const string& w, const vector<string>& t) {
	word = w;
	for (std::string tri : t) {
		trigrams.insert(tri);
	}
}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	int i{ 0 };
	for (std::string tri : t) {
		i += trigrams.count(tri);
	}
	return i;
}
