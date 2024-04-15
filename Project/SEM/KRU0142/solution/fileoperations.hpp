#ifndef FILEOPER
#define FILEOPER
#include <string>
#include "database.hpp"
using namespace std;
bool VerifyFile(const string);
void CopyFile(const string,const string,const string,const string,const string,const string);
vectorreg LoadRegFile(string&,const string,const string,const string,const string);
vectorroom LoadRoomFile(string&,const string,const string,const string,const string);


#endif // FILEOPER
