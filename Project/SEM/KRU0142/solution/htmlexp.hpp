#ifndef HTML
#define HTML
#include "database.hpp"



using namespace std;
void ExportVectorAdvancedFilter(const vectorroom,const vectorreg ,string[],const unsigned short);
void ExportVectorFilter(const vectorroom,const string,unsigned short,unsigned short);
void ExportVectorFilter(const vectorreg ,const string,string&,string&);
void ExportVector(const vectorroom);
void ExportVector(const vectorreg );
string RoomHtml(const room);
string RegHtml(const reg);
#endif // HTML
