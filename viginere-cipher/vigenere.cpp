//Cameron Candau
//CS11 Assignment 8
//Purpose: Allows the user to either encrypt or decrypt a message using the Vigenere Cipher and a keyword.

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//class for using a Vigenere cipher to encrypt or decrypt a message
//Vigenere objects must be created with a shift key, the value to use 
class Vigenere{
public:
	Vigenere(string);
	string encrypt(string);
	string decrypt(string);
	
private:
	char shift(char, int);
	string shkey;
	int shamt;
	//used to store the current position within the keyword
	int key_index;
};

//constructor function for Vigenere class, initializes data members
Vigenere::Vigenere(string user_shkey){
	shamt = 0;
	shkey = user_shkey;
	key_index = 0;
}

// accepts plaintext from user input and using the shift keyword, generates a shift amount for each position of the shift key and applies it to the current character in the plaintext.
// returns the ciphered version of the plaintext as a string.
string Vigenere::encrypt(string plaintext){
	string ciphertext = "";
	
	int plain_size = plaintext.size();
	int shkey_size = shkey.size();

	for (int i = 0; i < plain_size; i++){
		
		if (key_index > shkey_size - 1){
			key_index = 0;
		}
		shamt = shkey[key_index]-'A';
		ciphertext = ciphertext + shift(plaintext[i], shamt);
		key_index++;
	}
	return ciphertext;
}

// accepts ciphertext from user input and using the shift keyword, generates a shift amount for each position of the shift key and applies the negative shift amount to 
//the current character in the plaintext, reversing the original shift applied.
//returns the plaintext version of the ciphertext as a string.
string Vigenere::decrypt(string ciphertext){
	string plaintext = "";
	int size = ciphertext.size();
	int shkey_size = shkey.size();
	
	for (int i = 0; i < size; i++){
		if (key_index > shkey_size - 1){
			key_index = 0;
		}
		
		shamt = shkey[key_index]-'A';
		plaintext = plaintext + shift(ciphertext[i], -shamt);
		key_index++;
	}
	return plaintext;
}


//subtracts 'A' from the current character (which is already a capital letter) so that we are working with digits 0-25 representing our capital alphabet instead of the 
//actual ASCII values temporarily, and adds the shift amount. 
//Then, we add 'A' back to the character, bringing us back to the actual ASCII values we want, and returns that character.
char Vigenere::shift(char c, int shamt){
	int result = (c-'A'+shamt);
	
	if (result >= 26){
		result = result - 26;
	}
	else if (result < 0){
		result = result + 26;
	}
	
	return result + 'A';
}

//Converts text in a string to all uppercase letters and returns that new string without whitespace, punctuation, numbers, or other non-alpha characters
string simplify(string text){
	string simplified = "";
	int size = text.size();
	for (int i = 0; i < size; i++){
		if (isalpha(text[i])){
			simplified = simplified + (char) toupper(text[i]);
		}
	}
	return simplified;
}


//Allows the user to specify the encryption option and shift keyword in the argument variables when running the program, and then enter a message
// (or redirect input/output from or to a file containing a message or a blank file to write it to) to be encrypted or decrypted (whichever was indicated when running the program).
int main(int argc, char *argv[]){

	if (argc < 3){
		cerr << "USAGE: " << argv[0] << " -d|e shiftKeyword" << endl;
		exit(1);
	}

	string user_shkey = argv[2];
	
	bool encrypt;
	string option(argv[1]);
	string line;
	string encodedLine;
	
	if (option == "-e"){
		encrypt = true;}
	else {encrypt = false;}
	
	Vigenere cipher(simplify(user_shkey));
	
	while (getline(cin, line)){
		if (encrypt){
			encodedLine = cipher.encrypt(simplify(line));
		}
		else {
			encodedLine = cipher.decrypt(line);
		}
	cout << encodedLine << endl;
	}
	return 0;
}
