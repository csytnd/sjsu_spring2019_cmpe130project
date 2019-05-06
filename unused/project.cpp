// Header files section
#include <iostream>
#include <string>
#include <iomanip>
#include<fstream>
#include <sstream>



// Car struct
struct Car
{
   // std::string title;
   // // // Car *next;

   // // Car() {};

   // // Car(std::string in_title)
   // // {
   // //     title = in_title;
   // //     next = NULL;
   // // }
    int key;
    std::string carName;


};

// HashTable class specification
class HashTable
{
public:
   HashTable();
   ~HashTable();


   void getCarlist(struct Car car_list[], int key, int *num_of_cars);
   void resetList(struct Car car_list[], int num_of_cars);
   void buildHashTable(std::string cars[], int length);

   void printHashTable();

private:
   int newHashSum(std::string x, int s);
   int parkingLot;
   Car * hashTable[10];
};

// HashTable class implementation

// Default Constructor
HashTable::HashTable()
{
   parkingLot = 30;

   for (int i = 0; i < parkingLot; i++)
   {
       hashTable[i] = NULL;
   }
}

// Destructor
HashTable::~HashTable()
{
   // for (int i = 0; i < parkingLot; i++)
   // {
   //     Car* head = hashTable[i];

   //     while (head != NULL)
   //     {
   //         Car *current = head->next;
   //         head->next = NULL;
   //         delete head;
   //         head = current;
   //     }
   // }
}

// buildHashTable function implementation
void HashTable::buildHashTable(std::string cars[], int length)
{
   // for (int i = 0; i < length; i++)
   // {
   //     std::string name = cars[i];

   //     // call the newHashSum function
   //     int index = newHashSum(name, 5);

   //     if (hashTable[index] == NULL)
   //     {
   //         hashTable[index] = new Car(name);
   //     }
   //     else
   //     {
   //         Car *current = hashTable[index];
   //         while (current->next != NULL)
   //         {
   //             current = current->next;
   //         }

   //         current->next = new Car(name);
   //     }
   // }
}


// newHashSum function implementation
int HashTable::newHashSum(std::string x, int s)
{
   int total = 0;

   for (unsigned int index = 0; index < x.length(); index++)
   {
       if (index % 4 == 0)
           total += int(x[index]);
   }

   int remainder = total % s;

   return remainder;
}




void getCarList(struct Car car_list[], int key, int *num_of_cars)
{


    int n= 0;
    std::string line;
    std::ifstream infile;   //declare a in filestream
    infile.open("cars.dat"); //open file
    if(!infile.is_open())
    {
        std::cout << "Error opening file.\n" << std::endl;
    }

    while(getline(infile,line))
    {
        std::stringstream ss(line);
        ss >> car_list[n].carName;
        car_list[n].key = 10000 + ( std::rand() % (99999-10000+1));
        n++;

        // for (int i = 0; i < *num_of_cars; i++)
        // {
        //     std::cout << car_list[i].carName << "\n\n" << std::endl; 
        // }
    }

        infile.close();
        *num_of_cars = n;

    // FILE *fp;

    // printf("Opening cars.dat file. \n");
    // fp = fopen("cars.dat","r");

    // if(fp == NULL)
    // {
    //     perror("Error while opening file.\n");
    //     //exit
    // }
    // char line[1000];
    // std::string carName;
    // int n, index = 0;

    // while(fgets(line,1000, fp)!=NULL)
    // {
    //     n = sscanf(line, "%s\n", &carName);
    //     if(n>0)
    //     {
    //         car_list[index].carName = carName;
    //     }
    //     index++;
    //     printf("Car name: %s\n", car_list[index].carName);
    // }


    // fclose(fp);

    //store num_of_cars
    // *num_of_cars = index;

}

void printCars(struct Car *car_list, int num_of_cars)
{

    for (int i = 0; i < num_of_cars; i++)
    {
        std::cout<< "Car #: " << i+1 << "  "  << "Car Name: " << car_list[i].carName << 
        "  Key: " << car_list[i].key << "\n" << std::endl;
    }

}
// Print HashTable
void HashTable::printHashTable()
{
   // for (int i = 0; i < parkingLot; i++)
   // {
   //     std::cout << "Index " << i << ":" << std::endl;
   //     Car *current = hashTable[i];
   //     while (current != NULL)
   //     {
   //         std::cout << current->title;

   //         if (current->next != NULL)
   //             std::cout << " => ";

   //         current = current->next;
   //     }
   //     std::cout << std::endl << std::endl;
   // }

    // for ( int i = 0; i < 30; i++)
    // {
    //     cout << "Index: " << i << "Key: ";
    //     for ( int key: table[i])
    //     {
    //         std::cout << key << " ";
    //     }
    //     cout << endl;
    // }
}

// Main
int main()
{



   // // create a reference of HashTable class
   // HashTable ht;

   // // call the buildHashTable function
   // ht.buildHashTable(cars, 14);

   // // call the printHashTable function
   // ht.printHashTable();

struct Car car_list[30];
int num_of_cars;
int key;

getCarList(car_list, key, &num_of_cars);

printCars(car_list, num_of_cars);
   return 0;

}