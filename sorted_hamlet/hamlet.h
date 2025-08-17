#ifndef HAMLET_H
#define HAMLET_H

#define SYMBOL_IN_FILE_NAME 300 //see the main

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief this structure is designed to work with text.
 * @param line_in_file here is the actual number of lines in the file
 * @param all_symbol the number of all sims that are in the file
 * @param *text this is an array for saving the source text. It was created in order to split our text into an array of strings (an array of pointers)
 * @param **text_line and here it is, an array of pointers
 */
typedef struct
{  
    size_t line_in_file;
    size_t all_symbol;
    char *buffer;
    char **text_line;
} WORK_TEXT;

enum ERORRS
{ 
    FREAD_ERRORS = 1,
    SANYA_MOMENT = 1337,
    FILE_PITERYALSYA = 1488
};



////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////FUNCTION_FOR_WORK/////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////



/**
 * @brief this function fill in the WORK_TEXT structure (constructor)
 * @param WORK_TEXT *wt this is a pointer on the struct
 * @param FILE *pointer_on_file this is a pointer to the stream (to an open file)
 */
void processing_file(WORK_TEXT *wt, FILE *pointer_on_file);

/**
 * @brief this function counts the number of bytes in a file
 * @param WORK_TEXT *wt this is a pointer on the struct
 * @param FILE *pointer_on_file this is a pointer to the stream (to an open file)
 * @return the number of bytes in the file
 */
size_t get_byte_in_file(WORK_TEXT *wt, FILE *pointer_on_file);

/**
 * @brief This function creates a buffer array to store text
 * @param WORK_TEXT *wt this is a pointer on the struct
 * @param FILE *pointer_on_file this is a pointer to the stream (to an open file) 
 * @return a pointer to the beginning of the buffer array
 */
char* created_array_buffer(WORK_TEXT *wt, FILE *pointer_on_file);

/**
 * @brief this function counts the number of lines and replaces the buffer '\n' with '\0'
 * @param WORK_TEXT *wt this is a pointer to the struct
 * @return the number of lines in the file
 */
size_t counting_lines(WORK_TEXT *wt);

/**
 * @brief this fucntion create array of strings
 * @param WORK_TEXT *wt this is a pointer to the struct
 * @return pointer to the beginning of the text_line array
 */
char** create_array_of_strings(WORK_TEXT *wt);

/**
 * @brief this function writes the original and sorted version of the text to the file
 * @param WORK_TEXT *wt this is a pointer to the struct
 * @param FILE *pointer_on_file this is a pointer to the stream (to an open file)
 */
void write_to_file_buffer(WORK_TEXT *wt, FILE *pointer_on_file);

/**
 * @brief Well, like a classic destructor
 * @param WORK_TEXT *wt this is a pointer to the struct
 */
void destructor_for_struct(WORK_TEXT *wt);

/**
 * @brief This function checks the pointer to the stream (file)
 * @param FILE *pointer_name the very pointer
 */
void check_file(FILE *pointer_name); 

/**
 * @brief function-checking user input
 * @param char* buffer this is a name file
 */
void user_input(char *buffer);



////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////FUNCTION_FOR_SORTED///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////




/**
 * @brief comparator, which is used to sort by beginning
 * @param *a pointer to an array element
 * @param *b pointer to an array element
 * @return 0 -> a = b, 1 -> a > b, -1 a < b 
 */
int comp_by_beginning(const void *a, const void *b);

/**
 * @brief a comparator that is used to sort by rhyme
 * @param *a pointer to an array element
 * @param *b pointer to an array element
 * @return 0 -> a = b, 1 -> a > b, -1 -> a < b
 */
int comp_by_rhyme(const void *a, const void *b);

/**
 * @brief this function swaps the sorted elements (needed for bubble sort)
 * @param void *a - a pointer to any type
 * @param void *b - a pointer to any type
 * @param size_t size - type size
 */
void swap_element_array(void *a, void *b, size_t size);

/**
 * @brief needs no introduction
 */
void bubble_sort(WORK_TEXT *wt, int (*comparator_hacha)(const void *a, const void *b));

/**
 * @param void *base - it represents pointer to the first element of the array to be sorted.
 * @param size_t nmemb - it represents number of element in the array.
 * @param size_t soze - it represents size of each element in the array.
 * @param int (*comparator_hacha)(void *a, void *b) - it represent a function pointer to a comparison function that compares two elements.
 */
void hach_edition_qsort(void *base, size_t nmemb, size_t size, int (*comparator_hacha)(const void *, const void *));

#endif //HAMLET_H