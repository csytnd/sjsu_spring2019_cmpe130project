#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "hash.h"
using namespace std;

int main(){

	const unsigned int length = 25;
	srand(time(0));

	int a[length];
		for (int i=0; i<length; i++) {
			a[i] = rand()%100;
			if (a[i] == a[i-1]) {
				a[i] = a[i]+1;
			}
			cout << a[i] <<endl;
		}

	Hash h(30); // # = count of buckets

	for (int i = 0; i < length; i++){
		h.insertItem(a[i]);
	}


	h.displayHash();

 return 0;
}
