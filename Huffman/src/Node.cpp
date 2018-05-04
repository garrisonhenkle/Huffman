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
	left = nullptr;
	right = nullptr;
}

Node::Node(char c, int i, Node * lNode, Node * rNode){
	ch = c;
	value = i;
	blank = false;
	left = lNode;
	right = rNode;
}

Node::Node(Node * lNode, Node * rNode){
	ch = 'A';
	value = lNode->getValue() + rNode->getValue();
	blank = true;
	left = lNode;
	right = rNode;
}

Node::~Node() {
	delete left;
	delete right;
}

void Node::setChar(char in){
	ch = in;
}

char Node::getChar(){
	return ch;
}


void Node::setValue(int in){
	value = in;
}

int Node::getValue(){
	return value;
}

void Node::setLeft(Node * in){
	left = in;
}

Node * Node::getLeft(){
	return left;
}

void Node::setRight(Node * in){
	right = in;
}

Node * Node::getRight(){
	return right;
}

bool Node::isBlank(){
	if(blank == true){
		return true;
	} else{
		return false;
	}
}

void Node::setBlank(bool in){
	blank = in;
}
