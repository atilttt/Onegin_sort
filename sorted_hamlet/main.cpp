#include "hamlet.h"

int main(void)
{ 
    printf("Hello dear user. Welcome to the wonderful LARGE text sorting program.\nSo, enter the name of the file where your text is stored.\n\n");

    char name_input_file[SYMBOL_IN_FILE_NAME] = {};
    check_user_input(name_input_file);
    
    FILE *input = fopen(name_input_file, "r");
    check_file(input);

    printf("Okay, Okay, the file is open, let's start working with it.\n");
    printf("first, let's process the file\n");
    WORK_TEXT wt = {};

    processing_file(&wt, input);
    fclose(input);

    printf("\n\nOkay, the file has been processed\n");
    printf("let's start sorting?\n");
    char symbol = 0;
    printf("Write y/n, where y - is starting sorting, n - is not\n");
    scanf(" %c", &symbol);
    if(symbol == 'n')
    {
        fprintf(stdout, "paka\n");
        exit(1);
    }
     
    printf("\ngo, please write the name of the output file\n");
    printf("the rules are the same\n");
    char name_output_file[SYMBOL_IN_FILE_NAME] = {};
    check_user_input(name_output_file);

    FILE *output = fopen(name_output_file, "w");
    check_file(output);
    
    printf("recording the original text\n");
    write_to_file_buffer(&wt, output);
    
    hach_edition_qsort(&wt, 0, wt.line_in_file - 1, comp_by_beginning);
    write_to_file_buffer(&wt, output);
    printf("We recorded the sorting by the beginning of the lines\n");

    bubble_sort(&wt, comp_by_rhyme);
    write_to_file_buffer(&wt, output);
    printf("USE, take the job\n");
    fclose(output);

    destructor_for_struct(&wt);

    return 0;
}