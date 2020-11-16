#include "item.h"

const string Item::DEFAULT_NAME = "item";

const double Item::DEFAULT_VOLUME = 0.000015;

const double Item::DEFAULT_PRICE= 0.0;

Item::Item()
{
	setName(DEFAULT_NAME);
	setVolume(DEFAULT_VOLUME);
	setPrice(DEFAULT_PRICE);
}

Item::Item(const string& name, const double volume, const double price)
{
	setName(name);
	setVolume(volume);
	setPrice(price);
}

Item::Item(const Item& item)
{
	setName(item.getName());
	setVolume(item.getVolume());
	setPrice(item.getPrice());
}

void Item::setName(const string& name)
{
	this->name = name;
}

void Item::setVolume(const double volume)
{
	this->volume = (volume <= DEFAULT_VOLUME) ? DEFAULT_VOLUME : volume;
}

void Item::setPrice(const double price)
{
	this->price = (price < DEFAULT_PRICE) ? DEFAULT_PRICE : price;
}

string Item::getName() const
{
	return name;
}

double Item::getVolume() const
{
	return volume;
}

double Item::getPrice() const
{
	return price;
}

double Item::getSpecificValue() const
{
	return price / volume;
}

bool Item::operator==(const Item& other)
{
	return name == other.name && volume == other.volume && price == other.price;
}

bool Item::operator!=(const Item& other)
{
	return !(*this == other);
}
