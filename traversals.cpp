#ifndef TRAVERSALS_CPP
#define TRAVERSALS_CPP

#include "traversals.h"

void traversePreOrder(Node *root){
    if(root == NULL)
        return;

    cout << "String: " << root->input << " ; last character: " << root->lastChar << endl;
    traversePreOrder(root->left);
    traversePreOrder(root->right);
}

void traversePostOrder(Node *root){
    if (root == NULL){
        return;
    }
    traversePostOrder(root->left);
    traversePostOrder(root->right);
    cout << "String: " << root->input << " ; last character: " << root->lastChar << endl;
}

void printCurrentLevel(Node* root, int level){
    if(root == NULL){
        return;
    }
    if(level == 1){
        cout << "String: " << root->input << " ; last character: " << root->lastChar << endl;
    }
    else if(level > 1){
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level -1);
    }
}


void traverseLevelOrder(Node *root){
    int h = height(root);
    for(int i =1; i <= h; i++){
        printCurrentLevel(root, i);
    }
}

int height(Node *root){
    if(root == NULL)
        return 0;
    else{
        int lheight = height(root->left);
        int rheight = height(root->right);
        
        if(lheight > rheight) {
            return (lheight + 1);
        }
        else{
            return (rheight + 1);
        }
    }
}
#endif