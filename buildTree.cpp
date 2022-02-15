#ifndef BUILDTREE_C
#define BUILDTREE_C

#include "buildTree.h"
#include <fstream>

Node *newNode(string input){
    Node *newNode = new Node();
    newNode->input = input;
    newNode->lastChar = input.back();
    newNode->left = newNode ->right = NULL;
    return newNode;
}

Node *insert(Node* root, string word){
    if(root == NULL){
        root = newNode(word);
    }
    else if(word.back() <= root->lastChar){
        root->left = insert(root->left, word);
    }
    else{
        root->right = insert(root->right, word);
    }
    return root;
}

Node *buildTree(string fileName){
    ifstream file(fileName);
    Node *root = NULL;
    string word;

    while(file >> word){
        if(root == NULL){
            root = newNode(word);
        }
        else if(word.back() <= root->lastChar){
            root->left = insert(root->left,word);
        }
        else{
            root-> right = insert(root->right,word);
        }

    }

    return root;    
}



#endif