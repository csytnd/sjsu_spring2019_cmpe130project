#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include <list>
using namespace std;

struct Car
{
    int key;
    string carName;
};

class Hash
{
	int BUCKET;
	list<Car> *table;

public:
	Hash(int b);
	void insertItem(Car car);
	void deleteItem(Car car);
	int hashFunction1(Car car);
	int hashFunction2(Car car);
	int hashFunction3(Car car);
	int chooseHashFunction(Car car);
	

	void displayHash();
};

Hash::Hash(int b) {
	this->BUCKET = b;
	table = new list<Car>[BUCKET];
}

int Hash::hashFunction1(Car car)
{
	return (car.key % 5);
}

int Hash::hashFunction2(Car car) {
	return ((car.key * 109) % 29);
}

int Hash::hashFunction3(Car car) {
	return ((car.key - 109) % 17);
}

int Hash::chooseHashFunction(Car car)
{
	int result = 0;
	if((car.key >= 10000) && (car.key < 30000))
	{
		result = hashFunction1(car);
	}
	else if((car.key >= 30000) && (car.key < 60000))
	{
		result = hashFunction2(car);
	}
	else if((car.key >= 60000) && (car.key < 99999))
	{
		result = hashFunction3(car);
	}
	else
	{
		result = hashFunction1(car);
	}
	return result;
}

void Hash::insertItem(Car car) {
	int index = chooseHashFunction(car);
	table[index].push_back(car);
}

void Hash::deleteItem(Car car) {
	int index = chooseHashFunction(car);

	list <Car> :: iterator i;
	for (i = table[index].begin();
			i != table[index].end(); i++) {
		if ((*i).key == car.key)
		break;
	}

	if (i != table[index].end())
		table[index].erase(i);
}

void Hash::displayHash() {
	for (int i = 0; i < BUCKET; i++) {
		cout << i;
		for (auto x : table[i])
		cout << " --> " << x.key << " " << x.carName;
		cout << endl;
	}
}

#endif /* HASHTABLE_H_ */