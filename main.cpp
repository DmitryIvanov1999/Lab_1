#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include "Aeroflot.h"
#include <algorithm>
#define MAX_NUMBER 7//Максимальное количество записей - 7
using namespace std;
int main()
{
    Aeroflot plane[MAX_NUMBER];//Массив объектов (рейсов)
    setlocale(LC_ALL, "rus");//Подключение кодировки с русскими буквами
    char str[100];//Служебная строка для ввода данных в консоль
    int count=0;//Индекс массива-строки str и для строк, куда помещаются данные из файла
    int choise, note;//Переменные для номера команды в меню и выбора нужного элемента массива типа Aeroflot
    bool flag=true;//Флаг для проверки правильности введенных данных, команд и т.п.
    while(1)//Основной цикл работы программы
    {
        while(1)//Цикл для проверки правильности введенной команды в меню
        {
            cout << "1 - Enter all data\n2 - Display all data (in alphabet order)\n3 - Search by plane type\n4 - Change or add any note\n5 - Exit\n\n";//Информация для пользователя
            cout << "Enter the number of your choise:\n";
            gets(str);
            count=0;
            while(str[count])//Цикл проверки на то, является ли введенная заявка числом
            {
               if(isdigit(str[count]))
               {
                  flag=true;
                  count++;
               }
               else
               {
                  count=0;
                  flag=false;
                  break;
               }
            }
            if(!flag)
            {
               cout << "Incorrect! Press any button...\n";
               _getch();
               system("cls");
               continue;
            }
            else
               choise=atoi(str);//Сообщение - число, теперь идет преобразование из строки в число
            if(choise>5||choise<1)//Такой команды в меню нет, ошибка
            {
               cout << "Incorrect! Press any button...\n";
               _getch();
               system("cls");
               continue;
            }
            else
                break;
        }
        switch(choise)//Коммутатор, определяющий необходимые операции по заданному пункту в меню
        {
        case 1: system("cls");//Ввод всех данных
        for(int i=0; i<MAX_NUMBER; i++)
        {
           while(1)
           {
              system("cls");
              cin >> plane[i];//Непосредственный ввод информации в объекте
              try
              {
                 for(int j=0; j<MAX_NUMBER; j++)
                 {
                    if((plane[i].take_number()==plane[j].take_number())&&i!=j)//Проверка на то, уникален ли введенный номер рейса
                       throw 666;
                 }
              }
              catch(int p)//Номер уже существует
              {
                 cout << "The exception! This number of flight exists already in database!\n";
                 cout << "\nPress any button...\n";
                 _getch();
                 continue;
              }
              break;
           }
        }
        cout << "Sorting...\n\n";
        sort(plane,plane+MAX_NUMBER);//Сортировка объектов по алфавиту (пункт назначения)
        cout << "\nPress any button...\n";
        _getch();
        system("cls");
            break;
        case 2: system("cls");//Вывод всей информации (не более 7 записей)
        Aeroflot::disp(plane);//Вывод всей информации
        cout << "\nPress any button...\n";
        _getch();
        system("cls");
            break;
        case 3: system("cls");//Поиск по типу самолета
        cout << "Enter the type of plane for search in database:\n";
        gets(str);
        cout << "\n\n";
        Aeroflot::search_by_type(plane, str);//Поиск по типу самолета
        cout << "\nPress any button...\n";
        _getch();
        system("cls");
            break;
        case 4: system("cls");//Изменение или добавления новой записи (можно ввести число от 1 до 7 и только)
        //Если запись с таким номером существует, она заменится
        //Если нет, то добавится
        while(1)
        {
            Aeroflot::disp(plane);
            cout << "Enter the number of note you want to change or add:\n";
            gets(str);
            count=0;
            while(str[count])
            {
               if(isdigit(str[count]))
               {
                  flag=true;
                  count++;
               }
               else
               {
                  count=0;
                  flag=false;
                  break;
               }
            }
            if(!flag)
            {
               cout << "Incorrect! Press any button...\n";
               _getch();
               system("cls");
               continue;
            }
            else
               note=atoi(str);
            if(note>MAX_NUMBER||note<1)
               {
                  cout << "Incorrect! Press any button...\n";
                  _getch();
                  system("cls");
                  continue;
               }
            else
               break;
        }
        while(1)
        {
           system("cls");
           cin >> plane[note-1];//Замена или добавление только одной записи, номер которой ввели
           try
           {
              for(int j=0; j<MAX_NUMBER; j++)
              {
                 if((plane[note-1].take_number()==plane[j].take_number())&&((note-1)!=j))//Снова сравнение на уникальность номера рейса
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
        cout << "Sorting...\n\n";
        sort(plane,plane+MAX_NUMBER);
        cout << "\nPress any button...\n";
        _getch();
        system("cls");
            break;
        case 5://Выход из программы
        cout << "Goodbye!\n";
        return 0;
            break;
        }
    }
}
