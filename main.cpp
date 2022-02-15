//Name: Rami Hanin
//Date: 1/26/2022
//Class: CS4280

#include <iostream>
#include <fstream>
#include <string>

#include "node.h"
#include "buildTree.h"
#include "traversals.h"

using namespace std;


int main(int argc, char *argv[]){

    //Variables
    string fileName = "";


    //Extracting command line arguments
    string argument = "";
    if(argv[1]){
        //cout << argv[1] << " arg" << endl;
        argument = string(argv[1]);
    }
    cout << argument << endl;

    //Dealing with command line argument conditionals
    if(argument != ""){
        if(argument != ">"){
            fileName = argument;
        }
        if(argument == ">"){
            fileName = string(argv[2]);
        }
        else{
            cout << "Error, unidentified argument" << endl;
        }
    }

    //cout << fileName << " ; fileName" << endl;

    //Handling input from keyboard
    if(fileName == ""){
        cout << "No file name specified, please type on keyboard" << endl;
        cout << "All input must be in the form of lowercase letters, no symbols or numbers" << endl;
        cout << "Once you are finished, please press control + D and then the Enter Key" << endl;

        ofstream OutFile("input.txt");
        string input;
        getline(cin, input);
        OutFile << input;
        OutFile.close();
        ifstream InFile("input.txt");
        input = "";
        getline(InFile, input);
        // cout << input << "from file" <<endl;

        fileName = "input.txt";
        InFile.close();
    }

    //cout << fileName << " ; fileName" << endl;

    //Check to see if input is all lowercase characters.

    ifstream InFile(fileName);
    string checkRequirements;
    while(InFile >> checkRequirements){
        bool isAlpha = true;
        for(int i = 0; i < checkRequirements.length(); i++){
            cout << checkRequirements[i] << " checkreq " << i << endl;
            cout << isalpha(checkRequirements[i]) << " ; isAlpha" << endl;
            if(isalpha(checkRequirements[i]) < 1){
                isAlpha = false;
                i = checkRequirements.length();
            }
        }
        if(isAlpha == false){
            cout << "Input contained non letters, aborting program" << endl;
            return 0;
        }

        bool isLower = true;
        for(int i = 0; i < checkRequirements.length(); i++){
            if(islower(checkRequirements[i]) < 1){
                isLower = false;
                i = checkRequirements.length();
            }
        }
        if(isLower == false){
            cout << "Input contained non lowercase letters, aborting program" << endl;
            return 0;

        }

    }
    
    //build the tree, then traverse the tree.
    Node* root = NULL;
    root = buildTree(fileName);


    //Output
    cout << "Binary Search Tree: Traverse Pre Order" << endl;
    traversePreOrder(root);
    cout << "" << endl;
    cout << "Binary Search Tree: Traverse Post Order" << endl;
    traversePostOrder(root);
    cout << "" << endl;
    cout << "Binary Search Tree: Traverse Level Order" << endl;
    traverseLevelOrder(root);

    

    return 0;
}