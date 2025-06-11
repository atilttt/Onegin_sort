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
    else return 1;

    return 0;

}

void hach_edition_qsort(WORK_TEXT *wt, size_t count, size_t size, int (*comp)(const void *b, const void *a))
{ 
    
}