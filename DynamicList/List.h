#pragma once
#include <iostream>
using namespace std;

class List {
private:
	int SIZE;
	int CAPACITY = 10;
	typedef int ElementType;
	ElementType* list;
	void resize();
public:
	List();
	~List();
	bool isEmpty();
	void add(int number, int index);
	void add(int number);
	void remove(int index);
	void set(int number, int index);
	int size();
	bool contains(int number);
	void clear();
	void display(ostream& out) const;
	int indexOf(int number);
	int& operator[](int number);
	friend ostream& operator<< (ostream& out, const List& List);
};

