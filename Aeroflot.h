#ifndef AEROFLOT_H_INCLUDED
#define AEROFLOT_H_INCLUDED
#include <iostream>
using namespace std;
class Aeroflot
{
private:
    char *destination;
    char *type;
    int number;
public:
    void set_destination(char *data);
    void set_type(char *data);
    void set_number(int data);
    void get_destination(void);
    void get_type(void);
    void get_number(void);
    Aeroflot();
    Aeroflot(char *data_destination, char *data_type, int data_number);
    ~Aeroflot();
    Aeroflot(const Aeroflot& src);
    Aeroflot& operator=(const Aeroflot &src);
    friend ostream &operator<<(ostream &os, Aeroflot &obj);
    friend istream &operator>>(istream &stream, Aeroflot &obj);
    char* take_destination(void);
    char* take_type(void);
    int take_number(void);
    friend void sort_alphabet_order(Aeroflot obj[]);
    friend void search_by_type(Aeroflot obj[], char *str);
    friend void disp(Aeroflot obj[]);
};
#endif // AEROFLOT_H_INCLUDED
