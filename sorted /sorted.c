#include "sorted.h"

void copy_file(const char *original_file, const char *copied_file)
{ 
    FILE *original = fopen(original_file, "r");
    if (!original) 
    {
        printf("File not open\n");
        exit(1);
    }

    FILE *copied = fopen(copied_file, "w");
    if (!copied)
    { 
        printf("File not open\n");
        fclose(original);
        exit(1);
    }

    char c = 0;
    while ((c = fgetc(original)) != EOF)
    { 
        fputc(c, copied);
    }

    fclose(original);
    fclose(copied);
}

int quantity_lines(const char *name_file)
{ 
    FILE *fp = fopen(name_file, "r");
    if (!fp)
    {
        printf("File not open\n");
        fclose(fp);
    }

    int lines = 1;
    char c = 0;

    while ((c = fgetc(fp)) != EOF)
    { 
        if (c == '\n')
            lines++;
    }
    fclose(fp); 
    return lines;
}

int quantity_words_in_first_line(const char *name_file)
{
    FILE *fp = fopen(name_file, "r"); 
    if (!fp)
    {
        printf("File not open.\n");
        fclose(fp);
        exit(1);
    }

    int words_in_line = 0;
    char c = 0;

    while ((c = fgetc(fp)) != '\n')
    { 
        words_in_line++;
        printf("%c- ", c);
    }
    fclose(fp);
    return words_in_line;
}

void sorted_alphabetically(const char *copied_file_name)
{ 
    FILE *open_copied = fopen(copied_file_name, "r");
    
    if (!open_copied)
    { 
        printf("Sorry, file not open\n");
        fclose(open_copied);
        exit(1);
    }

    int lines = quantity_lines("sorted_onegin.txt");
    int words_in_line = quantity_words_in_first_line("sorted_onegin.txt"); 
    char **array_lines = calloc(lines, sizeof(char*));
    char *array_soxr_line = calloc(words_in_line, sizeof(char));

    printf("%d %d", lines, words_in_line);
    int i = 0;
    while (fgets(array_soxr_line, sizeof(array_soxr_line), open_copied) != NULL)
    { 
        //printf("%s ", array_soxr_line);
    }

}