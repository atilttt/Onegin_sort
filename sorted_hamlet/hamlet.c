#include "hamlet.h"

void free_memory_array(WORK_TEXT *wt, int choose)
{ 
    assert(wt);    
    if (choose == array_of_char)
    {
        free(wt->text);
    }
    else if (choose == array_of_strings)
    { 
        for (size_t i = 0; i < wt->line_in_file; i++)
        { 
            free(wt->text_line[i]);
        }
        free(wt->text_line);
    }
    else
    {
        fprintf(stderr, "KOGO TI PITAESHSYA NAEBAT?\n");
        exit(SANYA);
    }
    
}

void proccesing_file(WORK_TEXT *wt, FILE *pointer_name_on_file)
{ 
    assert(wt);
    if (!pointer_name_on_file)
    {
        fprintf(stderr, "Bro, the file didnt open or maybe it got lost. You, please check the file and listen to the new album MACAN\n");
        exit(FILE_NOT_OPEN);
    }

    fseek(pointer_name_on_file, 0, SEEK_END);
    wt->all_symbol = ftell(pointer_name_on_file);
    rewind(pointer_name_on_file);
}

void created_array_for_saved(FILE *pointer_name_on_file, WORK_TEXT *wt)
{ 
    assert(wt); 
    assert(pointer_name_on_file);

    wt->text = calloc(wt->all_symbol + 1, sizeof(char));

    if (!wt->text)
    { 
        fprintf(stderr, "no memory allocated for array buffer\n"); // я так понимаю это тоже крит, но пока надо как бы себя обезопасить, потом комментарии уберем
        exit(SVORACHIVAEMSY_PAMYTI_PIZDA);
    }

    size_t result = fread(wt->text, sizeof(char), wt->all_symbol, pointer_name_on_file); 

    if (result != wt->all_symbol)
    { 
        fprintf(stderr, "nothing was copied to the array, or less than necessary was copied\n");
        free_memory_array(wt, array_of_char);
        exit(NOT_COPIED_IN_ARRAY);
    }

    for (size_t i = 0; i < result; i++)
    {
        if (wt->text[i] == '\n')
        { 
            wt->text[i] = '\0';
            wt->line_in_file++;
        }
    }
    wt->text[result] = '\0';

}


void create_array_strings(WORK_TEXT *wt)
{
    assert(wt && wt->text);

    wt->text_line = calloc(wt->line_in_file, sizeof(char *));
    if (!wt->text_line)
    {
        fprintf(stderr, "cannot allocate memory for text_line\n");
        exit(SVORACHIVAEMSY_PAMYTI_PIZDA);
    }

    size_t new_line = 0;
    char *ptr_on_text = wt->text;
    char *end = wt->text + wt->all_symbol;

    while (ptr_on_text < end && new_line < wt->line_in_file)
    {
        size_t len_str = strnlen(ptr_on_text, end - ptr_on_text);
        if (len_str == 0)
        {
            ptr_on_text++;
            continue;
        }

        wt->text_line[new_line] = calloc(len_str + 1, sizeof(char));
        if (!wt->text_line[new_line])
        {
            fprintf(stderr, "cannot allocate memory for text_line[%zu]\n", new_line);
            exit(SVORACHIVAEMSY_PAMYTI_PIZDA);
        }

        strncpy(wt->text_line[new_line], ptr_on_text, len_str);
        wt->text_line[new_line][len_str] = '\0'; 
        new_line++;

        ptr_on_text += len_str + 1;  
    }

    wt->line_in_file = new_line; 
}


void write_in_output_file(WORK_TEXT *wt, int ara_delay_vibor, FILE *output)
{ 
    fprintf(output, "\n\n|||||||||||||||||||||||||||||||||||||||||||ARA NE GONI DA, YA PO SALONY YZE GULYAU|||||||||||||||||||||||||||||||||||||||||||\n\n");

    if (!output)
    { 
        fprintf(stderr, "Bro, the file didnt open or maybe it got lost. You, please check the file and listen to the new album MACAN\n");
        exit(FILE_NOT_OPEN);
    }

    if (ara_delay_vibor == original)
    {
        for(size_t i = 0; i < wt->all_symbol; i++)
        { 
            if (wt->text[i] == '\0')
            {
                wt->text[i] = '\n'; 
            }
            fputc(wt->text[i], output);
        }
    }
    else if(ara_delay_vibor == sorted)
    { 
        printf("tuz tuz\n");
        for (size_t i = 0; i < wt->line_in_file; i++)
        {
            fputs(wt->text_line[i], output);
            fputc('\n', output);
        }
    }
    else
    {
        fprintf(stderr, "NY TI DAESH\n");
        exit(SANYA); 
    }
}

void nemnoga_instruction(void)
{
    printf("hi dear user, I would like to tell you this thought, that this project doesn't make much sense, but if you bitch break my code, I'll come to your city and break your nose. Read the rest in the README.\n");
    printf("POKA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
}