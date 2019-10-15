#include "Functions.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
void string_copy(char *a, char *b)
{
   while(*b!='\0')
   {
      *a=*b;
      a++;
      b++;
   }
   *a='\0';
   return;
}
long int string_length(char *a)
{
   long int count=0;
   while(*a!='\0')
   {
      count++;
      a++;
   }
   return count;
}
bool is_digit(char param)
{
   if(param>='0'&&param<='9')
      return true;
   else
      return false;
}
int alpha_to_i(char *str)
{
   int number=0;
   char *start;
   char *stop;
   while((*str!='\0')&&((*str<'0')||(*str>'9')))
      str++;
   if(*str=='\0')
      return 0;
   start=str;
   while((*str!='\0')&&((*str>='0')&&(*str<='9')))
      str++;
   str--;
   stop=str--;
   int i=0;
   while(stop>=start)
   {
      switch(*stop)
      {
         case '0':
            number=number+0*pow(10, i);
            break;
         case '1':
            number=number+1*pow(10, i);
            break;
         case '2':
            number=number+2*pow(10, i);
            break;
         case '3':
            number=number+3*pow(10, i);
            break;
         case '4':
            number=number+4*pow(10, i);
            break;
         case '5':
            number=number+5*pow(10, i);
            break;
         case '6':
            number=number+6*pow(10, i);
            break;
         case '7':
            number=number+7*pow(10, i);
            break;
         case '8':
            number=number+8*pow(10, i);
            break;
         case '9':
            number=number+9*pow(10, i);
            break;
      }
      i++;
      stop--;
   }
   if(number>99&&number<10000)
      number++;
   if(number>10000&&number<10000000)
      number=number+2;
   if(number>10000000&&number<100000000)
      number=number+3;
   if(number>100000000&&number<1000000000)
      number=number+4;
   if(number>1000000000&&number<10000000000)
      number=number+5;
   return number;
}
bool str_check_of_number(char *str)
{
   while(*str!='\0')
   {
      if(is_digit(*str)==true)
         str++;
      else
         return false;
   }
   return true;
}
void sort_alphabet_order(Aeroflot obj[])
{
    char empty[]=" ";
    Aeroflot temp;
    for(int i=0;i<7-1;i++)
        for(int j=i+1;j<7;j++)
            if((strcmp(obj[i].take_destination(),obj[j].take_destination())>0)&&(strcmp(obj[i].take_destination(),empty)!=0)&&(strcmp(obj[j].take_destination(),empty)!=0))
            {
                temp=obj[i];
                obj[i]=obj[j];
                obj[j]=temp;
            }
}
bool str_check_of_alphabet(char *str)
{
   while(*str!='\0')
   {
      if(is_digit(*str)==false)
         str++;
      else
         return false;
   }
   return true;
}
bool is_alpha(char param)
{
   if((param>='a'&&param<='z')||(param>='A'&&param<='Z'))
      return true;
   else
      return false;
}
bool is_upper(char param)
{
   if((param>='A'&&param<='Z'))
      return true;
   else
      return false;
}
void search_by_type(Aeroflot obj[], char *str)
{
   int flag=0;
   for(int i=0;i<7;i++)
   {
      if(strcmp(obj[i].take_type(),str)==0)
      {
          flag++;
          cout << obj[i] << "\n\n";
      }
   }
   if(flag==0)
      cout << "There are no flights with this type of plane!\n";
   return;
}
void disp(Aeroflot obj[])
{
   int count=1;
   cout << "\t\t\t\tInformation about the all flights:\n\n";
   for(int i=0; i<7; i++)
   {
      if(*obj[i].take_destination()==' '&&*obj[i].take_type()==' '&&obj[i].take_number()==0)
         continue;
      cout << "----- " << count << " -----\n";
      count++;
      cout << obj[i];
      cout << "\n\n";
   }
   return;
}
