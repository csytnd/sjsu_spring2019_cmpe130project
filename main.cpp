#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include "hash.h"
using namespace std;

int main(){
	Car car_list[30];

	int n= 0;
    string line;
    ifstream infile;   //declare a in filestream
    infile.open("cars.dat"); //open file
    if(!infile.is_open())
    {
        cout << "Error opening file.\n" << endl;
    }

    while(getline(infile, line))
    {
        stringstream ss(line);
        ss >> car_list[n].carName;
        car_list[n].key = 10000 + ( rand() % (99999-10000+1));
        n++;
    }
    infile.close();


	Hash h(30); // length = # of buckets
	for (int i = 0; i < n; i++){
		h.insertItem(car_list[i]);
	}


	h.displayHash();

 return 0;
}

