//This is for Lab 2 Part 3: Array exercise

#include <iostream>
#include <cstdlib>
#include<ctime>

using namespace std;

void populate_array(int array[], int size);

//function to populate the array elements
void populate_array(int array[], int size){	

	for (int h = 0; h < size; h++){
		int num = rand() % 100;
		array[h] = num + 1;
	}

	return;
}

void print_statistics(int new_array [], int size){
	int total = 0;
	int minimum = 100;
	int maximum = 1;
	for (int h = 0; h < size; h++){
		total += new_array[h];
		if (new_array[h] > maximum){
			maximum = new_array[h];
		}
		if (new_array[h] < minimum){
			minimum = new_array[h];
		}
	}
	cout << "The sum of all elements in your array is: " << total << endl;
	cout << "The minimum value in your array is: " << minimum << " The maximum is: " << maximum << endl;
	cout << "The average of all the elements is: " << total/size << endl;	

	return;
}

int main()
{ 
	int again = 0;
	do{
	srand(time(NULL));
	int size = 0;	
	do {
		cout << "Please enter the size of the array you want between 5 and 50: ";
		cin >> size;
	}while (size < 5 || size > 50);
	int my_array[size];
	populate_array (my_array, size);
	print_statistics(my_array, size);	
	cout << "Would you like to run the program again? Enter 1 if you do. Otherwise enter anything else: ";
	cin >> again;	
	} while (again == 1);
	return 0;
}