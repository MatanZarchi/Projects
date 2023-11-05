#include "Zoo.h"


Zoo::Zoo(string n) : _name(n), _size(0), _arr(NULL)
{
	cout << "(Zoo) Zoo constructed\n";
}

Zoo::~Zoo()
{
	for (int i = 0; i < this->_size; i++)
		delete _arr[i];
	delete[]_arr;
	cout << "(Zoo) Zoo destroyed\n";
}

void Zoo::printAllAnimals() const
{
	if (this->_size == 0)
	{
		cout << "Zoo is empty\n";
		return;
	}
	cout << "Size of the zoo: " << this->_size << endl;
	for (int i = 0; i < this->_size; i++)
	{
		cout << "***********************\n";
		this->_arr[i]->print();
	} 
	cout << "*************************\n";
	cout << "(Zoo)///Animals printed///\n";
}


void Zoo::animalParty() const
{
	if (this->_size == 0)
	{
		cout << "Zoo is empty\n";
		return;
	}
	for (int i = 0; i < this->_size; i++)
	{
		cout << "(Zoo)***********************\n";
		this->_arr[i]->maKeNoise();
	}
	cout << "(Zoo)*************************\n";
}


void Zoo::sortAnimalByName()
{
	int i, j;
	for (i = 0; i < this->_size - 1; i++) {
		for (j = 0; j < this->_size - 1 - i; j++) {
			if (this->_arr[j]->getName() > this->_arr[j + 1]->getName())
			{
				swap(_arr[j], _arr[j + 1]);
			}
		}
	}
	cout << "///Zoo sorted///\n";
}

void Zoo::addAnAnimal()
{
	Animal** newarr = new Animal * [this->_size + 1];
	for (int i = 0; i < this->_size; i++)
		newarr[i] = this->_arr[i];
	delete[] this->_arr;
	this->_arr = newarr;
	this->_size++;
	cout << "Choose an animal:\n";
	cout << "1) Animal\n";
	cout << "2) Mammal\n";
	cout << "3) Insect\n";
	cout << "4) Lion\n";
	cout << "5) Horse\n";
	cout << "6) Fly\n";
	int choose;
	cin >> choose;
	switch (choose)
	{
	case 1: newarr[this->_size - 1] = new Animal;
		break;
	case 2: newarr[this->_size - 1] = new Mammal;
		break;
	case 3: newarr[this->_size - 1] = new Insect;
		break;
	case 4:newarr[this->_size - 1] = new Lion;
		break;
	case 5:newarr[this->_size - 1] = new Horse;
		break;
	case 6: newarr[this->_size - 1] = new Fly;
		break;
	default: newarr[this->_size - 1] = new Animal;
	}
	cout << "(Zoo)///Animal added///\n";
}


void Zoo::removeAnimalByName()
{
	int index = 0;
	index = this->findAnimalByName();
	if (index == -1)
		cout << "Not exists\n";
	return;
	delete this->_arr[index];
	this->_arr[index] = this->_arr[this->_size - 1];
	Animal** tempArr = new Animal * [this->_size - 1];
	for (int i = 0; i < this->_size; i++)
		tempArr[i] = this->_arr[i];
	delete[]this->_arr;
	_size--;
	this->_arr = tempArr;
	cout << "(Zoo) ///Removed///\n";
}

int Zoo::findAnimalByName() const
{
	cout << "Enter a name of an animal:\n";
	string tmp;
	cin >> tmp;
	for (int i = 0; i < this->_size; i++)
		if (this->_arr[i]->getName() == tmp) // strcmp
		{
			cout << "(Zoo)*******************\n";
			return i;
		}
	cout << "*********************\n";
	cout << "(Zoo) Name is invalid\n";
	return -1;
}


void Zoo::MENU()
{
	int choice = 0, index = 0;
	while (1)
	{
		cout << "Main menu: " << endl;
		cout << "****************\n";
		cout << "1) Print all animals\n";
		cout << "2) Animals party\n";
		cout << "3) Sort animal by name\n";
		cout << "4) Find all animal\n";
		cout << "5) Add an animal\n";
		cout << "6) Remove an animal by name\n";
		cout << "7) Count an animal\n";
		cout << "8) EXIT\n";
		cout << "Yout cohice: "; 
		cin >> choice;
		

		switch (choice)
		{
		case 1: this->printAllAnimals();
			break;
		case 2: this->animalParty();
			break;
		case 3: this->sortAnimalByName();
			break;
		case 4: index = this->findAnimalByName();
			if (index == -1)
				cout << "Not found\n";
			else
				cout << "Found at index: " << index << endl;
			break;
		case 5: this->addAnAnimal();
			break;
		case 6: this->removeAnimalByName();
			break;
		case 7: this->typeCounter();
			break;
		 case 8: cout << "Bye\n";
			return;
		default: cout << "Please try again\n";
		}

	}
}

void Zoo::typeCounter() const
{
	cout << "Choose an animal:\n";
	cout << "1) Animal\n";
	cout << "2) Mammal\n";
	cout << "3) Insect\n";
	cout << "4) Lion\n";
	cout << "5) Horse\n";
	cout << "6) Fly\n";
	int i, choose, count = 0;
	cin >> choose;


	switch (choose)
	{
	case 1:
		for (i = 0; i < this->_size; i++)
			if (typeid(*(this->_arr[i])) == typeid(Animal))
				count++;
		break;
	case 2:
		for (i = 0; i < this->_size; i++)
			if (typeid(*(this->_arr[i])) == typeid(Mammal))
				count++;
		break;
	case 3:
		for (i = 0; i < this->_size; i++)
			if (typeid(*(this->_arr[i])) == typeid(Insect))
				count++;
		break;
	case 4:
		for (i = 0; i < this->_size; i++)
			if (typeid(*(this->_arr[i])) == typeid(Lion))
				count++;
		break;
	case 5:
		for (i = 0; i < this->_size; i++)
			if (typeid(*(this->_arr[i])) == typeid(Horse))
				count++;
		break;
	case 6:
		for (i = 0; i < this->_size; i++)
			if (typeid(*(this->_arr[i])) == typeid(Animal))
				count++;
		break;

	default: cout << "No animal to count\n";
	}
	cout << "counter is: " << count << endl;
}


int Zoo::countIsMammel() const
{
	int counter = 0;
	for (int i = 0; i < this->_size; i++)
		if (dynamic_cast<Mammal*>(this->_arr[i])) //תן לי את כל מי שיונק
			counter++;
	return counter;
}
//dynamic casting:
//ptrDestination = dynamic_cast<type*>(ptrSource);

//Example 1:
//Animal* ptrS = new Lion;
//Lion* ptrD1 = dynamic_cast<Lion*>ptrS; //ptrD1 will point on Lion
//Mammal* ptrD2 = dynamic_cast<Mammal*>ptrS; // ptrD2 will point to Mammal

//Example 2:
//Animal* ptrS2 = new Mammal;
//Lion* ptrD3 = dynamic_cast<Lion*>ptrS2; // return null


//עובד עם מצביעים בלבד. אם מצביע המקור יורש או שווה לטייפ יחזור מצביע שמצביע על החלק של טייפ בלבד
//null אחרת יוחזר

void Zoo::gotMilkMammalOnly() const
{
	Mammal* ptr = NULL;
	for (int i = 0; i < this->_size; i++)
		if (ptr = dynamic_cast<Mammal*>(this->_arr[i]))
			ptr->gotMilk(); 
}



