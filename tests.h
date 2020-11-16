#pragma once


class Tests
{
public:
	void testItem();

	void testLinkedList();

private:
	//Item
	void testItemWithDefaultConstructor();

	void testItemWithThreeParams();

	void testItemWithCopyConstructor();

	void testItemSetName();

	void testItemSetVolume();

	void testItemSetPrice();

	void testItemGetSpecificValue();

	//LinkedList
	void testLinkedListWithDefaultConstructor();
	void testLinkedListWithCopyConstructor();
	void testLinkedListAddItem();
	void testLinkedListRemoveItem();
	void testLinkedListClear();
	void testLinkedListEqually();
	void testLinkedListWriteData();
	void testLinkedListReadData();

};

