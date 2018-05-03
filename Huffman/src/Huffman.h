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
	vector<Node *> read();
	void build(vector<Node *>);
	pair<char, int> processLine(string);
	void print();
private:
	string filename;
	vector<pair<char, int>> printOrder;
};

#endif /* HUFFMAN_H_ */
