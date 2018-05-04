/*
 * Huffman.h
 *
 *  Created on: May 1, 2018
 *      Author: Garrison Henkle
 *      Purpose: 	Creates Huffman codes from an input file of characters and their occurrence count.
 *  				Contains all methods and their helper methods for the reading of files,
 *  				the building of Huffman code trees, and the printing of the tree to the screen.
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
	/**
	 * Creates and prints the Huffman code for the input file given by the input string
	 */
	Huffman(string);

	/**
	 * Default deconstructor
	 */
	~Huffman();

	/**
	 * Reads the file and collects all the characters and their corresponding counts
	 *
	 * Stores the characters and counts in tree nodes, then returns the vector of nodes
	 */
	vector<Node *> read();

	/**
	 * Builds the Huffman code by building a tree from the input vector of nodes
	 *
	 * Returns a vector with a single element, which is the root of the Huffman code tree
	 */
	vector<Node *> build(vector<Node *>);

	/**
	 * Prints the Huffman code tree to the screen
	 *
	 * Recursively calls the helper method to traverse the left and right children of each node
	 */
	void print(vector<Node *>, vector<char>);

	/**
	 * Helper method for the print method
	 *
	 * Allows for the storage of the characters and their corresponding Huffman codes
	 */
	void print(Node *, string);
private:
	/**
	 * Processes a line of text, given by the input string to derive a character
	 * and its corresponding count
	 *
	 * Returns the character and count in a pair<string, int>
	 */
	pair<char, int> processLine(string);

	/**
	 * Finds the indexes of the nodes with the smallest and second smallest values in the input vector
	 *
	 * Returns the indexes in a pair<int, int>, where the first int is the smallest and the second is the
	 * second smallest
	 */
	pair<int, int> getSmallestIndexes(vector<Node *>);

	/**
	 * Pulls the characters from a vector of nodes while maintaining their original order
	 */
	vector<char> getOrder(vector<Node *>);

	vector<pair<string, string>> code; //holds the character in first and its corresponding huffman code in second
	vector<Node *> printOrder; //holds the input data in Node form with original ordering
	string filename; //holds the file to be parsed
};

#endif /* HUFFMAN_H_ */
