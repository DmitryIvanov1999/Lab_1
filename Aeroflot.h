#ifndef AEROFLOT_H_INCLUDED
#define AEROFLOT_H_INCLUDED
#include <iostream>
using namespace std;
class Aeroflot
{
private:
    char *destination;//Указатель на строку, в которой содержится информация о пункте назначения
    char *type;//Указатель на строку, в которой содержится информация о типе самолета
    int number;//Номер рейса
public:
    void set_destination(char *data);//Установить пункт назначения
    void set_type(char *data);//Установить тип самолета
    void set_number(int data);//Установить номер рейса
    void get_destination(void);//Вывод пункта назначения
    void get_type(void);//Вывод типа самолета
    void get_number(void);//Вывод номера рейса
    Aeroflot();//Обычный конструктор
    Aeroflot(char *data_destination, char *data_type, int data_number);//Конструктор с параметрами
    ~Aeroflot();//Деструктор
    Aeroflot(const Aeroflot& src);//Конструктор копирования
    friend ostream &operator<<(ostream &os, Aeroflot &obj);//Перегруж. оп. вывода
    friend istream &operator>>(istream &stream, Aeroflot &obj);//Перегруж. оп. ввода
    char* take_destination(void);//Получение указателя на пункт назначения
    char* take_type(void);//Получение указателя на тип самолета
    int take_number(void);//Получение номера рейса
    static void search_by_type(Aeroflot obj[], char *str);//Статический метод для сортировка рейсов по алфавитному порядку (пункты назначения)
    static void disp(Aeroflot obj[]);//Статический метод для вывода всего массива объектов на экран
    friend bool operator<(Aeroflot l, Aeroflot r);//Перегруженный оператор сравнения, благодаря которому выполняется сортировка объектов по алфавитному порядку в функции std::sort()
};
#endif // AEROFLOT_H_INCLUDED
