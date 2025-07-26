#ifndef HAMLET_H
#define HAMLET_H

#define SYMBOL_IN_FILE_NAME 200 //see the main

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
    char *text;
    char **text_line;
} WORK_TEXT;

/**
 * @brief these enumerations are created to free up the memory allocated for our arrays.
 * @param array_of_char variable for clearing the array in which the source text is stored
 * @param array_of_stringsthis variable is used to clear an array of pointers.
 */
enum FREE_MEMORY_CHOOSE
{
    array_of_char = 1, 
    array_of_strings = 2
};

/**
 * @brief these enumerations are used for the WRITE_FILE function.
 * @param original this variable is created to record the source text.
 * @param sorted this variable is created to record sorted text.
 */
enum WRITE
{ 
    original = 0, 
    sorted = 1
}; 

/**
 * @brief needs no introduction
 */
enum ERROR_CODE
{
    FILE_NOT_OPEN = 1,
    SVORACHIVAEMSY_PAMYTI_PIZDA  = 1337, 
    NOT_COPIED_IN_ARRAY = 2006,
    SANYA = 2003 //в слуае, если наебланил пользователь
};

////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////FUNCTION_FOR_WORK/////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief This function counts the bytes in a file. Then it makes an array.
 * @param *wt - pointer on the struct 
 * @param *pointer_name_on_file everything is clear here anyway
 */
void proccesing_file(WORK_TEXT* wt, FILE *pointer_name_on_file); 

/**
 * @brief This function is used to create array for saved source text
 * @param *pointer_name_on_file - the name of the pointer to the open file
 * @param *wt - pointer on the struct
 */
void created_array_for_saved(FILE *pointer_name_on_file, WORK_TEXT *wt);

/**
 * @brief this function frees up the memory allocated for the array.
 * @param *wt this is a pointer to the structure that contains the array.
 * @param choose this variable responds for choosing to clear the array //check enum
 */
void free_memory_array(WORK_TEXT *wt, int choose);

/**
 * @brief tgis function creates an array of pointers
 * @param *wt this is a pointer to the struct WORK_TEXT
 */
void create_array_strings(WORK_TEXT *wt);

/**
 * @brief this function writes data to an output file.
 * @param *wt this is a pointer to the struct WORK_TEXT
 * @param ara_delay_vibor this variable is responsible for selecting the recorded array (sorted or original)
 * @param *output this is a pointer to the file
 */
void write_in_output_file(WORK_TEXT *wt, int ara_delay_vibor, FILE *output);

/**
 * @brief this is instruction
 */
void nemnoga_instruction(void);

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
 * @param **array - this is an array of strings that we will sort.
 * @param i - the element that is in the current position
 * @param j - the next element of the array
 * @param *wt - a pointer to the struct
 */
void swap_element_array(char **array, size_t i, size_t j);

/**
 * @brief needs no introduction
 */
void bubble_sort(WORK_TEXT *wt);

/**
 * @brief array sorting function
 * @param *wt - a pointer to the struct
 * @param low - index of the beginning of the sorted section of the array
 * @param high - index of the end of the sorted section of the array
 * @param *comp this is a pointer to the comparator function 
 */
void hach_edition_qsort(WORK_TEXT *wt, size_t low, size_t high, int (*comp)(const void *a, const void *b));

#endif //HAMLET_H