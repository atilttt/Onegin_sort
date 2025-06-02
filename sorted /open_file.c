#include "open_file.h"

void open_file()
{ 
    FILE *fp = fopen("onegin.txt", "r");
    if(!fp)
    { 
        printf("File not open. :/\n");
        exit(1);
    }

    int number_of_lines = 0, number_of_words = 0;
    int check = 0;
    
    check_numbers_of_lines(fp, &number_of_lines, &check);
    if (check == 0)       
    {
        rewind(fp);
        check_words_in_file(fp, &number_of_words, &check); 
    }

    switch(check)
    {
        case file_is_empty:
            printf("Brother(maybe sister), file is empty.\n");
            fclose(fp);
            exit(1);
        case few_lines:
            printf("Brother(maybe sister), your text contains few lines.\n");
            fclose(fp);
            exit(1);
        case few_words:
            printf("Brother(maybe sister), your text contains few words.\n");
            fclose(fp);
            exit(1);
        default: 
            printf("Nice, your file have %d lines and %d words.\n", number_of_lines + 1, number_of_words); //+1 потому что ласт строку он не посчитает
    }
    
    fclose(fp);
}

void check_numbers_of_lines(FILE *filename, int* number_of_lines, int* check)
{ 
    char counter_end_lines = 0;

    while((counter_end_lines = fgetc(filename)) != EOF)
    {
        if (counter_end_lines == '\n')
        {
            (*number_of_lines)++;
        }
    }
    
    if (*number_of_lines == 0)
    {
        *check = file_is_empty;
    }
    else if(*number_of_lines < MIN_LINES)
    { 
        *check = few_lines;
    }

}

void check_words_in_file(FILE *filename, int* number_of_words, int* check)
{ 
    char symbol_space = 0;

    while((symbol_space = fgetc(filename)) != EOF)
    {
        if (symbol_space == ' ') (*number_of_words)++;
    }

    if (*number_of_words == 0)
    {
        *check = file_is_empty; 
    }
    else if(*number_of_words < MIN_WORDS)
    { 
        *check = few_words;
    }   
}