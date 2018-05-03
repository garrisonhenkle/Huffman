/*
 * Tree.h
 *
 *  Created on: May 3, 2018
 *      Author: garrison
 */



#ifndef TREE_H_
#define TREE_H_

#include <string>
#include <vector>
#include "Node.h"

using namespace std;

class Tree {
public:
	Tree();
	virtual ~Tree();
private:
	Node * root;
};

#endif /* TREE_H_ */
