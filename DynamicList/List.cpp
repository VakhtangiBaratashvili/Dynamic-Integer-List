#include "List.h"
#include <iostream>
using namespace std;
void List::display(ostream& out) const{
	out << "[";
	for (int i = 0; i < SIZE; i++) {
		out << list[i];
		if (i != SIZE - 1) {
			out << ", ";
		}
	}
	out << "]";
}

int List::indexOf(int number){
	for (int i = 0; i < SIZE; i++) {
		if (list[i] == number) {
			return i;
		}
	}
	return - 1;
}

int& List::operator[](int number) {
	return list[number];
}

void List::resize() {
	ElementType* temp = new ElementType[CAPACITY * 2];
	for (int i = 0; i < SIZE; i++) {
		temp[i] = list[i];
	}
	delete[] list;
	list = temp;
	CAPACITY *= 2;
}

List::List() {
	SIZE = 0;
	list = new ElementType[CAPACITY];
}

List::~List() {
	delete[] list;
}

bool List::isEmpty() {
	return SIZE == 0;
}

void List::add(int number, int index) {
	if (SIZE == CAPACITY) {
		resize();
	}
	else if (index < 0 || index > SIZE) {
		cerr << "Coundn't add a new element" << endl;
	}
	for (int i = SIZE; i > index; i--) {
		list[i] = list[i - 1];
	}
	list[index] = number;
	SIZE++;
}

void List::add(int number) {
	add(number, SIZE);
}

void List::remove(int index) {
	if (isEmpty()) {
		cerr << "List is empty";
	}
	else if (index < 0 || index >= SIZE) {
		cerr << "Couldn't remove";
	}
	else {
		for (int i = index; i < SIZE; i++) {
			list[i] = list[i + 1];
		}
		SIZE--;
	}
}

void List::set(int number, int index) {
	if (isEmpty()) {
		cerr << "List is empty";
	}
	else if (index < 0 || index >= SIZE) {
		cerr << "Couldn't set";
	}
	else {
		list[index] = number;
	}
}

int List::size()
{
	return SIZE;
}


bool List::contains(int number) {
	for (int i = 0; i < SIZE; i++) {
		if (list[i] == number) {
			return true;
		}
	}
	return false;
}

void List::clear() {
	delete[] list;
	list = new ElementType[CAPACITY];
	SIZE = 0;
}

ostream& operator<<(ostream& out, const List& list) {
	list.display(out);
	return out;
}
