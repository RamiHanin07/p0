#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
using namespace std;

struct Node {
    char lastChar;
    string input;
    vector<string> stringList();
    struct Node *left, *right;
};

int height(Node *node);
#endif