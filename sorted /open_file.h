//честно не знаю нахуя я это написал, ну пусть будет, типо как тесты пока что, потом подумаю как это допилить


#ifndef OPEN_FILE_H

#define OPEN_FILE_H

#define MIN_LINES 1000 //так как сортируем большой файл по-идее я ограничения поставил
#define MIN_WORDS 7000

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * перечисления собственно для обработки ошибок в дальнейшем
 * @param few_word мало слов блин нафик
 * @param file_is_empty файл пустой мазафака
 * @param few_lines мало строчек блин нафик
 */
enum error
{ 
    few_words = 1, file_is_empty = 2, few_lines = 3 
};

/**
 * @brief функция как основная, открываем файл, проверяем файл, если что-то не так закрываем файл
 */
void open_file(const char *filename);

/**
 * @brief функция для проверки строк
 * @param filename открытый файл передаем
 * @param number_of_lines указатель на переменную, отвечающую за кол-во строк
 * @param check тоже указатель, но уже на переменную, которая хранит в себе номер ошибки(enum)
 */
void check_numbers_of_lines(FILE *pointer_name, int* number_of_lines, int* check);

/**
 * @brief функция для проверки слов
 * @param filename открытый файл
 * @param number_of_words указатель на переменную, отвечающую за кол-во слов
 * @param check тоже указатель, но уже на переменную, которая хранит в себе номер ошибки(enum)
 */
void check_words_in_file(FILE *pointer_name, int* number_of_words, int* check);



#endif // OPEN_FILE_H