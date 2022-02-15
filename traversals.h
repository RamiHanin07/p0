#ifndef TRAVERSALS_H
#define TRAVERSALS_H

#include "node.h"
#include <iostream>
using namespace std;
void traversePreOrder(Node *root);
void traversePostOrder(Node *root);
void traverseLevelOrder(Node *root);
void printCurrentLevel(Node* root, int level);




#endif