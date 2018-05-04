/*
 * Node.cpp
 *
 *  Created on: May 1, 2018
 *      Author: Garrison Henkle
 */

#include "Node.h"

//see header file
Node::Node(char c, int i) {
	//set the data variables to the input data
	ch = c;
	value = i;
	//since there is input data, the node is not blank
	blank = false;
	//this is a root so there is no children yet
	left = nullptr;
	right = nullptr;
} //end constructor Node(char, int)

//see header file
Node::Node(char c, int i, Node * lNode, Node * rNode) {
	//set the data variables to the input data
	ch = c;
	value = i;
	//since there is input data the node is not blank
	blank = false;
	//set the children variables to the input nodes
	left = lNode;
	right = rNode;
} //end constructor Node(char, int, Node*, Node*)

//see header file
Node::Node(Node * lNode, Node * rNode) {
	//the character variable can be set to any dummy value
	ch = 'A';
	//the value is set to the sum of the childrens' values
	value = lNode->getValue() + rNode->getValue();
	//this is a dummy node that has no character of its own
	blank = true;
	//left and right children are set to the input nodes
	left = lNode;
	right = rNode;
} //end constructor Node(Node, Node)

//see header file
Node::~Node() {
	delete left;
	delete right;
} //end deconstructor

//see header file
void Node::setChar(char in) {
	ch = in;
} //end setChar

//see header file
char Node::getChar() {
	return ch;
} //end getChar

//see header file
void Node::setValue(int in) {
	value = in;
} //end setValue

//see header file
int Node::getValue() {
	return value;
} //end getValue

//see header file
void Node::setLeft(Node * in) {
	left = in;
} //end setLeft

//see header file
Node * Node::getLeft() {
	return left;
} //end getLeft

//see header file
void Node::setRight(Node * in) {
	right = in;
} //end setRight

//see header file
Node * Node::getRight() {
	return right;
} //end getRight

//see header file
bool Node::isBlank() {
	if (blank == true) {
		return true;
	} else {
		return false;
	}
} //end isBlank

//see header file
void Node::setBlank(bool in) {
	blank = in;
} //end setBlank
