#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool isLoggedIn(){
    string username, password, un, pw;
    cout << "Enter user name: "; cin >> username;
    cout << "Enter password: "; cin >> password;

    ifstream readFile("loggingfile.txt");
    getline(readFile, un);
    getline(readFile, pw);
    if ( un == username)
    {
        return true;
    }
    else return false;
}

int main(){
    int choice;
    cout << "1. Sign up\n2. Sign in\nEnter your choice: "; cin >> choice;
    bool n = true;
    
    if(choice == 1)
    {
        string username, password;
        cout << "Enter your username: "; cin >> username;
        cout << "Enter your password: "; cin >> password;
        ofstream readFile("loggingfile.txt");
        readFile << username <<"\n"<< password;
        readFile.close();
        main();
    }
    else if(choice == 2)
    {
        bool status = isLoggedIn();
        if(!status)
        {
            cout << "Wrong username or password"<<endl;
            system("pause");
            return 0;
        }
        else
        {
            cout << "Sign in completed"<< endl;
            system("pause");
            return 1;
        }
    }
    return 0;
}