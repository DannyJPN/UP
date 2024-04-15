#ifndef STDOUT
#define STDOUT
#include <vector>
#include "database.hpp"
using namespace std;
void WriteRoom(const room);
void WriteReg(const reg);
void WriteVector(const vectorroom);
void WriteVectorAdvancedFilter(const vectorroom,const vectorreg ,string[],const unsigned short);
void WriteVectorFilter(const vectorroom,const string,unsigned short,unsigned short);
void WriteVectorFilter(vectorreg ,const string,string&,string&);
void WriteVector(const vectorreg );
void WriteVector(const vector<string>);
void WriteRegFile(vectorreg ,bool ,const string,const string,const string,const string);



#endif // STDOUT




