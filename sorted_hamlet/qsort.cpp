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
        assert(a);
        assert(b);

        const char *s1 = *(const char **)a;
        const char *s2 = *(const char **)b;

        assert(s1);
        assert(s2);

        size_t size_string_s1 = strlen(s1);
        size_t size_string_s2 = strlen(s2);

        //if (size_string_s1 == 0 && size_string_s2 == 0) return 0;
        //if (size_string_s1 == 0 && size_string_s2 != 0) return -1; //проверки на NULL уже не нужны
       // if (size_string_s1 != 0 && size_string_s2 == 0) return 1;

        const char *new_s1 = s1 + size_string_s1 - 1; // обработка '\0'
        const char *new_s2 = s2 + size_string_s2 - 1; //обработка '\0'

        while (new_s1 >= s1 && new_s2 >= s2)
        { 
            while (new_s1 >= s1 && isalpha(*new_s1) == 0) new_s1--;
            while (new_s2 >= s2 && isalpha(*new_s2) == 0) new_s2--;

            if (*new_s1 != *new_s2)
            {
                return (*new_s1 < *new_s2) ? -1 : 1; 
            }
            new_s1--;
            new_s2--;
        }

        if (new_s1 < s1 && new_s2 < s2) return 0; 
        else if (new_s1 < s1) return -1;
        else if (new_s2 < s2) return 1;

        return 0;
    }

    void swap_element_array(void *a, void *b, size_t size) {
        if (a == b) return;
    
        void* temp = malloc(size);  
        memcpy(temp, a, size);
        memcpy(a, b, size);
        memcpy(b, temp, size);
    }


    void bubble_sort(WORK_TEXT *wt, int (*comparator)(const void *, const void *))
    {
        assert(wt);
        assert(wt->text_line);

        for (size_t i = 0; i < wt->line_in_file - 1; i++)
        {
            for (size_t j = 0; j < wt->line_in_file - i - 1; j++)
            {
                if (comparator(&wt->text_line[j], &wt->text_line[j + 1]) > 0)
                {
                    swap_element_array(&wt->text_line[j], &wt->text_line[j + 1], sizeof(char*));
                }
            }
        }
    }

     
    void hach_edition_qsort(void *base, size_t nmemb, size_t size, int (*comparator_hacha)(const void *, const void *)) {
        if (nmemb <= 1) return;

        char *array = (char*)base;
        size_t pivot_idx = nmemb - 1;
        size_t i = 0;

        for (size_t j = 0; j < pivot_idx; j++) {
            if (comparator_hacha(array + j*size, array + pivot_idx*size) < 0) {
                swap_element_array(array + i*size, array + j*size, size);
                i++;
            }
        }
        

        swap_element_array(array + i * size, array + pivot_idx * size, size);

        if (i > 0) 
            hach_edition_qsort(array, i, size, comparator_hacha);
        if (nmemb - i - 1 > 0)
            hach_edition_qsort(array + (i + 1) * size, nmemb - i - 1, size, comparator_hacha);
    }