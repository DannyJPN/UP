#include <iostream>
#include "security.hpp"


using namespace std;

/**
 * @brief Security functions file. Should be submitted to further development.
 * @file security.cpp
 * @author Dan Krupa
 */

/**
 * @brief Authentication function. Causes login dialog and verifies credentials.
 * @param prompt System commandline prompt. Used as the prompt changes according to the identity of the logged-in user.
 */
bool Authenticate(string& prompt)
{

    string username,password;
cout<<"Login: ";
    getline(cin,username,'\n');
    cout<<"Password: ";
    getline(cin,password,'\n');

    if(password == "pass"&&username == "admin")
        {
        prompt=username+"#";
            return true;
        }
    else if(password == "letmein"&&username == "guest")
        {
        prompt=username+"#";
            return true;
        }
    return false;
}
