/*
 * Huffman.h
 *
 *  Created on: May 3, 2018
 *      Author: garrison
 */

#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Node.h"

using namespace std;

class Huffman {
public:
	Huffman(string);
	~Huffman();

	vector<Node *> read();
	void build(vector<Node *>);
	void print();
private:
	pair<char, int> processLine(string);

	vector<Node *> printOrder;
	string filename;
};

#endif /* HUFFMAN_H_ */
