#ifndef SORTED_H

#define SORTED_H

#include "open_file.h"
#include <string.h>
#include <locale.h>

/**
 * @brief функция, реализующая копирование файлов.
 * @param original_file имя исходного файла
 * @param copied_file имя файла, в который будем копировать исходный
 */
void copy_file(const char *original_file, const char *copied_file);

/**
 * @brief функция считающая в файле количество строк
 * @param name_file имя файла
 */
int quantity_lines(const char *name_file);

/**
 * @brief функция считающая количество символов в одной строке(для временного массива, куда потом будем сохранять по одной строек)
 * @param name_file имя файла 
 */
int quantity_words_in_first_line(const char *name_file);

void sorted_alphabetically(const char *copied_file_name);



#endif //SORTED_H