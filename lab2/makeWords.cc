#include <iostream>
using std::endl;
#include <fstream>
using std::ofstream;
#include <cstdlib> // for exit function
#include <vector>
#include <bits/stdc++.h> 



int main() {
    std::ifstream infile("dict.txt");
    ofstream outfile("words.txt");
    if (!outfile || !infile) { // file couldn't be opened
        std::cout << "Error: file could not be opened" << endl;
        exit(1);
    }

    
    std::string str;
    while (std::getline(infile, str)) {
        // output the line
        int length = str.length();
        outfile << str;
        std::vector<std::string> arr{};
        for (int i = 0; i < length-2; i++) {
            arr.push_back(str.substr(i, 3).c_str());
        }
        sort(arr.begin(), arr.end());
        outfile << " " << arr.size();
        for (auto& tri : arr) {
            outfile << " " << tri;
        }
        outfile << std::endl;

        // now we loop back and get the next line in 'str'
    }
    

    

    outfile << "my text here!" << std::endl;

    outfile.close();

    return 0;
}