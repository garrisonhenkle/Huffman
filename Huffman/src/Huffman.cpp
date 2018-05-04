/*
 * Huffman.cpp
 *
 *
 *  Created on: May 1, 2018
 *  	Author: Garrison Henkle
 */

#include "Huffman.h"

//see header file
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

	return 0;
} //end main

//see header file
Huffman::Huffman(string in) {
	//set file location
	filename = in;

	//read the file
	printOrder = read();

	//print the tree in the same order it was given
	print(build(printOrder), getOrder(printOrder));
} //end constructor

//see header file
Huffman::~Huffman() {
	printOrder.clear();
	code.clear();
} //end deconstructor

//see header file
pair<char, int> Huffman::processLine(string in) {
	char outChar;
	int outCount;

	string currChar;
	string currCount;

	int currIndex = 0;

	while (currIndex < in.length()) {
		if (in[currIndex] == ' ') {
			break;
		} else {
			currChar += in[currIndex];
		}
		currIndex++;
	}

	currIndex++;

	while (currIndex < in.length()) {
		currCount += in[currIndex];
		currIndex++;
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
	outCount = atoi(currCount.c_str());

	//return the character and its count in a pair
	return make_pair(outChar, outCount);
} //end method processLine

//see header file
vector<Node *> Huffman::read() {

	//input file stream
	ifstream file;
	//string that holds lines of input text
	string input;

	//vector that holds the nodes for each input
	vector<Node *> output;
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
		output.push_back(new Node(processPair.first, processPair.second));
	}

	return output;
} //end method read

//see header file
pair<int, int> Huffman::getSmallestIndexes(vector<Node *> input) {
	//smallest value's index
	int index1 = 0;
	//second smallest value's index
	int index2 = 1;

	//for every node in the vector, if the value of the current node is smaller than the current
	//smallest value, set the second smallest value to the smallest value and set the smallest value to
	//the current node
	//if the current node is larger than the smallest but smaller than the second smallest, then replace
	//index2 to the current value
	for (int i = 2; i < input.size(); i++) {

		//at the beginning of each loop, make sure that the smallest is always in index 1
		if (input.at(index1)->getValue() > input.at(index2)->getValue()) {
			int temp = index1;
			index1 = index2;
			index2 = temp;
		}

		if (input.at(i)->getValue() <= input.at(index1)->getValue()) {
			index2 = index1;
			index1 = i;
		} else if (input.at(i)->getValue() <= input.at(index2)->getValue()) {
			index2 = i;
		}
	}

	return make_pair(index1, index2);
} //end method getSmallestIndexes

//see header file
vector<Node *> Huffman::build(vector<Node *> in) {

	//current working node list
	vector<Node *> currTrees = in;

	//current working indexes
	pair<int, int> indexes;

	//build the tree
	while (currTrees.size() != 1) {
		//find the indexes of the smallest two nodes
		indexes = getSmallestIndexes(currTrees);

		//n1 and n2 hold the smallest and second smallest nodes, respectively
		Node * n1 = currTrees.at(indexes.first);
		Node * n2 = currTrees.at(indexes.second);

		//combine the two smallest nodes into one tree
		Node * newRoot = new Node(n1, n2);

		//always delete the one later in the vector so it doesn't change where the second
		//deletion will occur
		if (indexes.first > indexes.second) {
			currTrees.erase(currTrees.begin() + indexes.first);
			currTrees.erase(currTrees.begin() + indexes.second);
		} else {
			currTrees.erase(currTrees.begin() + indexes.second);
			currTrees.erase(currTrees.begin() + indexes.first);
		}

		//push the new tree to the vector
		currTrees.push_back(newRoot);
	}

	return currTrees;
} //end method build

//see header file
vector<char> Huffman::getOrder(vector<Node *> in) {

	vector<char> output;

	//for all the nodes in the vector, compile the characters in order
	for (int i = 0; i < in.size(); i++) {
		output.push_back(in.at(i)->getChar());
	}

	return output;
} //end method getOrder

//see header file
void Huffman::print(vector<Node *> treeIn, vector<char> orderIn) {
	vector<Node *> tree = treeIn;

	string codeStr = "";

	//root of the tree
	Node * current = tree.at(0);

	//if there is a left child, recursively call on that child and add to the code string
	if (current->getLeft() != nullptr) {
		print(current->getLeft(), codeStr += "0");
	}
	//if there is a right child, recursively call on that child and add to the code string
	if (current->getRight() != nullptr) {
		print(current->getRight(), codeStr += "1");
	}

	//after the code vector has been filled, print all the values
	for (int i = 0; i < code.size(); i++) {
		cout << code.at(i).first << " " << code.at(i).second << endl;
	}

} //end method print

//see header file
void Huffman::print(Node * n, string codeString) {
	//if there is a left child, recursively call on that child and add to the code string
	if (n->getLeft() != nullptr) {
		print(n->getLeft(), codeString += "0");
	}
	//if there is a right child, recursively call on that child and add to the code string
	if (n->getRight() != nullptr) {
		print(n->getRight(), codeString += "1");
	}
	//if there is no children and it is not blank, add it to the list of codes
	//convert any strange characters to a readable form (i.e. space and nextline)
	if (n->isBlank() == false && n->getLeft() == nullptr
			&& n->getRight() == nullptr) {
		string temp;
		if (n->getChar() == ' ') {
			temp = "space";
		} else if (n->getChar() == '\n') {
			temp = "newline";
		} else {
			temp = n->getChar();
		}
		//add the pair of the character and string to list of codes
		code.push_back(make_pair(temp, codeString));
	}
} //end method print helper
