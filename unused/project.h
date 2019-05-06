#include <iostream>
#include <string>


struct Car
{
	std::string carName;
	Car * next;

	Car() {};

	Car(std::string carN)
	{
		carName = carN;
		next = NULL;
	}
};


class HashTable
{
public:
	HashTable();
	~HashTable();
	void buildHashTable(std::string parkingLot[], int length);

	void pringHashTable();

private:
	int newHashSum(std::string x, int s);
	int tableSize;
	Car * hashTable[30];
};