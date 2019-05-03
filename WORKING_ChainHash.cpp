#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "hash.h"
using namespace std;

int main(){

	const unsigned int length = 30;
	int a[length];
		for (int i=0; i<length; i++) {
			a[i] = rand()%100;
			if (a[i] == a[i-1]) {
				a[i] = a[i]+1;
			}
			cout << a[i] <<endl;
		}

	// insert the keys into the hash table
	Hash h(30); // 7 is count of buckets in
				// hash table
	for (int i = 0; i < length; i++)
		h.insertItem(a[i]);

	h.displayHash();

	//h.deleteItem(18);

	//h.displayHash();

 return 0;
}
