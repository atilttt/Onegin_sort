#ifndef HAMLET_H
#define HAMLET_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//this is struct for work with file
typedef struct
{  
    size_t line_in_file;
    size_t all_symbol;
    char* text;
    char** text_line;
} WORK_TEXT;


/**
 * @brief this function checks the pointer to the open file.
 * @param *pointer_name_on_file - the name of the pointer to the open file
 * @return it does not return, but closes the program if the pointer is null.
 */
void pointer_check(FILE* pointer_name_on_file);

/**
 * @brief this function counting the lines in file
 * @param *pointer_name_on_file - the name of the pointer to the open file
 * @return number of lines read
 */
size_t counting_lines(FILE *pointer_name_on_file);

/**
 * @brief this function counting all symbol in file
 * @param *pointer_name_on_file - the name of the pointer to the open file
 * @return the number of all characters in the file
 */
size_t all_symbol_in_file(FILE *pointer_name_on_file);

/**
 * @brief This function is used to create array for saved 
 * @param *pointer_name_on_file - the name of the pointer to the open file
 * @param *pointer_on_struct - pointer on the struct
 */
void created_array_for_save(FILE *pointer_name_on_file, WORK_TEXT *pointer_on_struct);

/**
 * @brief this function creates an array of strings to sort the text later.
 * @param *pointer_name_on_file - the name of the pointer to the open file 
 * @param *pointer_on_struct - pointer on the struct
 */
void created_array_string(FILE *pointer_name_on_file, WORK_TEXT *pointer_on_struct);

#endif //HAMLET_H