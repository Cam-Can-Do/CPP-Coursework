/*
Cameron Candau
main.cpp
CS21, Data Structures and Algorithms Assignment 3: "Quicksort"

Description:
	A program to preform quicksort using a std::vector to store the data
	(accepted from stdin), and print the sorted elements to stdout. Lomuto quicksort
	is used by default, and Hoare quicksort is used if the program is run with "-h"
	as a command line argument. 

	Input is assumed to be integers of at most 9 digits long.
	Prints sorted data with leading zeros.
*/

#include <iostream>
#include <vector>
#include <iomanip>

// swaps the values at index first and second in the vector "V"
void swap(std::vector <int> &V, int first, int second) {
	int temp = V[first];
	V[first] = V[second];
	V[second] = temp;
}

/* 	
	Finds the median value from three indexes in vector "V" and swaps it with
	the final element in the vector
*/
void med_of_3 (std::vector <int> &V, int first, int third) {
	int second = (first + (third - first)/2);
	int med;	

	if (V[first] >= V[second] && V[second] >= V[third]) med = second;
	if (V[first] >= V[third] && V[third] >= V[second]) med = third;
	if (V[second] >= V[first] && V[first] >= V[third]) med = first;
	if (V[second] >= V[third] && V[third] >= V[first]) med = third;
	if (V[third] >= V[first] && V[first] >= V[second]) med = first;
	if (V[third] >= V[second] && V[second] >= V[first]) med = second;
	if (V[med] != V[third]) {
		swap(V, med, third);
	}
}

/*
	Creates two partitions within vector "V" for values less than and greater
	than the pivot element, and then swaps the pivot in between the two partions,
	returning its index. Uses median of 3 to prevent picking a worst case pivot
*/
int partition(std::vector <int> &V, int p, int r) {

	if ((r - p) > 2) {
		med_of_3(V, p, r);
	}

	int x = V[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (V[j] <= x) {
			++i;
			swap(V, i, j);
		}
	}
	swap(V, i + 1, r);
	return i + 1;
}

/*
	Performs quicksort, calling partition to seperate the vector into smaller
	sub-arrays and recursively calls quicksort on each half until the vector
	is entirely sorted.
*/
void quicksort(std::vector <int> &V, int p, int r) {
	if (p < r) {		
		int q = partition(V, p, r);
		quicksort(V, p, q - 1);
		quicksort(V, q + 1, r);
	}
}

/*
	Finds the median value from three indexes in vector "V" and swaps it with
 	the first element in the vector
*/
void H_med_of_3 (std::vector <int> &V, int first, int third) {
	int second = (first + (third - first)/2);
	int med;	

	if (V[first] >= V[second] && V[second] >= V[third]) med = second;
	if (V[first] >= V[third] && V[third] >= V[second]) med = third;
	if (V[second] >= V[first] && V[first] >= V[third]) med = first;
	if (V[second] >= V[third] && V[third] >= V[first]) med = third;
	if (V[third] >= V[first] && V[first] >= V[second]) med = first;
	if (V[third] >= V[second] && V[second] >= V[first]) med = second;
	if (V[med] != V[first]) {
		swap(V, first, med);
	}
}

/*
	Preforms Hoare style partitioning to seperate the vector into two sub-arrays,
	one of elements greater than and one of elements smaller than the pivot.
	Pivot is chosen and swapped to the beginning of the current range with 
	H_med_of_3 function to prevent worse case arrangements. 
*/
int H_partition(std::vector <int> &V, int p, int r) {
	if ((r - p) > 10) {
		H_med_of_3(V, p, r);
	}
	int x = V[p];
	int i = p - 1;
	int j = r + 1;
	while (true) {
		do {i = i + 1;}
		while (V[i] < x);
		do {j = j - 1;}
		while (V[j] > x);
		if (i >= j) return j;
		swap(V, i, j);
	}
}

/*
	Performs quicksort, calling H_partition to seperate the vector into smaller
	sub-arrays with the Hoare method and recursively calls quicksort on each
	half until the vector is entirely sorted.
*/
void H_quicksort(std::vector <int> &V, int p, int r) {
	if (p >= 0 && r >= 0 && p < r) {		
		int q = H_partition(V, p, r);
		H_quicksort(V, p, q);
		H_quicksort(V, q + 1, r);
	}
}

/*
	Main function to accept integers from stdin, push them onto a vector,
	perform quicksort (with Lomuto style partitioning by default or Hoare style 
	with "-h" as a command line argument) and print the sorted values to stdout 
	with a width of 9 characters, including leading 0's if necessary.
*/
int main(int argc, char *argv[]) {
	std::string choice = "";
	if (argc > 1) {
		choice = argv[1];
	}

	std::vector <int> data;
	int temp;
	while (std::cin >> temp) {
		data.push_back(temp);
	}
	int data_size = data.size();
	
	if (choice == "-h") {
		H_quicksort(data, 0, data_size - 1);
	} else { 
		quicksort(data, 0, data_size - 1);
	}
	for (int value: data) {
		std::cout << std::setw(9) << std::setfill('0') << value << '\n';
	}
}
