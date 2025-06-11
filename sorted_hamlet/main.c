#include "hamlet.h"

int main() {
    // 1. Открытие файлов
    FILE *input = fopen("hamlet.txt", "r");
    FILE *output = fopen("output.txt", "w");
    check_pointer(input);
    check_pointer(output);

    WORK_TEXT wt = {0};

    created_array_for_saved(input, &wt);
    created_array_string(&wt);
    
    char** alphabet_sorted = malloc(wt.line_in_file * sizeof(char*));
    char** rhyme_sorted = malloc(wt.line_in_file * sizeof(char*));
    if (!alphabet_sorted || !rhyme_sorted) {
        printf("gg naxyi\n");
        abort(); 
    }
    
    memcpy(alphabet_sorted, wt.text_line, wt.line_in_file * sizeof(char*));
    memcpy(rhyme_sorted, wt.text_line, wt.line_in_file * sizeof(char*));
    
    fprintf(output, "|||||||ORIGINAL TEXT|||||\n\n");
    the_end(output, original, &wt);
    
    hach_edition_qsort(&wt, 0, wt.line_in_file-1, comp_by_beginning);
    fprintf(output, "\n\n|||||||||||ABCDEFGHIJKLMN||||||||||\n\n");
    the_end(output, sorted, &wt);
    
    memcpy(wt.text_line, alphabet_sorted, wt.line_in_file * sizeof(char*));
    
    hach_edition_qsort(&wt, 0, wt.line_in_file-1, comp_by_rhyme);
    fprintf(output, "\n\n||||||||||RHYME ORDER||||||||||\n\n");
    the_end(output, sorted, &wt);
    
    
    free(alphabet_sorted);
    free(rhyme_sorted);
    free_memory_array(&wt, array_of_char);
    free_memory_array(&wt, array_of_strings);
    
    fclose(input);
    fclose(output);
    return 0;
}