/*
Cameron Candau
camcandau@gmail.com
main.cpp
Assignment 4: "Radix/Bucket Sort Hybrid"

Description: 
	Accepts integers from stdin until EOF, pushes each onto a std::vector,
	uses the radix/bucket hybrid sort to sort the elements, and then prints them 
	to stdout in sorted (ascending) order.
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

/*
	Given integers n and i, returns the integer in the i'th position of n.
	If n = 235 and i = 2, this function will return 3
*/
int digit (int n, int i) {
	if (i == 0) { 
		return n % 10;
	} else {
		return (n / (int)pow(10,i) % 10);
	}
}

/*
	Preforms the radix/bucket hybrid sort on a std::vector<int>, modifying
	the vector directly by reference. 
*/
void radix_bucket(std::vector <int> &V) {
	int n = V.size();
	int d = 9;
	int k = 10;

	std::vector<std::vector<int>> B(k);
	for (int i = 0; i <= d; ++i) {
		for (int j = 0; j < n; ++j) {
			B[digit(V[j], i)].push_back(V[j]);
		}
		V.clear();
		for (int i = 0; i <= d; ++i) {
			int B_size = B[i].size();
			if (B_size > 0) {
				for (int j = 0; j < B_size; ++j) {
					V.push_back(B[i][j]);
				}
				B[i].clear();
			}
		}
	}
}

/*
	Main function to accept integers from stdin, push them onto a vector,
	perform Radix/Bucket Hybrid Sort and print the sorted values to stdout 
	with a width of 9 characters, including leading 0's if necessary.
*/
int main() {
	std::vector <int> data;
	int temp;
	while (std::cin >> temp) {
		data.push_back(temp);
	}

	radix_bucket(data);

	for (int value: data) {
		std::cout << std::setw(9) << std::setfill('0') << value << '\n';
	}
}
