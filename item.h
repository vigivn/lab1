#pragma once
#include <string>
using namespace std;


class Item
{
public:
	static const string DEFAULT_NAME;
	static const double DEFAULT_VOLUME;
	static const double DEFAULT_PRICE;

	Item();
    Item(
        const string &name,
        const double volume,
        const double price);
	Item(const Item& item);

    void setName(const string &name);
	void setVolume(const double volume);
	void setPrice(const double price);

    string getName() const;
    double getVolume() const;
    double getPrice() const;
	double getSpecificValue() const;

	bool operator==(const Item& other);
	bool operator!=(const Item& other);

private:
	string name;
	double volume;
	double price;
};

