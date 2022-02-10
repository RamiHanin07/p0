//Name: Rami Hanin
//Date: 1/26/2022
//Class: CS4280

#include <iostream>
#include <fstream>
#include <string>

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
    }

    cout << fileName << " ; fileName" << endl;

    return 0;
}