#include "hamlet.h"

void check_pointer(FILE *pointer_name_on_file)
{ 
    if (pointer_name_on_file == NULL)
    { 
        printf("sorry, brother(maybe a sister, maybe a mom ...), file not open :(\n)");
        abort();
    }
}

void free_memory_array(WORK_TEXT *wt, int choose)
{ 
    assert(wt != NULL);

    if (choose == array_of_char)
    {
        free(wt->text);
        wt->text = NULL;
    }
    else 
    { 
        for (size_t i = 0; i < wt->line_in_file; i++)
        {
            free(wt->text_line[i]); 
        }
        free(wt->text_line);
        wt->text_line = NULL;
    }
}

size_t counting_lines(FILE *pointer_name_on_file)
{
    check_pointer(pointer_name_on_file);

    char soxr = 0, c = 0;
    size_t line = 0;
    while((c = fgetc(pointer_name_on_file)) != EOF)
    { 
        if (c == '\n') line++;
        
        soxr = c;
    }
    
    if (soxr != '\n') line++; //processing the last line
    
    return line;
}

size_t all_symbol_in_file(FILE *pointer_name_of_file)
{
    check_pointer(pointer_name_of_file);
    rewind(pointer_name_of_file);

    size_t all_symbol = 0;
    char c = 0;
    while ((c = fgetc(pointer_name_of_file)) != EOF)
    {
        all_symbol++;
    }

    return all_symbol;
}

void created_array_for_saved(FILE *pointer_name_on_file, WORK_TEXT *pointer_on_struct)
{ 
    check_pointer(pointer_name_on_file);
    assert(pointer_on_struct != NULL);
    rewind(pointer_name_on_file);

    pointer_on_struct->line_in_file = counting_lines(pointer_name_on_file);
    pointer_on_struct->all_symbol = all_symbol_in_file(pointer_name_on_file);
    rewind(pointer_name_on_file);

    pointer_on_struct->text = calloc(pointer_on_struct->all_symbol + 1, sizeof(char));
    if (pointer_on_struct->text == NULL)
    { 
        printf("No memory allocated.\n");
        free_memory_array(pointer_on_struct, array_of_char);
        abort(); 
    }

    size_t result = fread(pointer_on_struct->text, sizeof(char), pointer_on_struct->all_symbol, pointer_name_on_file);
    if (result != pointer_on_struct->all_symbol)
    { 
        printf("fread worked incorrectly, there may be an error in reading all the characters in the file.\n ");
        free(pointer_on_struct->text);
        abort();
    }

    for (size_t i = 0; i < result; i++)
    { 
        if (pointer_on_struct->text[i] == '\n')
        { 
            pointer_on_struct->text[i] = '\0';
        }
    }

}


//мне не оч нравится реализация этих функций что array_for_saved, что created_array_string, но по другому я не придумал, еще и зубчатый массив
//я начал читать про структуры и про динам. память и там был он, я посчитал, что это идеальное решение для меня, но возможно я ошибаюсь.
void created_array_string(WORK_TEXT *pointer_name_on_struct)
{ 
    assert(pointer_name_on_struct); 
    
    pointer_name_on_struct->text_line = calloc(pointer_name_on_struct->line_in_file, sizeof(char*));
    if (pointer_name_on_struct->text_line == NULL)
    {
        printf("Opa, pamyt ne videlilas.\n");
        free_memory_array(pointer_name_on_struct, array_of_strings);
        abort(); 
    }

    char *ptr = pointer_name_on_struct->text;
    int new_sorted_line = 0;

    //ну очень интересный метод файл обработать
    for (size_t i = 0; i < pointer_name_on_struct->line_in_file; i++)
    {
        if (*ptr == '\0')
        { 
            ptr++;
            continue;
        }

        while(isspace(*ptr)) ptr++;

        if (*ptr == '\0')
        { 
            ptr++;
            continue;
        }

        size_t len = strlen(ptr);
        pointer_name_on_struct->text_line[new_sorted_line] = calloc(len + 1, sizeof(char));
        if (pointer_name_on_struct->text_line[new_sorted_line] == NULL)
        {
            printf("Opa, pamyt ne videlilas.\n");
            free_memory_array(pointer_name_on_struct, array_of_strings);
            abort(); 
        }  
        strcpy(pointer_name_on_struct->text_line[new_sorted_line], ptr);
        ptr += len + 1;
        new_sorted_line++; 
    }

    pointer_name_on_struct->line_in_file = new_sorted_line; //для qsort, да и в целом пустая строка по моему не строка, поэтому такая сортировка, и меняем количество, хотя бля, это не грамнотно
                                                            //но сортировать то я буду массив text_line, а буффер - есть буффер епт, ток он у меня text называется   
}

void the_end(FILE *pointer_name, int choose, WORK_TEXT *wt) 
{
    check_pointer(pointer_name);
    assert(wt);
    
    if (choose == original) 
    {
        for (size_t i = 0; i < wt->all_symbol;) 
        {
            if (wt->text[i] == '\0') 
            {
                fputc('\n', pointer_name);
                i++;
            } else 
            {
                fputc(wt->text[i++], pointer_name);
            }
        }
    } 
    else 
    {
        for (size_t i = 0; i < wt->line_in_file; i++) 
        {
            fputs(wt->text_line[i], pointer_name);
            fputc('\n', pointer_name);
        }
    }

    fprintf(pointer_name, "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"); //это для души
}