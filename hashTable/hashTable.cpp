/*
Cameron Candau
hashTable.cpp
Assignment #5 "Hash Table"
*/

#include <vector>
#include <iomanip>
#include "hashTable.h"

// operator= overloading for copying records
void record::operator=(record* that) {
	this->ID = that->ID;
	this->data = that->data;
}


// record constructor provided an ID and data
record::record(int ID_in, std::string data_in) {
	ID = ID_in;
	data = data_in;
}

// returns ID integer
int record::getID() { // or something similar 
	return ID;
}

// returns data string
std::string record::get_data() {
	return data;
}

// builds an empty hash table
hashTable::hashTable(int size){ 
	int actual_size = (size > 0) ? size : 100;
		table.resize(actual_size);
		m = actual_size;
}	

// inserts a copy of a record into the hash table
void hashTable::insert(record* insertion){ 
	int this_ID = insertion->getID();
	std::string this_data = insertion->get_data();
	int index = hash(this_ID);
	table[index].push_back(record(this_ID, this_data));
}

// returns pointer to copy of found record, or 0 
record* hashTable::search(int ID) {
	int index = hash(ID);
	int size = table[index].size();
	for (int i = 0; i < size; ++i) {
		if ((table[index][i]).getID() == ID) {
			return &(table[index][i]);
		}	
	}
	return 0;
}

// void hashTable::delete_rec(int); // delete a record
// return pointer to a copy of found record, or 0
record* hashTable::rec_delete(int ID) {
	int index = hash(ID);
	int size = table[index].size();
	//if (size == 0) return 0;
	for (int i = 0; i < size; ++i) {
		if ((table[index][i]).getID() == ID) {
			record* del_rec = new record(ID, table[index][i].get_data());
			//if (i != size - 1 && i != 0) {
			table[index][i] = table[index][size-1];
			table[index][size-1] = del_rec;	
			//}
			table[index].pop_back();
			return del_rec; 
		}
	}
	return 0;
}

// clears hash table 
void hashTable::clear() {
	for (int i = 0; i < m; ++i) {
		table[i].clear();	
	}	
}


// find return value: some type of index
//record* hashTable::find(int); // helper search fn
int hashTable::hash(record* rec) { // hash value for record
	return hash(rec->getID());
}
int hashTable::hash(int k) { // hash value for key  
	double kc = k * c;
	return (int)(m * (kc - (int)(kc)));	
}

// returns ostream with contents of hash table, one ID/data pair per line
std::ostream& operator<<(std::ostream &out, hashTable &table_obj) {
	int table_size = table_obj.table.size();
	bool first = true;
	for (int i = 0; i < table_size; ++i) {
		int subtable_size = table_obj.table[i].size();
		for (int j = 0; j < subtable_size; ++j) {
			if (first) {
				first = false;
			} else {
				out << '\n';
			}
			out << std::setw(9) << std::setfill('0') << (table_obj.table[i][j].getID()) << " ";
			out << (table_obj.table[i][j].get_data());
		}
	}
	return out;
}





