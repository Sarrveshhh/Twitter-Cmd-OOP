/*Twitter Clone*/
#include<iostream>
#include<fstream>
#include<string>
//for data type time_t.
#include<ctime>

//user defined preprocessor directives
#include "HeaderFile/fileHandling.h"
using namespace std;

class Tweet{
    private:
    string content;
    string author;
    time_t timestamp;

    public:
    Tweet(string content, string user){
        this->content = content;
        this->author = user;  
        this->timestamp = time(nullptr);
    }



    //getter for tweet properties;
    string getContent(){
        return this->content;
    }

    string getAuthor(){
        return this->author;
    }

    time_t getTimestamp(){
        return this->timestamp;
    }


};

class User{
    private:
    string username;
    string password;
    int followCount;
    int followingCount;

    public:
    User(string username, string password){
        this->username = username;
        this->password = password;
        followCount = 0;
        followingCount = 0;
    };

    void changePassword(){
        string username = this->username;
        string p;
        cout << "Enter new password" << endl;
        cin >> p;
        this->password = p;
        int flag = 0;
        fstream file;
        std::string line;
        string searchString = this->username;
        file.open("userLogin.txt", ios::in);
        if(file.is_open()){
            while (getline(file, line)) {
            size_t spacePos = line.find(' ');
            string u = line.substr(0, spacePos);
            // string p = line.substr(spacePos+1);
            // cout << u << endl;
        if (u == searchString) {
            cout << "string found!" << endl;
            file << u + ' ' + p << endl;
            flag = 1;
        }
    }
        if(flag != 1)
            cout << "String not found!" << endl;
        }

        file.close();
    file.open("userLogin.txt", ios::app);

    if(file.is_open()){
        file << this->username + " "+ p << endl;

    }

        else{
            cout << "Please try again!" << endl;
        }

    }
    void login(){
        //function written in fileHandling.cpp
        bool ans = checkCredentials(this->username, this->password);
        if(ans){
            cout << "You have successfully signed in! You can now Tweet" << endl;
        }
        else{
            cout << "Login fail, please check credentials!" << endl;
        }
    }

    void signup(){
        //checking if username already exists.
        bool userExisits = alreadyExisits(this->username);
        if(userExisits){
            cout << "Username already taken! Please try another username." << endl;
        }
        else{
            // append username and password in file.
            bool addedUser = appendCredentials(this->username, this->password);
            if(addedUser){
                cout << "Your signup is successfull, You can now Login!" << endl;
            }
            else{
                cout << "Error in creating account, try again later!" << endl;
            }
        }
    }
};
int main(){
    bool isRunning = true;

    while(isRunning){
        cout << "***********HOME PAGE***********" << endl;
        cout << "1. Login" << endl;
        cout << "2. Signup" << endl;
        cout << "3. Exit App" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string passW;
            string userN;
            cout << "Enter your username: " << endl;
            cin >> userN;
            cout << "Enter your password: " << endl;
            cin >> passW;
            User u(userN, passW); // constructor.
            u.login();
            break;
        }
        case 2:
        {
            string username;
            string password;
            cout << "Enter your username: " << endl;
            cin >> username;
            cout << "Enter your password: " << endl;
            cin >> password;
            User u(username, password);
            u.signup();
            break;
        }
        case 3:
        {
            isRunning = false;
            break;
        }
        default:
            cout << "Invalid choice. Please try again!" << endl;
            break;
        }

    }


    // singloton patter
    // Twitter t;
    // t.run();
    return 0;
}