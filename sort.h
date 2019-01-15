#include <stdio.h>

#ifndef DSV_STRING_READER_H
#define DSV_STRING_READER_H

#endif //DSV_STRING_READER_H

//File stream function
void file_reader(char  * stream, Vector *v);

// qsort string comparison function
int string_cmp(const void *a, const void *b);

//sorting function using qsort
void sort_n_print(Vector *v);