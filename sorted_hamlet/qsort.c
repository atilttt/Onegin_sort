#include "hamlet.h"

int comp_by_beginning(const void *a, const void *b)
{
    assert(a != NULL);
    assert(b != NULL);

    const char *s1 = *(const char **)a;
    const char *s2 = *(const char **)b;

    size_t size_s1 = strlen(s1);
    size_t size_s2 = strlen(s2);
    
    while (*s1 != '\0' || *s2 != '\0')
    { 
        while (*s1 != '\0' && isalpha(*s1) == 0) s1++;
        while (*s2 != '\0' && isalpha(*s2) == 0) s2++;
 
        if (*s1 != *s2)
        { 
            return (*s1 < *s2) ? -1 : 1;
        }

        s1++;
        s2++;
    }

    if (size_s1 < size_s2) return -1;
    else if (size_s2 < size_s1) return 1;

    return 0; //строки одинаковые
}

int comp_by_rhyme(const void *a, const void *b)
{ 
    assert(a != NULL);
    assert(b != NULL);

    const char *s1 = *(const char **)a;
    const char *s2 = *(const char **)b;

    size_t size_s1 = strlen(s1) - 1; //'\0'
    size_t size_s2 = strlen(s2) - 1; //'\0'

    s1 += size_s1;
    s2 += size_s2;

    while (s1 >= *(const char **)a && s2 >= *(const char **)b)
    { 
        while(s1 >= *(const char**)a && isalpha(*s1) == 0) s1--;
        while(s2 >= *(const char **)b && isalpha(*s2) == 0) s2--;
        
        if (*s1 != *s2)
        {
            return (*s1 < *s2) ? -1 : 1;
        }
        
        s1--;
        s2--;
    }

    if (s1 < *(const char **)a && s2 >= *(const char **)b) return -1;
    if (s2 < *(const char **)b && s1 >= *(const char **)a) return 1;

    return 0;

}

void swap_element_array(char **array, size_t i, size_t j)
{   
    char *temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void bubble_sorte(WORK_TEXT *wt)
{
    for (size_t i = 0; i < wt->line_in_file - 1; i++)
    { 
        for (size_t j = 0; j < wt->line_in_file - i - 1; j++)
        { 
            if (comp_by_beginning(&(wt->text_line[j]), &(wt->text_line[j + 1])) > 0)
            { 
                swap_element_array(wt->text_line, j, j+1);
            }
        }
    }
}


//я бы даже назвал хач Ломуто эдишн
void hach_edition_qsort(WORK_TEXT *wt, size_t low, size_t high, int (*comp)(const void *a, const void *b))
{
    if (low >= high)
        return;

    char **array = wt->text_line;

    char *pivot = array[high];
    size_t i = low;

    for (size_t j = low; j < high; j++)
    {
        if (comp(&array[j], &pivot) < 0)
        {
            swap_element_array(array, i, j);
            i++;
        }
    }

    swap_element_array(array, i, high);

    if (i > 0) hach_edition_qsort(wt, low, i - 1, comp); 
    hach_edition_qsort(wt, i + 1, high, comp);           
}
