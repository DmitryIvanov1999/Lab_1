#include "Aeroflot.h"
#include "Functions.h"
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
void Aeroflot::set_destination(char *data)
{
    long int size=string_length(data);
    delete [] destination;
    destination=NULL;
    destination=new char[size+1];
    string_copy(destination, data);
    return;
}
void Aeroflot::set_type(char *data)
{
    long int size=string_length(data);
    delete [] type;
    type=NULL;
    type=new char[size+1];
    string_copy(type, data);
    return;
}
void Aeroflot::set_number(int data)
{
    number=0;
    number=data;
    return;
}
void Aeroflot::get_destination(void)
{
    cout << "The destination: " << destination << "\n";
    return;
}
void Aeroflot::get_type(void)
{
    cout << "The type of plain: " << type << "\n";
    return;
}
void Aeroflot::get_number(void)
{
    cout << "The number of flight: " << number << "\n";
    return;
}
Aeroflot::Aeroflot()
{
    cout << "Constructor for object with address " << this << "\n";
    destination=new char[2];
    *(destination+0)=' ';
    *(destination+1)='\0';
    type=new char[2];
    *(type+0)=' ';
    *(type+1)='\0';
    number=0;
}
Aeroflot::~Aeroflot()
{
    cout << "Destructor for object with address " << this << "\n";
    delete [] destination;
    destination=NULL;
    delete [] type;
    type=NULL;
    number=0;
}
istream &operator>>(istream &stream, Aeroflot &obj)
{
    fflush(stdin);
    char str[100];
    int data_number;
    while(1)
    {
       cout << "Enter the destination:\n";
       gets(str);
       if(str_check_of_alphabet(str)==true&&is_upper(str[0])==true)
          break;
       else
       {
          cout << "Incorrect! Press any button...\n";
          _getch();
          system("cls");
          continue;
       }
    }
    obj.set_destination(str);
    cout << "Enter the type of plane:\n";
    gets(str);
    obj.set_type(str);
    while(1)
    {
       cout << "Enter the number of flight:\n";
       gets(str);
       if(str_check_of_number(str)==true)
       {
          data_number=alpha_to_i(str);
          break;
       }
       else
       {
          cout << "Incorrect! Press any button...\n";
          _getch();
          system("cls");
          continue;
       }
    }
    obj.set_number(data_number);
	return stream;
}
ostream &operator<<(ostream &stream, Aeroflot &obj)
{
    obj.get_destination();
    obj.get_type();
    obj.get_number();
    return stream;
}
char* Aeroflot::take_destination(void)
{
    return destination;
}
char* Aeroflot::take_type(void)
{
    return type;
}
Aeroflot::Aeroflot(const Aeroflot& src)
{
    cout << "Copy constructor for object with address " << this << "\n";
    if(destination)
    {
        delete [] destination;
        destination=NULL;
    }
    if(type)
    {
        delete [] type;
        type=NULL;
    }
    long int size=string_length(src.destination);
    destination=new char [size+1];
    string_copy(destination,src.destination);
    size=string_length(src.type);
    type=new char [size+1];
    string_copy(type,src.type);
    number=src.number;
}
Aeroflot& Aeroflot::operator=(const Aeroflot &src)
{
    if(destination)
    {
        delete [] destination;
        destination=NULL;
    }
    if(type)
    {
        delete [] type;
        type=NULL;
    }
    long int size=string_length(src.destination);
    destination=new char [size+1];
    string_copy(destination,src.destination);
    size=string_length(src.type);
    type=new char [size+1];
    string_copy(type,src.type);
    number=src.number;
    return *this;
}
int Aeroflot::take_number(void)
{
    return number;
}
Aeroflot::Aeroflot(char *data_destination, char *data_type, int data_number)
{
   cout << "Constructor with parameters for object with address " << this << "\n";
   long int size=string_length(data_destination);
   destination=NULL;
   destination=new char[size+1];
   string_copy(destination, data_destination);
   size=string_length(data_type);
   type=NULL;
   type=new char[size+1];
   string_copy(type, data_type);
   number=data_number;
}
