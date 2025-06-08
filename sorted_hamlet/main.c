#include "tetst_open_file.h"
#include "hamlet.h"

int main(void)
{ 
    open_file("hamlet.txt");
    int counter = symbol_in_line("hamlet.txt");
    printf("\n%d max symbol in line", counter);
    return 0;
}