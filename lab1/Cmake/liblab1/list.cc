#include <iostream>
#include "list.h"

List::List() {
	first = nullptr;
}

List::~List() {
	while (first != nullptr)
	{
		Node* del = first;
		first = first->next;
		delete del;
	}
}

bool List::exists(int d) const {
	Node* n = first;
	while (n != nullptr)
	{
		if (n->value == d)
		{
			return true;
		}
		n = n->next;
	}
	return false;
}

int List::size() const {
	Node* n = first;
	int i{ 0 };
	while (n != nullptr)
	{
		++i;
		n = n->next;
	}
	return i;
}

bool List::empty() const {
	return (first==nullptr);
}

void List::insertFirst(int d) {
	Node* temp = new Node(d,first);
	first = temp;
	
}

void List::remove(int d, DeleteFlag df) {
	Node* n = first;
	if (df == DeleteFlag::LESS)
	{
		if (n->value < d)
		{
			first = first->next;
			delete n;
			return;
		}
		while (n->next != nullptr)
		{
			if (n->next->value < d)
			{
				Node* tmp = n->next;
				n->next = n->next->next;
				delete tmp;
				return;
			}
			n = n->next;
		}
	}
	if (df == DeleteFlag::GREATER)
	{
		if (n->value > d)
		{
			first = first->next;
			delete n;
			return;
		}
		while (n->next != nullptr)
		{
			if (n->next->value > d)
			{
				Node* tmp = n->next;
				n->next = n->next->next;
				delete tmp;
				return;
			}
			n = n->next;
		}
	}
	if (df == DeleteFlag::EQUAL)
	{
		if (n->value == d)
		{
			first = first->next;
			delete n;
			return;
		}
		while (n->next != nullptr)
		{
			if (n->next->value == d)
			{
				Node* tmp = n->next;
				n->next = n->next->next;
				delete tmp;
				return;
			}
			n = n->next;
		}
	}
}

void List::print() const {
	Node* n = first;
	std::cout << "{";
	while (n != nullptr)
	{
		std::cout << n->value << ", ";
		n = n->next;
	}
	std::cout << "}" << std::endl;
}

