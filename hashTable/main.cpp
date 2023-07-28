/*
Cameron Candau
main.cpp
Assignment #5 "Hash Table"

Description: 
Hash table with chaining using multiplication rule.
Code Status: Finished, tested
Compiles/Warnings? Compiles, no warnings
Questions/Comments:
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "hashTable.h"
 	
int main() {	

	hashTable table(178000);	
	std::string str_choice;
	bool end = false;
	while (end == false) {
		std::cout << "(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? ";
		std::getline(std::cin, str_choice);	
		int choice = -1;
		if (str_choice.length() != 1 || !isdigit(str_choice[0])) {
			choice = -1;
		} else {
			choice = stoi(str_choice);
		}
		if (choice == 1) {
			//load
			std::cout << "read hash table - filename? ";
			std::string fname;
			std::getline(std::cin, fname); 
			std::ifstream in_file;
			in_file.open(fname.c_str());	
			if (in_file.fail()) { return 0; }
			
			std::string data_in;
			std::string temp;
			
			while (std::getline (in_file, temp)) {
				int line_len = temp.length();
				std::string ID_in_str = (temp.substr(0, 9));
				int ID_in = stoi(ID_in_str);
				data_in = temp.substr(10, line_len - 10);	
				record* new_record = new record(ID_in, data_in);
				table.insert(new_record); 
				delete new_record;
			}
		} else if (choice == 2) {
			std::cout << "input new record:" << '\n';	
			int ID_in;
			std::string data_in;
			std::string temp;
			std::getline (std::cin, temp);	
			int line_len = temp.length();
			if (line_len - 10 > 0) {
				std::string ID_in_str = (temp.substr(0, 9));
				ID_in = stoi(ID_in_str);
				data_in = temp.substr(10, line_len - 10);	
				record* new_record = new record(ID_in, data_in);
				table.insert(new_record); 
				delete new_record;
			}
		} else if (choice == 3) {
			//delete
			std::cout << "delete record - key? ";
			std::string str_key;
			std::getline(std::cin, str_key);
			int key = stoi(str_key);
			record* deletion = table.rec_delete(key);
			if (deletion) {
				std::cout << "Delete: " << std::setw(9) << std::setfill('0') << deletion->getID();  
				std::cout << " " << deletion->get_data() << '\n';
			} else {
				std::cout << "Delete not found: " << std::setw(9) << std::setfill('0') << key << '\n';
			}
			delete deletion;
		} else if (choice == 4) {
			// search
			std::cout << "search for record - key? ";
			std::string str_key;
			std::getline(std::cin, str_key);
			int key = stoi(str_key);
			record* retrieved = table.search(key);
			if (retrieved) {
				std::cout << "Found: " << std::setw(9) << std::setfill('0') << retrieved->getID();
				std::cout << " " << retrieved->get_data() << '\n';
			} else {
				std::cout << "Search not found: ";
				std::cout << std::setw(9) << std::setfill('0') << key << '\n';
			}
		} else if (choice == 5) {
			// clear
			table.clear();
			std::cout << "clearning hash table." << '\n';
		} else if (choice == 6) {
			//save

			std::cout << "write hash table - filename? ";
			std::string out_fname;
			std::getline(std::cin, out_fname); 
			std::ofstream out_file;
			out_file.open(out_fname.c_str());	
			if (out_file.fail()) { return 0; }
				
			out_file << table << '\n';

		}	
		else if (choice == 7) {
			// quit
			end = true;
		}
	}
/*
	for (int value: data) {
		std::cout << std::setw(9) << std::setfill('0') << value << '\n';
	}
*/
}

	
    
