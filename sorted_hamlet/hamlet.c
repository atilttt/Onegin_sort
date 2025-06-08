#include "hamlet.h"

void check_pointer(FILE *pointer_name_on_file)
{ 
    if (pointer_name_on_file == NULL)
    { 
        printf("sorry, brother(maybe a sister, maybe a mom ...), file not open :(\n)");
        abort();
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

size_t all_symbol_in_the_file(FILE *pointer_name)
{
    check_pointer(pointer_name);
    rewind(pointer_name);

    size_t all_symbol = 0;
    char c = 0;
    while ((c = fgetc(pointer_name)) != EOF)
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

    pointer_on_struct->line_in_file = counting_line(pointer_name_on_file);
    pointer_on_struct->all_symbol = all_symbol_in_file(pointer_name_on_file);

    pointer_on_struct->text = calloc(pointer_on_struct->all_symbol, sizeof(char));
    if (pointer_on_struct->text == NULL)
    { 
        printf("No memory allocated.\n");
        fclose(pointer_name_on_file);
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

void created_array_string(FILE *pointer_name_on_file, WORK_TEXT *pointer_name_on_struct)
{ 
    check_pointer(pointer_name_on_file);
    assert(pointer_name_on_struct); 
    
    pointer_name_on_struct->text_line = calloc(pointer_name_on_struct->line_in_file, sizeof(char *)); 
    if (pointer_name_on_struct->text_line == NULL)
    {
        printf("No memory allocated.\n");
        free(pointer_name_on_struct->text_line);
        abort();
    }

    for (size_t i = 0; i < pointer_name_on_struct->line_in_file; i++)
    { 
        ;
    }

}