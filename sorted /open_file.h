#ifndef OPEN_FILE_H

#define OPEN_FILE_H
#define MIN_LINES 1000
#define MIN_WORDS 7000

#include <stdio.h>
#include <stdlib.h>


enum error
{ 
    few_words = 1, file_is_empty = 2, few_lines = 3 
};


void open_file();

void check_numbers_of_lines(FILE *filename, int* number_of_lines, int* check);

void check_words_in_file(FILE *filename, int* number_of_words, int* check);



#endif // OPEN_FILE_H