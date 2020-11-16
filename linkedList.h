#pragma once
#include "item.h"
class LinkedList;
class Iterator;

class Node {
	friend class Iterator;
	friend class LinkedList;
public:
	Node();
private:
	Item data;
	Node* next;
	Node* prev;
};

class Iterator {
	friend class LinkedList;
public:
	Iterator(const Node* node);
	Iterator& operator=(Node* node);
	Item operator*();
	Iterator& operator++(); //prefix
	Iterator operator++(int); //postfix
	bool operator==(const Iterator& other);
	bool operator!=(const Iterator& other);
private:
	const Node* currNode;
};

class LinkedList {
	friend class Iterator;
public:
	LinkedList();
	LinkedList(const LinkedList& other);
	~LinkedList();

	Iterator begin();
	Iterator end();

	void add(const Item& item);
	void remove(const Item& item);

	void clear();
	size_t size();

	bool operator==(const LinkedList& other);
	bool operator!=(const LinkedList& other);
	
	void print();
	void writeData(const string& path);
	void readData(const string& path);
private:
	void pushBack(const Item& item);

private:
	Node* head;
	Node* tail;
	size_t count;
};
