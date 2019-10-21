#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "Aeroflot.h"
void string_copy(char *a, char *b); //Копирование строки b в a
long int string_length(char *a); //Получение длины строки
bool is_digit(char param); //Проверка на то, явл. ли символ param цифрой
int alpha_to_i(char *str); //Преобразование строки в целое число
bool str_check_of_number(char *str); //Проверка на то, явл. ли строка str числом
bool str_check_of_alphabet(char *str); //Проверка на то, содержит ли строка str только буквы
bool is_alpha(char param); //Проверка на то, явл. ли символ param буквой
bool is_upper(char param); //Проверка на то, явл. ли символ param заглавной буквой
#endif // FUNCTIONS_H_INCLUDED
