#include "tests.h"
#include "item.h"
#include "linkedList.h"
#include <assert.h>
#include <iostream>

void Tests::testItem()
{
	testItemWithDefaultConstructor();
	testItemWithThreeParams();
	testItemWithCopyConstructor();
	testItemSetName();
	testItemSetVolume();
	testItemSetPrice();
	testItemGetSpecificValue();

	cout << "all item tests are passed" << endl;
}

void Tests::testLinkedList()
{
	testLinkedListWithDefaultConstructor();
	testLinkedListWithCopyConstructor();
	testLinkedListAddItem();
	testLinkedListRemoveItem();
	testLinkedListClear();
	testLinkedListEqually();
	testLinkedListWriteData();
	testLinkedListReadData();
	cout << "all linked list tests are passed" << endl;
}

void Tests::testItemWithDefaultConstructor()
{
	Item item;
	assert(item.getName() == Item::DEFAULT_NAME);
	assert(item.getVolume() == Item::DEFAULT_VOLUME);
	assert(item.getPrice() == Item::DEFAULT_PRICE);
}

void Tests::testItemWithThreeParams()
{
	Item item = Item("cheap item", 14.5, 0.25);
	assert(item.getName() == "cheap item");
	assert(item.getVolume() == 14.5);
	assert(item.getPrice() == 0.25);
}

void Tests::testItemWithCopyConstructor()
{
	Item item = Item("cheap item", 1.5, 4400);
	Item item1 = Item(item);
	assert(item.getName() == item1.getName());
	assert(item.getVolume() == item1.getVolume());
	assert(item.getPrice() == item1.getPrice());
}

void Tests::testItemSetName()
{
	Item item;
	item.setName("cheap item");
	assert(item.getName() == "cheap item");
}

void Tests::testItemSetVolume()
{
	Item item;
	item.setVolume(12.45);
	assert(item.getVolume() == 12.45);

	item.setVolume(-78);
	assert(item.getVolume() == Item::DEFAULT_VOLUME);

	item.setVolume(0);
	assert(item.getVolume() == Item::DEFAULT_VOLUME);
}

void Tests::testItemSetPrice()
{
	Item item;
	item.setPrice(12.45);
	assert(item.getPrice() == 12.45);

	item.setPrice(-78);
	assert(item.getPrice() == Item::DEFAULT_PRICE);
}

void Tests::testItemGetSpecificValue()
{
	Item item;
	assert(item.getSpecificValue() == Item::DEFAULT_PRICE / Item::DEFAULT_VOLUME);

	item.setPrice(44);
	item.setVolume(0);
	assert(item.getSpecificValue() == 44 / Item::DEFAULT_VOLUME);
}

void Tests::testLinkedListWithDefaultConstructor()
{
	LinkedList list;
	assert(list.size() == 0);
	assert(list.begin() == Iterator(nullptr));
	assert(list.end() == Iterator(nullptr));
}

void Tests::testLinkedListWithCopyConstructor()
{
	Item item1("1", 10, 10);
	Item item2("2", 10, 10);
	Item item3("3", 10, 10);

	LinkedList list;
	list.add(item1);
	list.add(item2);
	list.add(item3);

	LinkedList copy(list);

	for (auto it = copy.begin(); it != copy.end(); ++it) {
		assert((*it).getVolume() == 10.0);
	}
}

void Tests::testLinkedListAddItem()
{
	Item item1("1", 10, 15);
	Item item2("2", 10, 10);
	Item item3("3", 10, 60);

	LinkedList list;
	list.add(item1);
	list.add(item2);
	list.add(item3);

	auto it = list.begin();
	assert(list.size() == 3);
	assert((*it).getSpecificValue() == 1.0);
	++it;
	assert((*it).getSpecificValue() == 1.5);
	++it;
	assert((*it).getSpecificValue() == 6.0);
}

void Tests::testLinkedListRemoveItem()
{
	Item item1("1", 10, 10);
	Item item2("2", 10, 15);
	Item item3("3", 10, 60);

	LinkedList list;
	list.add(item1);
	list.remove(item1);
	assert(list.size() == 0);
	assert(list.begin() == Iterator(nullptr));
	assert(list.end() == Iterator(nullptr));


	list.add(item1);
	list.add(item2);
	list.remove(item1);
	assert(list.size() == 1);
	assert((*list.begin()).getName() == "2");

	list.add(item1);
	list.remove(item2);
	assert(list.size() == 1);
	assert((*list.begin()).getName() == "1");


	list.add(item2);
	list.add(item3);
	list.remove(item2);
	assert(list.size() == 2);
	auto it = list.begin();
	assert((*it).getName() == "1");
	++it;
	assert((*it).getName() == "3");
}

void Tests::testLinkedListClear()
{
	Item item1("1", 10, 10);
	Item item2("2", 10, 10);
	Item item3("3", 10, 10);

	LinkedList list;
	list.add(item1);
	list.add(item2);
	list.add(item3);
	list.clear();
	assert(list.size() == 0);
	assert(list.begin() == Iterator(nullptr));
	assert(list.end() == Iterator(nullptr));
}

void Tests::testLinkedListEqually()
{
	Item item1("1", 10, 10);
	Item item2("2", 10, 10);
	Item item3("3", 10, 10);

	LinkedList list1;
	list1.add(item1);
	list1.add(item2);
	list1.add(item3);

	LinkedList list2;
	list2.add(item1);
	list2.add(item2);
	list2.add(item3);

	assert(list1 == list2);
}

void Tests::testLinkedListWriteData()
{
	Item item1("1", 10, 10);
	Item item2("2", 20, 20);
	Item item3("3", 30, 30);

	LinkedList list;
	list.add(item1);
	list.add(item2);
	list.add(item3);
	list.writeData("out.txt");
}

void Tests::testLinkedListReadData()
{
	LinkedList list;
	list.readData("out.txt");
	assert(list.size() == 3);
	auto it = list.begin();
	assert((*it).getName() == "1");
	++it;
	assert((*it).getName() == "2");
	++it;
	assert((*it).getName() == "3");
}
