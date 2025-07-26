#include "hamlet.h"

int main(void) {
    printf("||||||||||||||||||||||||||||||||||");
    nemnoga_instruction();
    printf("||||||||||||||||||||||||||||||||||");

    FILE *input = fopen("hamlet.txt", "r"); 
    if (!input)
    {
        fprintf(stderr, "Bro, the file didnt open or maybe it got lost. You, please check the file and listen to the new album MACAN\n");
        exit(FILE_NOT_OPEN);
    }

    WORK_TEXT wt = {
        .all_symbol = 0,
        .line_in_file = 0,
        .text = NULL,
        .text_line = NULL
    };

    printf("pam-pam pidam pam-pam pidam dam\n");
    proccesing_file(&wt, input);
    created_array_for_saved(input, &wt); 
    create_array_strings(&wt);
    fclose(input);
    printf("pupupu the program has done everything it needs to do, let's go\n\n");
    //printf("%zu %zu", wt.all_symbol, wt.line_in_file);
    
    printf("Brat, please enter the file name (pls sanya_lox.txt && .txt don't forget)\n");
    printf("And yes, consider the 200-character limit\n");
    char name_output_file[SYMBOL_IN_FILE_NAME] = {'\0'};
    scanf("%199s", name_output_file); //проверка на дебила (ваще лучше бы через if проверить, но чет впадлу)
    printf("If the file is not called sanya_lox.txt, then you are a lox\n");

    FILE *output = fopen(name_output_file, "w");
    if(!output)
    {
        fprintf(stderr, "Bro, the file didnt open or maybe it got lost. You, please check the file and listen to the new album MACAN\n");
        exit(FILE_NOT_OPEN);
    }


    printf("first, the original text\n");
    write_in_output_file(&wt, original, output);
    printf("original sorted is full\n");

    printf("sortirovochka ara\n");
    hach_edition_qsort(&wt, 0, wt.line_in_file - 1, comp_by_beginning); 
    write_in_output_file(&wt, sorted, output);
    printf("alphabetical erasure, as fast as Skoda Octavia\n");

    printf("opyat sortirovochka ara\n");
    hach_edition_qsort(&wt, 0, wt.line_in_file - 1, comp_by_rhyme);
    write_in_output_file(&wt, sorted, output);


    printf("NYYYYYYYYYYYYYYYYYYYYYYYY brat, take the job\n\n\n");
    printf("if you broke the program or it broke itself, fuck off and go to rest\n");
    printf("But know this, if you got here, then you've done everything\n\n");


    printf("please write anything and the number\n");
    char prikol[36] = {};
    int prrikol = 0;
    scanf("%s ", prikol);
    scanf("%d ", &prrikol);


    printf("___________________________####__________\
            \n___________________________######________ \
            \n___________________________######_________\
            \n____________________________####__________\
            \n_____________________________##___________\
            \n___________________________######_________\
            \n__________________________#######_________\
            \n__####__________________#########_________\
            \n_######________________###_######_________\
            \n_######_______________###__######_________\
            \n__####_______________###___######_________\
            \n_____##################____######_________\
            \n_____##################САНЯ#######________\
            \n______#################____######_________\
            \n_______###_______#####_____######_________\
            \n______###_______#####______######_________\
            \n_____###________#####______######_________\
            \n#######_________##########_##############__\
            \n___________________________________________");



    free_memory_array(&wt, array_of_char);
    free_memory_array(&wt, array_of_strings);
    fclose(output);
    

    printf("paka\n");
    return 0;
}