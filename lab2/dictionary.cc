
#include <sstream>

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include "word.h"
#include "dictionary.h"

using std::string;
using std::vector;
using std::ofstream;


Dictionary::Dictionary() { 
    //load dictionary
    std::ifstream infile("dict.txt");
    if (!infile) { // file couldn't be opened
        std::cout << "Error: file could not be opened" << std::endl;
        exit(1);
    }

    std::string str;
    while (std::getline(infile, str)) {
        wordSet.insert(str);
    }

    //load trigram prepped words
    std::ifstream infile2("words.txt");
    if (!infile2) { // file couldn't be opened
        std::cout << "Error: file could not be opened" << std::endl;
        exit(1);
    }

    std::string str2;
    while (std::getline(infile2, str2)) {
        std::string word;
        std::istringstream iss(str2);
        iss >> word;
        std:string skip;
        iss >> skip;
        std::string tri;
        std::vector<std::string> tris;
        while (iss >> tri) {
            tris.push_back(tri);
        }
        Word wordToAdd{ word,tris };
        if (word.size() <= MAXLENGTH){
            trigramWords[word.size()-1].push_back(wordToAdd);
        }
    }
}

bool Dictionary::contains(const string& word) const {
    return wordSet.count(word); //wordSet.find(word) != wordSet.end();
}

vector<string> Dictionary::get_suggestions(const std::string& word) const {
    std::vector < std::string > suggestions;
    add_trigram_suggestions(suggestions, word);
    rank_suggestions(suggestions, word);
    trim_suggestions(suggestions);
    return suggestions;
}

void Dictionary::add_trigram_suggestions(std::vector<std::string>& suggestions, const std::string& word) const {
    if (word.size() > 2 && word.size() < MAXLENGTH) {
        for (Word w : trigramWords[word.size() - 2]) {
            suggestions.push_back(w.get_word());
        }
        for (Word w : trigramWords[word.size() -1]) {
            suggestions.push_back(w.get_word());
        }
        for (Word w : trigramWords[word.size()]) {
            suggestions.push_back(w.get_word());
        }
    }
    else if (word.size() == MAXLENGTH) {
        for (Word w : trigramWords[word.size() - 1]) {
            suggestions.push_back(w.get_word());
        }
        for (Word w : trigramWords[word.size()]) {
            suggestions.push_back(w.get_word());
        }
    }
}

int cost(std::string& p, const std::string& q) {
    int d[26][26];
    for (int i = 0;i < MAXLENGTH+1;i++) {
        d[i][0] = i;
        d[0][i] = i;
    }
    for (int i = 1;i < p.length()+1;i++) {
        for (int j = 1; j < q.length()+1;j++) {
            int same;
            if (p[i-1] == q[j-1]) {
                same = d[i - 1][j - 1];
            }
            else {
                same = d[i - 1][j - 1] + 1;
            }

            d[i][j] = std::min(same,std::min(d[i - 1][j] + 1, d[i][j - 1] + 1));
        }
    }
    /*
    for (int i = 0;i < p.length();i++) {
        for (int j = 0; j < q.length();j++) {
            unsigned int number_of_digits = 0;
            int n = d[i][j];

            do {
                ++number_of_digits;
                n /= 10;
            } while (n);

            std::string str( (unsigned int)3 - number_of_digits,' ' );
            std::cout << d[i][j]<<str;
        }
        std::cout << std::endl;
    }
    std::cout << p << " " << q << " cost: " << d[p.length()][q.length()] << std::endl;
    */
    return d[p.length()][q.length()];
}

void Dictionary::rank_suggestions(std::vector<std::string>& suggestions, const std::string& word) const {
    vector<std::pair<int, string>> ranking;
    for (std::string str : suggestions) {
        ranking.push_back(std::make_pair(cost(str, word), str));
    }
    std::sort(ranking.begin(), ranking.end());
    suggestions.clear();
    for (auto sugg: ranking) {
        suggestions.push_back(sugg.second);
        //if (sugg.first < 3) {
        //    std::cout << sugg.first << " " << sugg.second << std::endl;
        //}
    }
}

void Dictionary::trim_suggestions(std::vector<std::string>& suggestions) const {
    if (suggestions.size() > 5) {
        suggestions.resize(5);
    }
}
