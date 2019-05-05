#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "hash.h"
using namespace std;

int main(){

	string c[10];
	const unsigned int length = 10;
	srand(time(0));

	cout << "Enter info for 10 cars: " << endl;
	for (int i=0; i<length; i++) {
		cout << i+1 << ")";
		cin >> c[i];

	}

	cout << "Cars entered: ";
	for (int i=0; i<length; i++) {
		cout << c[i] << ", ";
	}
	cout << endl;

	int a[length];
		for (int i=0; i<length; i++) {
			a[i] = rand()%50;
			if (a[i] == a[i-1]) {
				a[i] = a[i]+1;
			}
			cout << a[i] <<endl;
		}

	Hash h(length); // length = # of buckets

	for (int i = 0; i < length; i++){
		h.insertItem(a[i]);
	}


	h.displayHash();

 return 0;
}
