#include<string>
#include<iostream>
#include<fstream>
// #include "../HeaderFile/fileHandling.h"
using namespace std;
bool appendCredentials(string username, string password){
    fstream file;
    file.open("userLogin.txt", ios::app);
    if(file.is_open()){
        file << username << " " << password << endl;
        file.close();
        return true;
    }
    else{
        cout << "Error in opening the database! Try again later" << endl;
        return false;
    }
}

bool alreadyExisits(string username){
    fstream file;
    string line;
    file.open("userLogin.txt", ios::in);
    if(file.is_open()){
        while(getline(file, line)){
            size_t spacePos = line.find(' ');
            string u = line.substr(0, spacePos);
            if(u == username){
                return true;
            }
        }
        file.close();
        return false;
    }
    else{
        cout << "Error in opening the database! Try again later" << endl;
        return false;
    }
}

bool checkCredentials(string username, string password){
    fstream file;
    file.open("userLogin.txt", ios::in);
    if(file.is_open()){
        string line;
        while(getline(file, line)){

            //splitting the line into username and password.
            size_t spacePos = line.find(' ');
            string u = line.substr(0, spacePos);
            string p = line.substr(spacePos+1);
                
            if(u == username && p == password){
                return true;
            }

            // file.close();
        }
        file.close();
        return false;
    }
}