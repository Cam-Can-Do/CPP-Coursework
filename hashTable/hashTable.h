/*
Cameron Candau
main.cpp
Assignment #5 "Hash Table"
*/
#include <vector>
#include <string>
#include <iostream>

// abstract base class for data
//   also overload operator= if necessary
//   and/or copy constructor, destructor 
// clone method invokes copy constructor
// to make a copy of the object
class record{
public:
  record(int, std::string);
  int getID(); // or something similar 
  std::string get_data();
  record *clone(); // or something similar
  void operator=(record*);
  // anything else that you think is appropriate 
private:
// members to hold ID/key and data string
  int ID;
  std::string data;
};

class hashTable{
public:
  friend std::ostream &operator<<(std::ostream& out, hashTable &table_obj);
  hashTable(int size); // build a table
  void insert(record*); // insert copy of record
  record* rec_delete(int); // delete a record
  // return pointer to a copy of found record, or 0
  record* search(int); 
  void clear();
private:
  // find return value: some type of index
  record *find(int); // helper search fn
  int hash(record *); // hash value for record
  int hash(int); // hash value for key  
  int m; // size of table
  // array of m lists that hold records
  // other members as desired
  std::vector<std::vector<record>> table;
  const double c = .618034;
};

