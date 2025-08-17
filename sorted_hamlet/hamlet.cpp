#include "hamlet.h"

void processing_file(WORK_TEXT *wt, FILE *pointer_on_file)
{ 
    assert(wt);
    assert(pointer_on_file);

    wt->all_symbol = get_byte_in_file(wt, pointer_on_file); 
    wt->buffer = created_array_buffer(wt, pointer_on_file);
    wt->line_in_file = counting_lines(wt);
    wt->text_line = create_array_of_strings(wt);
}

size_t get_byte_in_file(WORK_TEXT *wt, FILE *pointer_on_file)
{ 
    assert(wt);
    assert(pointer_on_file);

    assert(fseek(pointer_on_file, 0, SEEK_END) == 0);
    size_t byte_in_file = (size_t) ftell(pointer_on_file);
    rewind(pointer_on_file);

    return byte_in_file;
}

char* created_array_buffer(WORK_TEXT *wt, FILE *pointer_on_file)
{ 
    assert(wt);
    assert(pointer_on_file);

    char* buffer = (char *)calloc(wt->all_symbol + 1, sizeof(char));
    assert(buffer);

    size_t result = fread(buffer, sizeof(char), wt->all_symbol, pointer_on_file);

    if (result < wt->all_symbol)
    {
        fprintf(stderr, "the fread function is not working properly\n");
        exit(FREAD_ERRORS);
    }

    return buffer;
}

size_t counting_lines(WORK_TEXT *wt)
{ 
    assert(wt);

    char *ptr_buffer = wt->buffer; // это для того самого strchr
    size_t line = 0;

    while ((ptr_buffer = strchr(ptr_buffer, '\n')) != NULL)
    { 
        *ptr_buffer = '\0';
        ptr_buffer++;
        line++;
    }

    line++;

    return line;
}

char** create_array_of_strings(WORK_TEXT *wt)
{ 
    assert(wt);

    char** text_line = (char **) calloc(wt->line_in_file, sizeof(char *));
    assert(text_line);

    char *ptr_on_buffer_for_search_0 = wt->buffer;
    char *ptr_on_buffer_for_saved = wt->buffer; 
    
    for(size_t i = 0; i < wt->line_in_file; i++)
    { 
        text_line[i] = ptr_on_buffer_for_saved;

        while (*ptr_on_buffer_for_search_0 != '\0')
        { 
            ptr_on_buffer_for_search_0++; 
        }

        ptr_on_buffer_for_search_0++;               
        ptr_on_buffer_for_saved = ptr_on_buffer_for_search_0;
    }
    
    return text_line;
}

void write_to_file_buffer(WORK_TEXT *wt, FILE *pointer_on_file)
{
    assert(wt); 
    assert(pointer_on_file);

    fprintf(pointer_on_file, "\n\n\nkis-kis kis kis ya kotik ti kotik\n\n\n");

    for (size_t i = 0; i < wt->line_in_file; i++)
    {
        fputs(wt->text_line[i], pointer_on_file);
        fputc('\n', pointer_on_file);
    }
}


void destructor_for_struct(WORK_TEXT *wt)
{ 
    assert(wt);

    wt->all_symbol = 0;
    wt->line_in_file = 0;

    free(wt->buffer);
    free(wt->text_line);

    wt->buffer = NULL;
    wt->text_line = NULL;
}

void check_file(FILE *pointer_name)
{
    if (!pointer_name)
    {
        fprintf(stderr, "Well, look, the program is closed, right? Right.\
            So check your file, it's either empty or with another extension that is not supported by the program.\n\n");
        exit(FILE_PITERYALSYA);
    }
}

void user_input(char *buffer)
{ 
    assert(buffer);

    printf("hello again, please enter the name of the file that stores your text\n");
    printf("keep in mind the 300-character limit (.txt also applies to this)\n");

    if (scanf("%299s", buffer) != 1)
    { 
        fprintf(stderr, "Bro, read it again, please note that spaces are not needed here. Be sure to write .txt, okay?\n");
        exit(SANYA_MOMENT);
    }
    
    size_t len_str = strlen(buffer);
    if(len_str < 4 && strcmp(buffer + len_str - 4, ".txt") != 0)
    {
        fprintf(stderr ,"BROOOOOOOO, read carefully");
        exit(SANYA_MOMENT);
    }
}
