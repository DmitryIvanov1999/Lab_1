#include "Aeroflot.h"//h-заголовок для использования данных рабочего класса
#include <stdlib.h>//h-заголовок для функции system("cls"), очищающей экран
#include <conio.h>//h-заголовок для принятия команды нажатия любой клавиши _getch() при запросе
#include <stdio.h>//h-заголовок для функции fflush(stdin), очищающей входной поток
#include <string.h>//h-заголовок для работы со строками
#define MAX_NUMBER 7//Максимальное количество записей - 7
using namespace std;
void Aeroflot::set_destination(char *data)
{
    long int size=strlen(data);
    delete [] destination;
    destination=NULL;
    destination=new char[size+1];
    strcpy(destination, data);
    return;
}
void Aeroflot::set_type(char *data)
{
    long int size=strlen(data);
    delete [] type;
    type=NULL;
    type=new char[size+1];
    strcpy(type, data);
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
    cout << "Constructor for object with address " << this << "\n";//Вывод сообщ. о том, что вызван конструктор для рассматриваемого объекта
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
    cout << "Destructor for object with address " << this << "\n";//Вывод сообщ. о том, что вызван деструктор для рассматриваемого объекта
    delete [] destination;//
    destination=NULL;//
    delete [] type;//Очистка памяти
    type=NULL;//
    number=0;//
}
istream &operator>>(istream &stream, Aeroflot &obj)
{
    fflush(stdin);
    char str[100];
    int data_number;
    int count=0;
    bool flag=true;
    while(1)
    {
       cout << "Enter the destination:\n";
       gets(str);
       while(str[count])
       {
          if((!isalpha(str[count])&&str[count]!='-'&&str[count]!=' '&&str[count]!='\'')||!isupper(str[0]))//Проверка на то, является ли введенная строка допустимой для названия города
          {
             cout << "Incorrect! Press any button...\n";
             _getch();
             system("cls");
             flag=false;
             count=0;
             break;
          }
          flag=true;
          count++;
       }
       if(flag)
          break;
    }
    count=0;
    obj.set_destination(str);
    cout << "Enter the type of plane:\n";
    gets(str);
    obj.set_type(str);
    while(1)
    {
       cout << "Enter the number of flight:\n";
       gets(str);
       while(str[count])
       {
          if(isdigit(str[count]))//Проверка на то, является ли строка числом
          {
             flag=true;
             count++;
          }
          else
          {
             cout << "Incorrect! Press any button...\n";
             _getch();
             system("cls");
             flag=false;
             count=0;
             break;
          }
       }
       if(flag)
       {
          data_number=atoi(str);
          break;
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
    cout << "Copy constructor for object with address " << this << "\n";//Вывод сообщ. о том, что вызван конструктор копирования для рассматриваемого объекта
    delete [] destination;//
    destination=NULL;//
    delete [] type;//Обнуление всей памяти для создаваемого объекта
    type=NULL;//
    number=0;//
    /*-----------Выделение новой памяти и ее заполнение---------*/
    long int size=strlen(src.destination);
    destination=new char [size+1];
    strcpy(destination,src.destination);
    size=strlen(src.type);
    type=new char [size+1];
    strcpy(type,src.type);
    number=src.number;
}
int Aeroflot::take_number(void)
{
    return number;
}
Aeroflot::Aeroflot(char *data_destination, char *data_type, int data_number)
{
   cout << "Constructor with parameters for object with address " << this << "\n";
   long int size=strlen(data_destination);
   destination=NULL;
   destination=new char[size+1];
   strcpy(destination, data_destination);
   size=strlen(data_type);
   type=NULL;
   type=new char[size+1];
   strcpy(type, data_type);
   number=data_number;
}
void Aeroflot::search_by_type(Aeroflot obj[], char *str)
{
   int flag=0;
   for(int i=0;i<MAX_NUMBER;i++)
   {
      if(strcmp(obj[i].take_type(),str)==0)//Поиск по всему массиву на совпадение запрашиваемого типа самолета с теми, которые есть в базе данных
      {
          flag++;
          cout << obj[i] << "\n\n";
      }
   }
   if(flag==0)
      cout << "There are no flights with this type of plane!\n";
   return;
}
void Aeroflot::disp(Aeroflot obj[])
{
   int count=1;
   cout << "\t\t\t\tInformation about the all flights (not more than 7 notes):\n\n";
   for(int i=0; i<MAX_NUMBER; i++)
   {
      if(*obj[i].take_destination()==' '&&*obj[i].take_type()==' '&&obj[i].take_number()==0)//Если запись пуста, не производить вывод
         continue;
      cout << "----- " << count << " -----\n";
      count++;
      cout << obj[i];
      cout << "\n\n";
   }
   return;
}
bool operator<(Aeroflot &l, Aeroflot &r)
{
   if((strcmp(r.take_destination(),l.take_destination())>0)&&(strcmp(l.take_destination()," ")!=0)&&(strcmp(r.take_destination()," ")!=0))//Сравнение по алфавитному порядку
      return true;
   else
      return false;
}
