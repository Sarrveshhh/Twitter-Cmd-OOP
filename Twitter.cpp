/*Twitter Clone*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

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

    //login logic
    void login(){
        //reading each line of file to check if username and password exists.
        fstream file;
        file.open("userLogin.txt", ios::in);
        if(file.is_open()){
            string line;
            bool userFound = false;
            while(getline(file, line)){

                //splitting the line into username and password.
                size_t spacePos = line.find(' ');
                string u = line.substr(0, spacePos);
                string p = line.substr(spacePos+1);

                if(u == this->username && p == this->password){
                    cout << "Login of " << this->username << " is successful!" << endl;
                    userFound = true;
                    break;
                }
            }
            //if could not find user.
            if(!userFound){
                cout << "Username not found! Check credentials and try again!" << endl;
            }

            file.close();
        }
        else{
            cout << "File did not open!. Try again!" << endl;
        }
    }

    void signup(){
        //checking if username already exits.
        fstream file;
        string line;
        bool userStored = false;
        bool userAlreadyExist = false;
        file.open("userLogin.txt", ios::in);
        if(file.is_open()){
            while(getline(file, line)){
                size_t spacePos = line.find(' ');
                string u = line.substr(0, spacePos);
                if(u == this->username){
                    cout << "Username already exits, please try different username!" << endl;
                    userAlreadyExist = true;
                    break;
                }
            }
            file.close();
        }
        else{
            cout << "File could not open, Try again!" << endl;
        }
        //appending usrname and password in file.
        if(!userAlreadyExist){
            file.open("userLogin.txt", ios::app);
            if(file.is_open()){
                file << this->username << " " << this->password << endl;
                userStored = true;
            }
            else{
                cout << "File could not open, Try again!" << endl;
            }
        }

        if(userStored){
            cout << "You have completed your registration! You can now login! Thank You!!" << endl;
        }
    }
};
int main(){
    bool isRunning = true;

    while(isRunning){
        cout << "***********HOME PAGE***********" << endl;
        cout << "1. Login" << endl;
        cout << "2. Signup" << endl;
        cout << "4. Exit App" << endl;
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
            isRunning = false;
            break;

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