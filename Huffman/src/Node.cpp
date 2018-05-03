/*
 * Node.cpp
 *
 *  Created on: May 3, 2018
 *      Author: garrison
 */

#include "Node.h"

Node::Node(char c, int i) {
	ch = c;
	value = i;
	blank = false;
}

Node::Node(char c, int i, Node * lNode, Node * rNode){
	ch = c;
	value = i;
	blank = false;
	left = lNode;
	right = rNode;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

