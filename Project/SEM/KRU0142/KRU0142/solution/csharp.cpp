#include <sstream>
#include "csharp.hpp"


/**
 * @brief File containing functions that are C++ reproductions of native C# methods or are similar.
 * @file csharp.cpp
 * @author Dan Krupa
 */

/**
 * @brief Function reproducing C# ToLower method,which converts an entire string into a lowercase text.
 * @param text  Text to be converted.
*/

void ToLower(string& text)
{
    for(unsigned int i =0;i<text.length();i++)
    {
        text[i] = tolower(text[i]);
    }
}
/**
 * @brief Function the verifies that the text can be converted into number of type Unsigned Short (0,65535).
 * @param text  Text to be checked.
 * @return Returns TRUE or FALSE (IS or IS NOT convertible to unsigned short).
 */

bool IsUShort(const string text)
{
    if(text.length()>5)
    {
        return false;
    }
    for(unsigned int i =0;i<text.length();i++)
    {
        if(!isdigit(text[i]))
           {
               return false;
           }
    }
    return true;
}
/**
 * @brief Reproduction of C# method Convert.ToUInt16. Converts string value into unsigned short integer.
 * @param text  Text to be converted.
 * @return Returns the converted unsigned short value.
 */
unsigned short ToUShort(const string text)
{
    unsigned short number;
    stringstream memory(text);
    memory>>number;
    return number;
}
/**
 * @brief Reproduction of C# non-static method Split. Creates a list of strings extracted from the original string using the given delimiter.
 * @param text  Text to be converted.
 * @param delim Delimiting character.
 * @return Returns vector of the separated strings.
 */
vector<string> Split(const string text,const char delim)
{
    vector< int> indexes {-1};
    vector<string> splitted;
    string temp;
    for(unsigned int i =0;i<text.length();i++)
    {
        if(text[i]==delim)
        {
            indexes.push_back(i);
        }
    }
indexes.push_back(text.length());

    for(unsigned int i=0;i<indexes.size()-1;i++)
    {
        temp = text.substr(indexes[i]+1,indexes[i+1]-indexes[i]-1);
        splitted.push_back(temp);
    }

return splitted;

}

/**
 * @brief Function that verifies that the string is a tabulator separated line of Unsigned Short values.
 * @param text  Text to be checked.
 * @return Returns number of unsigned short values.If the line contains a non-uns.short value,returns -1.
 */

short UShortLineLength(const string text)
{
   vector<string> line=  Split(text,'\t');
    for(unsigned int i = 0;i<line.size();i++)
    {
        if(!IsUShort(line[i]))
        {
            return -1;
        }
    }
    return line.size();





}

/**
 * @brief Function that reproduces vector method push_back of C++ and also the Add method from List class of C#.Adds an element at the end of a dynamic array. Function is type-overloaded.Uses special structure containing a dynamic array and its size,not an array itself.
 * @param vect Array to which the element should be added.
 * @param newroom Element to be added to array.Type overloaded.
 */


void PushBack(vectorroom& vect,room newroom)
{

     if(vect.size>0)
    {
        room* newar = vect.arroom;
        vect.size++;
        //delete[] vect.arroom;
        vect.arroom=new room[vect.size];
        copy(newar,newar+vect.size-1,vect.arroom);
        vect.arroom[vect.size-1]=newroom;
        delete[] newar;
        newar = nullptr;
    }
    else
    {
        vect.size=1;
       vect.arroom = new room[vect.size];
       vect.arroom[0]=newroom;
    }



}

/**
 * @brief Function that reproduces vector method push_back of C++ and also the Add method from List class of C#.Deletes element from given index from the array. Function is type-overloaded.Uses special structure containing a dynamic array and its size,not an array itself.
 * @param vect Array from which the element should be removed.
 * @param delroom   index of the element that should be deleted.
 */

void Erase(vectorroom& vect,int delroom)
{
    if(vect.size==1)
    {
//        delete[] vect.arroom;
        vect.arroom=nullptr;
        vect.size--;
        return;
    }
    else if(vect.size>1)
    {

        int i;
        for(i=delroom;i<vect.size-1;i++)
        {
            vect.arroom[i]=vect.arroom[i+1];
        }
        vect.arroom[i]={0,0,0,0,0};
        room* newar = vect.arroom;
        vect.size--;
        vect.arroom=new room[vect.size];
        copy(newar,newar+vect.size,vect.arroom);
        delete[] newar;
        return;
    }
}

/**
 * @brief Function that reproduces vector method push_back of C++ and also the Add method from List class of C#.Adds an element at the end of a dynamic array. Function is type-overloaded.Uses special structure containing a dynamic array and its size,not an array itself.
 * @param vect  Array to which the element should be added.
 * @param newreg    Element to be added to array.Type overloaded.
 */

void PushBack(vectorreg& vect,reg newreg)
{

     if(vect.size>0)
    {
        reg* newar = vect.arreg;
        vect.size++;
        //delete[] vect.arreg;
        vect.arreg=new reg[vect.size];
        copy(newar,newar+vect.size-1,vect.arreg);
        vect.arreg[vect.size-1]=newreg;
        delete[] newar;
        newar = nullptr;
    }
    else
    {
        vect.size=1;
       vect.arreg = new reg[vect.size];
       vect.arreg[0]=newreg;
    }



}

/**
 * @brief Function that reproduces vector method push_back of C++ and also the Add method from List class of C#.Deletes element from given index from the array. Function is type-overloaded.Uses special structure containing a dynamic array and its size,not an array itself.
 * @param vect Array from which the element should be removed.
 * @param delreg   index of the element that should be deleted.
 */

void Erase(vectorreg& vect,int delreg)
{
    if(vect.size==1)
    {
        delete[] vect.arreg;
        vect.arreg=nullptr;
        vect.size--;
        return;
    }
    else if(vect.size>1)
    {

        int i;
        for(i=delreg;i<vect.size-1;i++)
        {
            vect.arreg[i]=vect.arreg[i+1];
        }
        vect.arreg[i]={0,"0.0.0000"};

//WriteVec(vect);

    reg* newar = vect.arreg;

vect.size--;
//cout<<"S"<<vect.size<<endl;
//delete[] vect.arreg;
vect.arreg=new reg[vect.size];



copy(newar,newar+vect.size,vect.arreg);
    delete[] newar;
    return;
    }
}

