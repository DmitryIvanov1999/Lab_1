#ifndef AEROFLOT_H_INCLUDED
#define AEROFLOT_H_INCLUDED
#include <iostream>
using namespace std;
class Aeroflot
{
private:
    char *destination; //Указатель на строку, в которой содержится информация о пункте назначения
    char *type; //Указатель на строку, в которой содержится информация о типе самолета
    int number; //Номер рейса
public:
    void set_destination(char *data); //Установить пункт назначения
    void set_type(char *data); //Установить тип самолета
    void set_number(int data); //Установить номер рейса
    void get_destination(void); //Вывод пункта назначения
    void get_type(void); //Вывод типа самолета
    void get_number(void); //Вывод номера рейса
    Aeroflot(); //Обычный конструктор
    Aeroflot(char *data_destination, char *data_type, int data_number); //Конструктор с параметрами
    ~Aeroflot(); //Деструктор
    Aeroflot(const Aeroflot& src); //Конструктор копирования
    Aeroflot& operator=(const Aeroflot &src); //Перегруж. оп. присваивания
    friend ostream &operator<<(ostream &os, Aeroflot &obj); //Перегруж. оп. вывода
    friend istream &operator>>(istream &stream, Aeroflot &obj); //Перегруж. оп. ввода
    char* take_destination(void); //Получение указателя на пункт назначения
    char* take_type(void); //Получение указателя на тип самолета
    int take_number(void); //Получение номера рейса
    friend void sort_alphabet_order(Aeroflot obj[]); //Сортировка рейсов по алфавитному порядку (пункты назначения)
    friend void search_by_type(Aeroflot obj[], char *str); //Поиск по типу самолета
    friend void disp(Aeroflot obj[]); //Вывод всего массива объектов на экран
};
#endif // AEROFLOT_H_INCLUDED
