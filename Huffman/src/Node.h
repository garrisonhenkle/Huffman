/*
 * Node.h
 *
 *  Created on: May 1, 2018
 *      Author: Garrison Henkle
 *      Purpose:	Creates nodes that allow for the storage of a character and its count data, as well
 *      			as provides for a means to form the nodes into trees.  Each node has a character,
 *      			count, blank status, left child, and right child variable.  Desgined for use in
 *      			the creation of Huffman codes.
 */

#ifndef NODE_H_
#define NODE_H_

class Node {
public:
	/**
	 * Constructor that allows for the creation of roots with no children
	 */
	Node(char, int);

	/**
	 * Constructor that allows for the creation of roots with children
	 */
	Node(char, int, Node *, Node *);

	/**
	 * Constructor that allows for the creation of blank dummy roots with just children
	 */
	Node(Node *, Node *);

	/**
	 * Default deconstructor
	 */
	virtual ~Node();

	/**
	 * Character variable getter and setter
	 */
	void setChar(char);
	char getChar();

	/**
	 * Value (aka count) variable getter and setter
	 */
	void setValue(int);
	int getValue();

	/**
	 * Left child getter and setter
	 */
	void setLeft(Node *);
	Node * getLeft();

	/**
	 * Right child getter and setter
	 */
	void setRight(Node *);
	Node * getRight();

	/**
	 * Blank variable getter and setter
	 */
	bool isBlank();
	void setBlank(bool);

private:
	//holds the character of the node
	char ch;

	//holds the value (aka count) of the node
	int value;

	//holds the left child of the node
	Node * left;

	//holds the right child of the node
	Node * right;

	//holds the blank variable of the node
	bool blank;

};

#endif /* NODE_H_ */
