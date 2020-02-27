#include "TagRemover.h"
#include <iostream>

void testRemoveTags() {
	std::string test = "Haj du<, din sabla glytt>, kan man fa sig en sluring<javel> eller?";
	std::string verify = "Haj du, kan man fa sig en sluring eller?";
	TagRemover tr(test);
	if (tr.getText().compare(verify) == 0) {
		std::cout << "success - testRemoveTags()" << std::endl;
	} else {
		std::cout << "test failed - testRemoveTags()" << std::endl;
		std::cout << "got:       " << tr.getText() << std::endl;
		std::cout << "expected:  " << verify << std::endl;
	}
}

void testSpecialCharacters() {
	std::string test = "Tack &lt; for &gt; inbjudan &nbsp; glytt &amp; inge camping";
	std::string verify = "Tack < for > inbjudan   glytt & inge camping";
	TagRemover tr(test);
	if (tr.getText().compare(verify) == 0) {
		std::cout << "success - testSpecialCharacters()" << std::endl;
	}
	else {
		std::cout << "test failed - testSpecialCharacters()" << std::endl;
		std::cout << "got:       " << tr.getText() << std::endl;
		std::cout << "expected:  " << verify << std::endl;
	}
}

int main() {
	testRemoveTags();
	testSpecialCharacters();
}

