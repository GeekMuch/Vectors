#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vector.h"
#include "string_reader.h"


// Reading and pushing string to vector after splitting each string from newlines
void file_reader(char *stream, Vector *v){

    FILE * fileO;
    fileO = fopen(stream, "r");//setting file to variable

    char * x = malloc(500); // allocating space for string
    char * token ;
    while(fgets(x, 500, fileO) != NULL ) { //Getting each line of file

        token = strtok (x , "\n"); // use the delimiter to sanitize the string from newline

        //Looping through token with strings, and splitting them to new sanitized strings
        for (token = strtok (x , "\n");token != NULL; token = strtok (NULL, "\n")) {
            vector_push (v , token);// pushing string into vector array
            x = malloc (500);// allocating new space for string
        }
    }
};


//A string comparator for sorting the vector array
int string_cmp(const void *a, const void *b) {
    const char **x = (const char **) a;
    const char **y = (const char **) b;
    return strcmp(*x, *y);
}


// sorting and print function
void sort_n_print(Vector *v){
    int i;

    // Utilizing qsort for sorting the array, with help from string_cmp
    qsort(v->value,v->size,sizeof(char*),string_cmp);// sorting

    printf("\n****Sorted List*****\n");

    // Printing elements in sorted vector array
    for(i=0; i < v->size; i++)
        printf("%s \n", (char * ) vector_get_element(v, i));


};

/*  Main function */
int main(int argc, char* argv[]){
    int i;
    Vector v;
    vector_init(&v);

    file_reader(argv[1], &v);// Read file function

    sort_n_print(&v); // sorting function
};
