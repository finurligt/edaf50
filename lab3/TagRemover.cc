#include "tagremover.h"
#include <iostream>


//int main() {
//	TagRemover tr(std::cin); // read from cin
//	tr.print(std::cout); // print on cout
//}

TagRemover::TagRemover(std::istream& is) {
    std::string line;
    while (std::getline(is, line)) {
        text += line;
        text += "\n";
    }
    removeTags();
    specialCharacters();
}

TagRemover::TagRemover(std::string str) {
    text = str;
    removeTags();
    specialCharacters();
}

void TagRemover::removeTags()  {
    int start(0);
    while (1) {
        start = text.find("<", start);
        if (start == std::string::npos) {
            break;
        }

        auto end = text.find(">", start);
        if (end == std::string::npos) {
            break;
        }
        text.erase(start, 1 + end - start);
    }
    //std::cout << start << "-" << end;
}

void TagRemover::specialCharacters() {
    int start(-1);
    while (1) {
        start = text.find("&",start+1);
        if (start == std::string::npos) {
            break;
        }
        
        auto end = text.find(";", start);
        if (end == std::string::npos) {
            break;
        }

        std::string sub = text.substr(start, 1 + end - start);
        if (sub.compare("&lt;")==0) {
            text.replace(start, sub.size(),"<");
        } else if (sub.compare("&gt;")==0){
            text.replace(start, sub.size(),">");
        } else if (sub.compare("&nbsp;")==0) {
            text.replace(start, sub.size()," ");
        } else if (sub.compare("&amp;")==0) {
            text.replace(start, sub.size(),"&");
        }
    }
}


void TagRemover::print(std::ostream& os) const {
    os << text;
}

std::string TagRemover::getText() const {
    return text;
}
