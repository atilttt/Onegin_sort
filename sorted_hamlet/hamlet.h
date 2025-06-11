//Я, конечно, после ревью исправлю все комментарии и прочую тему, ну, брат, я ща собираюсь это пушить
//И код конечно выглядит ебано, прям очень, ну типо, файл читаю посимвольно, что долго, копирую массивы и т.д.
//Я исправлю все, ток вот пока сидел думал как, но как будто всю логику заново писать
//Тада вопрос, а смысл кидать этот. Ну во первых, хочу тя послушать, в чем я не прав, че стоит почитать
//А во вторых, ну я писатель я так вижу :)


#ifndef HAMLET_H
#define HAMLET_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

//this is struct for work with file
typedef struct
{  
    size_t line_in_file;
    size_t all_symbol;
    char* text;
    char** text_line;
} WORK_TEXT;

enum free_memory_choose
{
    array_of_char = 1, array_of_strings = 2
};

enum write
{ 
    original = 0, sorted = 1
}; 

/**
 * @brief this function checks the pointer to the open file.
 * @param *pointer_name_on_file - the name of the pointer to the open file
 * @return it does not return, but closes the program if the pointer is null.
 */
void check_pointer(FILE* pointer_name_on_file);

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
void created_array_for_saved(FILE *pointer_name_on_file, WORK_TEXT *pointer_on_struct);

/**
 * @brief this function creates an array of strings to sort the text later. 
 * @param *pointer_on_struct - pointer on the struct
 */
void created_array_string(WORK_TEXT *pointer_on_struct);

/**
 * @brief this function frees up the memory allocated for the array.
 * @param *wt this is a pointer to the structure that contains the array.
 * @param 
 */
void free_memory_array(WORK_TEXT *wt, int choose);

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
 * @brief arrat sorting function
 * @param *wt - a pointer to the struct
 * @param count - the number of elements in the array 
 * @param size - the size of each element
 * @param *comp this is a pointer to the comparator function 
 */
void hach_edition_qsort(WORK_TEXT *wt, size_t count, size_t size, int (*comp)(const void *a, const void *b));

/**
 * @brief this function is the final one, we write everything to a file output.txt And that's it.
 * @param *pointer_name - the name of the pointer to the open file
 * @param name - name your file
 */
void the_end(FILE *pointer_name, int choose, WORK_TEXT *wt);

#endif //HAMLET_H