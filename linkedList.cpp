#include "linkedList.h"
#include <iostream>
#include <fstream>
#include <assert.h>

Iterator::Iterator(const Node* node)
{
	currNode = node;
}

Iterator& Iterator::operator=(Node* node)
{
	currNode = node;
	return *this;
}

Item Iterator::operator*()
{
	return currNode->data;
}

Iterator& Iterator::operator++()
{
	if (currNode != nullptr)
		currNode = currNode->next;
	return *this;
}

Iterator Iterator::operator++(int)
{
	Iterator iter = *this;
	++(*this);
	return iter;
}

bool Iterator::operator==(const Iterator& other)
{
	return currNode == other.currNode;
}

bool Iterator::operator!=(const Iterator& other)
{
	return currNode != other.currNode;
}

LinkedList::LinkedList()
{
	head = tail = nullptr;
	count = 0;
}

LinkedList::LinkedList(const LinkedList& other)
{
	LinkedList();
	Node* curr = other.head;
	while (curr != nullptr) {
		pushBack(curr->data);
		curr = curr->next;
	}
}

LinkedList::~LinkedList()
{
	clear();
}

Iterator LinkedList::begin()
{
	return Iterator(head);
}

Iterator LinkedList::end()
{
	return Iterator(nullptr);
}

void LinkedList::add(const Item& item)
{
	if (head == nullptr) {
		head = new Node();
		head->data = item;
		head->prev = nullptr;
		head->next = nullptr;
		tail = head;
		count++;
	}
	else if (tail->data.getSpecificValue() <= item.getSpecificValue()) {
		pushBack(item);
	}
	else {
		Node* curr = head;
		while (curr != nullptr)
		{
			if (curr->data.getSpecificValue() > item.getSpecificValue()) {
				Node* node = new Node();
				node->data = item;

				if (curr == head) {
					node->next = head;
					head->prev = node;
					head = node;
				}
				else {
					curr->prev->next = node;
					node->prev = curr->prev;

					curr->prev = node;
					node->next = curr;
				}

				break;
			}
		}
		count++;
	}
}

void LinkedList::remove(const Item& item)
{
	Node* curr = head;
	while (curr != nullptr) {
		if (curr->data == item) {
			if (curr == head) {
				Node* temp = head;
				head = head->next;
				if (head == nullptr) {
					tail = nullptr;
				}
				else {
					head->prev = nullptr;
				}
				delete temp;
			}
			else if (curr->data == tail->data) {
				Node* temp = tail;
				tail = tail->prev;
				tail->next = nullptr;
				delete temp;
			}
			else {
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				delete curr;
			}

			count--;
			break;
		}
		curr = curr->next;
	}
}

void LinkedList::clear()
{
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
		count--;
	}
	head = tail = nullptr;
}

size_t LinkedList::size()
{
	return count;
}

bool LinkedList::operator==(const LinkedList& other)
{
	if (count != other.count)
		return false;
	Node* curr1 = head;
	Node* curr2 = head;
	while (curr1 != nullptr)
	{
		if (curr1->data != curr2->data)
			return false;
		curr1 = curr1->next;
		curr2 = curr2->next;
	}

	return true;
}

bool LinkedList::operator!=(const LinkedList& other)
{
	return !(*this == other);
}

void LinkedList::print()
{
	Node* curr = head;
	while (curr != nullptr) {
		std::cout << curr->data.getName() << std::endl;
		curr = curr->next;
	}
}

void LinkedList::writeData(const string& path)
{
	if (count != 0) {
		ofstream fout;
		fout.open(path);
		fout << count << endl;
		Node* curr = head;
		while (curr != nullptr) {
			fout << curr->data.getName() << endl;
			fout << curr->data.getVolume() << endl;
			fout << curr->data.getPrice() << endl;
			curr = curr->next;
		}
		fout.close();
	}
}

void LinkedList::readData(const string& path)
{
	ifstream fin(path);

	if (!fin.is_open()) {
		cout << "File not open" << endl;
		assert(false);
	}
	else {
		string str;
		getline(fin, str);
		if (str.empty())
			cout << "File is empty" << endl;
		else {
			int size = stoi(str);
			for (int i = 0; i < size; ++i) {
				Item item;
				getline(fin, str);
				item.setName(str);
				getline(fin, str);
				item.setVolume(stod(str));
				getline(fin, str);
				item.setPrice(stod(str));
				add(item);
			}
		}
		fin.close();
	}
}

void LinkedList::pushBack(const Item& item)
{
	if (tail == nullptr) {
		tail = new Node();
		tail->data = item;
		tail->next = nullptr;
		tail->prev = nullptr;
		head = tail;
	}
	else {
		tail->next = new Node();
		tail->next->data = item;
		tail->next->next = nullptr;
		tail->next->prev = tail;
		tail = tail->next;
	}
	count++;
}

Node::Node()
{
	next = prev = nullptr;
}
