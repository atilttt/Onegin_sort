#include "tetst_open_file.h"


void open_file(const char *filename)
{ 
    int line = 0, error = 0, words = 0;
    FILE *fp = fopen(filename, "r"); 
    check_pointer_for_file(fp);

    check_line(fp, &line, &error);
    if (error == 0)
    { 
        rewind(fp);
        check_words(fp, &words, &error);
    }
    

    switch(error)
    { 
        case all_good:
            rewind(fp);
            break; 
        case file_is_empty:
            printf("Dratuti, your file is empty.\n");
            fclose(fp);
            exit(1);
            break;
        case number_line:
            printf("Dratuti, your file contains few lines.\n");
            fclose(fp);
            exit(1);
            break;
        case number_words:
            printf("Dratuti, your file contains few words\n.");
            fclose(fp);
            exit(1);
            break;
        default:
            printf("I don't know what happened, but I do know that I respect Daniil Paramonov.\n");
            break;
    } 
}

void check_pointer_for_file(FILE *name_pointer)
{ 
    if (name_pointer == NULL)
    { 
        printf("File not open, gg brother.\n");
        exit(1); 
    }
}

void check_line(FILE *pointer_name, int *line, int *error)
{ 
    assert(line != NULL);
    assert(error != NULL);

    char symbol = 0;
    while ((symbol = fgetc(pointer_name)) != EOF)
    { 
        if (symbol == '\n') (*line)++;
    }

    if (*line == 0)
    {
        *error = file_is_empty;
    }
    else if (*line < MIN_LINE)
    {
        *error = number_line;
    }

    *(line++); //так как, ласт строку не обработает, а если ошибку не отловит, то можно в целом и добавит :)
} 

void check_words(FILE *pointer_name, int *words, int *error)
{ 
    assert(words != NULL);
    assert(error != NULL);

    char array[MAX_WORD_LINE];
    int in_word = 0; //флаг для проверки, что мы внутри слова, ну с КР своровал
    while (fgets(array, sizeof(array), pointer_name) != NULL)
    { 
        if (array[0] == '\n') continue;
        
        for(int i = 0; array[i] != '\0'; i++)
        { 
            if (array[i] == ' ' || array[i] == '\t' || array[i] == '\n')
            {
                if (in_word != 0)
                { 
                    (*words)++;
                    in_word = 0;
                }
            }
            else
            {
                in_word = 1;
            }
        }    
    }

    if (*words == 0)
    { 
        *error = file_is_empty;
    }
    else if(*words < MIN_WORDS)
    {
        *error = number_words;
    }
    
}