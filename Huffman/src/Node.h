/*
 * Node.h
 *
 *  Created on: May 3, 2018
 *      Author: garrison
 */

#ifndef NODE_H_
#define NODE_H_

class Node {
public:
	Node(char, int); //Node(int value, char c)
	Node(char, int, Node *, Node *);
	Node(Node *, Node *);
	virtual ~Node();

	void setChar(char);
	char getChar();

	void setValue(int);
	int getValue();

	void setLeft(Node *);
	Node * getLeft();

	void setRight(Node *);
	Node * getRight();

	bool isBlank();
	void setBlank(bool);


private:
	char ch;
	int value;

	Node left;
	Node right;

	bool blank;

};

#endif /* NODE_H_ */
