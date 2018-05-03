/*
 * Huffman.cpp
 *
 *  Created on: May 3, 2018
 *      Author: garrison
 */

#include "Huffman.h"

int main(int argc, char* argv[]) {

	string filenameIn;

	//if there is two command line arguments, assign the filename variable
	if (argc == 2) {
		filenameIn = argv[1];
		//if argc != 2, then give an error and exit
	} else {
		cerr << "Invalid amount of arguments.  Please see the readme.txt"
				<< endl;
		return 1;
	}

	//create the Huffman object
	//This creates the Huffman code and prints it to the screen
	Huffman * h = new Huffman(filenameIn);

	//delete all pointers
	delete h;
}

Huffman::Huffman(string in) {
	//set file location
	filename = in;
	printOrder = read();
	cout << "read worked" << endl;
	build(printOrder);
	cout << "build worked" << endl;
	print();
}

Huffman::~Huffman(){
	printOrder->clear();
	delete printOrder;
}

pair<char, int> Huffman::processLine(string in) {
	char outChar;
	int outCount;

	string currChar;
	string currCount;

	//from index 0 to the space, add all characters to a string
	//at the space, add all characters from (index of the space + 1) to the end of the line
	//then break from both loops
	for (int i = 0; i < in.length(); i++) {
		if (in[i] != ' ') {
			currChar += in[i];
		} else {
			for (int j = (i + 1); j < in.length(); j++) {
				if (in[i] != '\n') {
					currCount += in[i];
				} else {
					break;
				}
			}
			break;
		}
	}

	//Convert any characters in text form (i.e space instead of ' ')
	//If it is not in text form, the first index of the string is the character
	if (currChar == "space") {
		outChar = ' ';
	} else if (currChar == "newline") {
		outChar = '\n';
	} else {
		outChar = currChar[0];
	}

	//convert the currCount string into the integer count of the character
	outCount = stoi(currCount);

	//return the character and its count in a pair
	return make_pair(outChar, outCount);
}

vector<Node *> * Huffman::read() {

	//input file stream
	ifstream file;
	//string that holds lines of input text
	string input;

	//vector that holds the nodes for each input
	vector<Node *> * output;
	//temporary pair holder
	pair<char, int> processPair;

	//tries to open the file, exits if it cannot open it
	file.open(filename);
	if (!file) {
		cerr << "Unable to open input file";
		exit(1);
	}

	//for every available line, store the character and its count
	while (getline(file, input)) {

		//process the line into a character and a count (int) and store in a holder
		processPair = processLine(input);

		//create a new node using the process output and push it to the node vector
		output->push_back(new Node(processPair.first, processPair.second));
		cout << "Char: " << processPair.first << ", Count: "
				<< processPair.second << endl;
	}

	return output;
}

void build(vector<Node *> input){
	for(Node n: input){
		cout << n.getChar() << " : " << n.getValue() << endl;
	}
}
