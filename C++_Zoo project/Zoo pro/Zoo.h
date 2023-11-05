#pragma once
#include "Lion.h"
#include "Horse.h"
#include "Fly.h"


class Zoo //container
{
private:
	string _name;
	Animal** _arr; //למה מערך של פוינטרים לאנימל? מכיוון שאנו רוצים לפנות לאובייקטים שאנימל מכיל
	int _size; // sizeof(_arr) / sizeof(*animal)
public:
	Zoo(string n);
	~Zoo();
	void printAllAnimals() const;
	void animalParty() const;
	void sortAnimalByName(); // not const cause we have to sort the array by alpha bet
	void addAnAnimal();
	void removeAnimalByName();
	int findAnimalByName() const;
	void MENU();
	void typeCounter()const;
	int countIsMammel() const;
	void gotMilkMammalOnly() const;
};

