#ifndef DATABASE
#define DATABASE
#include <string>





using namespace std;


/** @struct room
 *  @brief Structure containing information about a room entity
 *  @param id            Unique ID of a room.
 *  @param floor         Floor on which the room resides.
 *  @param number        Unique 4-digit number of the room.
 *  @param seats         Number of seats in the room.
 *  @param cost          Daily cost of the room.
 */
struct room
{

unsigned short    id;
unsigned short    floor;
unsigned short    number;
unsigned short    seats;
unsigned short    cost;

};

/** @struct reg
 *  @brief Structure containing information about a registration entity
 *  @param id            ID of a registered room.
 *  @param date          Date on which the rooms is registered.
 */
struct reg
{
unsigned short id;
string date;
};
/** @struct vectorreg
 *  @brief Structure containing an array of reg entities and its size.
 *  @param arreg        Pointer to a dynamically allocated array of reg entites
 *  @param size         Size of array.
 */

struct vectorreg
{
    reg* arreg;
    unsigned int size=0;
};
/** @struct vectorroom
 *  @brief Structure containing an array of room entities and its size.
 *  @param arreg        Pointer to a dynamically allocated array of room entites
 *  @param size         Size of array.
 */

struct vectorroom
{
    room* arroom;
    unsigned int size=0;
};
/** @struct Command
 *  @brief Structure containing a command syntax and its unique ID.
 *  @param ID           Unique ID of a command.
 *  @param name         Name,or better the syntax form of the command.
 */
struct Command
{
    int ID;
    string name;
};
void DateSort(vectorreg&);
bool Registered(const vectorreg ,const unsigned short,const string);
short FindRoom(const vectorroom,const unsigned short);
short FindReg(const vectorreg ,const unsigned short,const string);
Command FindID(const string com_name);
void Sort(vectorroom&,string);
void Sort(vectorreg&,string);
int FindFirstPresent(vectorreg&);
#endif // DATABASE
