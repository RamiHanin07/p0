#ifndef BUILDTREE_H
#define BUILDTREE_H

#include "node.h"

Node *buildTree(string fileName);
Node *newNode(string input);
Node *insert(Node* root, string word);

#endif