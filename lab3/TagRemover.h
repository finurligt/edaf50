#ifndef TAGREMOVER_H
#define TAGREMOVER_H
#include <iostream>


class TagRemover {
public:
	TagRemover(std::istream& is);
	TagRemover(std::string str);
	void print(std::ostream& os) const;
	std::string getText() const;


private:
	std::string text;

	void removeTags();
	void specialCharacters();
};


#endif
