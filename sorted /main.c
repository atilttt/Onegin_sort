#include "open_file.h"
#include "sorted.h"


int main(void)
{
    open_file("onegin.txt");
    printf("/////lets go work//////\n");
    
    copy_file("onegin.txt", "onegin.txt");
    sorted_alphabetically("onegin.txt");
    return 0;
}