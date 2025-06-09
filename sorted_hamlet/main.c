#include "hamlet.h"

int main() {

    const char *filename = "hamlet.txt";
    FILE *file = fopen(filename, "r");
    check_pointer(file);  
    WORK_TEXT wt = {0};
    created_array_for_saved(file, &wt);
    created_array_string(file, &wt);
    free_memory_array(&wt, array_of_strings);
    free_memory_array(&wt, array_of_char);

    fclose(file);
    return 0;
}
