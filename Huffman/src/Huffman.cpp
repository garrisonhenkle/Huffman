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
	Huffman * h = new Huffman(filenameIn);

	//delete all pointers
	delete h;
}

Huffman::Huffman(string in) {
	//set file location
	filename = in;
	build(read());
}

pair<char, int> Huffman::processLine(string in) {
	char outChar;
	int outCount;

	string currChar;
	string currCount;

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

	if (currChar == "space") {
		outChar = ' ';
	} else if (currChar == "newline") {
		outChar = '\n';
	} else {
		outChar = currChar[0];
	}

	outCount = stoi(currCount);

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

		processPair = processLine(input);
		output.push_back(new Node(processPair.first, processPair.second));
	}

	return output;
}
