#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Functions.h"
#include "Aeroflot.h"
#include <fstream>
#include <sstream>
using namespace std;
int main()
{
    ostringstream oss;
    ifstream in;
    Aeroflot plane[7];
    setlocale(LC_ALL, "rus");//Подключение кодировки с русскими буквами
    char str[100];
    char ch;
    char prev=' ';
    char *sentences[3];
    int sizes[3]={0, 0, 0};
    int i=0;
    int count=0;
    int choise, note;
    while(1)
    {
        while(1)
        {
            cout << "1 - Enter all data\n2 - Display all data (in alphabet order)\n3 - Search by plane type\n4 - Change or add any note\n5 - Read 3 sentences and display it in reverse order\n6 - Exit\n\n";
            cout << "Enter the number of your choise:\n";
            gets(str);
            if(str_check_of_number(str)==true)
            {
                choise=alpha_to_i(str);
                if(choise>6||choise<1)
                {
                   cout << "Incorrect! Press any button...\n";
                   _getch();
                   system("cls");
                   continue;
                }
                system("cls");
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
        switch(choise)
        {
        case 1: system("cls"); //Ввести все записи (максимум 7)
        for(int i=0; i<7; i++)
        {
           while(1)
           {
              system("cls");
              cin >> plane[i];
              try
              {
                 for(int j=0; j<7; j++)
                 {
                    if((plane[i].take_number()==plane[j].take_number())&&i!=j)
                       throw 666;
                 }
              }
              catch(int p)
              {
                 cout << "The exception! This number of flight exists already in database!\n";
                 cout << "\nPress any button...\n";
                 _getch();
                 continue;
              }
              break;
           }
        }
        cout << "\nPress any button...\n";
        _getch();
        system("cls");
            break;
        case 2: system("cls"); //Вывести все записи на экран
        sort_alphabet_order(plane);
        disp(plane);
        cout << "\nPress any button...\n";
        _getch();
        system("cls");
            break;
        case 3: system("cls"); //Поиск рейса по типу самолета
        sort_alphabet_order(plane);
        cout << "Enter the type of plane for search in database:\n";
        gets(str);
        cout << "\n\n";
        search_by_type(plane, str);
        cout << "\nPress any button...\n";
        _getch();
        system("cls");
            break;
        case 4: system("cls"); //Изменить или добавить запись
        sort_alphabet_order(plane); //Необходимо ввести номер записи для добавления или изменения (не более 7) 
        while(1) //Если запись с таким номером существует, она будет изменена;
        { //если не существует, то добавлена
            disp(plane);
            cout << "Enter the number of note you want to change or add:\n";
            gets(str);
            if(str_check_of_number(str)==true)
            {
                note=alpha_to_i(str);
                if(note>7||note<1)
                {
                   cout << "Incorrect! Press any button...\n";
                   _getch();
                   system("cls");
                   continue;
                }
                system("cls");
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
        while(1)
        {
           system("cls");
           cin >> plane[note-1];
           try
           {
              for(int j=0; j<7; j++)
              {
                 if((plane[note-1].take_number()==plane[j].take_number())&&((note-1)!=j))
                    throw 999;
              }
           }
           catch(int p)
           {
              cout << "The exception! This number of flight exists already in database!\n";
              cout << "\nPress any button...\n";
              _getch();
              continue;
           }
           break;
        }
        cout << "\nPress any button...\n";
        _getch();
        system("cls");
            break;
        case 5: system("cls"); //Считывание 3 предложений из файла Source.txt, их вывод в обратном порядке
        sizes[0]=0; //Предложением считается любой набор символов до точки, вопр. знака и т.д.,
        sizes[1]=0; //если был переход на новую строку.
        sizes[2]=0; //Если знаки-разделители идут ПОДРЯД друг за другом, то предложение не считается (....!.?)
        prev=' '; //Если меж разделителями хотя бы один символ, то предложение учитывается (. .)
        in.open("Source.txt");
        if(!in)
           cout << "File can't be open!\n";
        count=0;
        i=0;
        sentences[0]=NULL;
        sentences[1]=NULL;
        sentences[2]=NULL;
        while(((ch = in.get()) != EOF))
        {
           if((ch!='\n'&&ch!='\0'&&ch!='.'&&ch!='!'&&ch!='?')&&(prev=='\n'||prev=='\0'||prev=='.'||prev=='!'||prev=='?'))
           {
              count++;
              if(count>2)
                 break;
              sizes[count]++;
              prev=ch;
              continue;
           }
           if(ch!='\n'&&ch!='\0')
              sizes[count]++;
           prev=ch;
        }
        sentences[0]=new char[sizes[0]+1];
        sentences[1]=new char[sizes[1]+1];
        sentences[2]=new char[sizes[2]+1];
        count=0;
        i=0;
        prev=' ';
        in.close();
        in.open("Source.txt");
        while(((ch = in.get()) != EOF))
        {
           if((ch!='\n'&&ch!='\0'&&ch!='.'&&ch!='!'&&ch!='?')&&(prev=='\n'||prev=='\0'||prev=='.'||prev=='!'||prev=='?'))
           {
              sentences[count][i]='\0';
              count++;
              if(count>2)
                 break;
              i=0;
              sentences[count][i]=ch;
              i++;
              prev=ch;
              continue;
           }
           if(ch!='\n'&&ch!='\0')
           {
              sentences[count][i]=ch;
              i++;
           }
           prev=ch;
        }
        in.close();
        i=0;
        while(sizes[2]>0)
        {
            cout << sentences[2][i];
            i++;
            sizes[2]--;
        }
        cout << "\n";
        oss.str(sentences[1]);
        cout << oss.str() << "\n";
        oss.str(sentences[0]);
        cout << oss.str() << "\n";
        delete [] sentences[0];
        delete [] sentences[1];
        delete [] sentences[2];
        cout << "\nPress any button...\n";
        _getch();
        system("cls");
            break;
        case 6: //Выход
        cout << "Goodbye!\n";
        return 0;
            break;
        }
    }
}
