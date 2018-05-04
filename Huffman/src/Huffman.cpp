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
	/*
	printOrder = read();
	vector<Node *> huffCode = build(printOrder);
	print(huffCode);
	*/
	printOrder = read();
	print(build(printOrder), printOrder);
}

Huffman::~Huffman() {
	printOrder.clear();
}

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
}

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
}

pair<int, int> Huffman::getSmallestIndexes(vector<Node *> input) {
	//smallest value's index
	int index1 = 0;
	//second smallest value's index
	int index2 = 1;

	//for every node in the vector, if the value of the current node is smaller than the current
	//smallest value, set the second smallest value to the smallest value and set the smallest value to
	//the current node

	for (int i = 2; i < input.size(); i++) {

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
}

vector<Node *> Huffman::build(vector<Node *> in) {

	//current working node list
	vector<Node *> currTrees = in;

	//current working indexes
	pair<int, int> indexes;

	//build the tree
	while (currTrees.size() != 1) {
		//find the indexes of the smallest two nodes
		indexes = getSmallestIndexes(currTrees);

		Node * n1 = currTrees.at(indexes.first);
		Node * n2 = currTrees.at(indexes.second);
		Node * newRoot = new Node(n1, n2);

		if (indexes.first > indexes.second) {
			currTrees.erase(currTrees.begin() + indexes.first);
			currTrees.erase(currTrees.begin() + indexes.second);
		} else {
			currTrees.erase(currTrees.begin() + indexes.second);
			currTrees.erase(currTrees.begin() + indexes.first);
		}

		currTrees.push_back(newRoot);
	}

	return currTrees;
}

vector<char> Huffman::getOrder(vector<Node *> in){

	vector<char> output;

	for(int i=0;i<in.size();i++){
		output.push_back(in.at(i)->getChar());
	}

	return output;
}

void Huffman::print(vector<Node *> treeIn, vector<Node *> orderIn) {
	vector<Node *> tree = treeIn;
	vector<pair<char, int>> code;



}
