#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

#define VECTOR_INITIAL_CAPACITY 10


// Initialize a vector to be empty
// Pre: 'vector' != NULL
void vector_init(Vector *vector){
    vector->value = malloc(sizeof(char *) * vector->capacity);
    vector->capacity = VECTOR_INITIAL_CAPACITY;
    vector->size = 0;
};


// Deallocate internal structures of the vector
// Note: the user is responsible for deleting all values
// Note: the user is responsible for deleting the actual vector if it was dynamically allocated
void vector_delete(Vector *vector){
    free(&vector->capacity); // free allocated memory
};


static void vector_resize(Vector *vector, int capacity){
    void *value = realloc(vector->value, sizeof(void *) * capacity); // Using realloc for resizing array size
    if (value != NULL){ // error handling
        vector->value = value;// setting new value
        vector->capacity = capacity;// setting new value
    }
};


// Insert a new element at the end of the vector
// Pre: 'vector' != NULL
void vector_push(Vector *vector, void *value){
    if (vector->capacity == vector->size && vector->size != 0)//Partially error handling and meeting conditions
            vector_resize(vector, vector->capacity * 2 ); // The strategic of array size 2n if capacity exceeded
    vector->value[vector->size++] = value; // setting new size of value
};


// Remove the last element in the vector and return the value
// Pre: the vector is non-empty, 'vector' != NULL
void *vector_pop(Vector *vector){
    char * LastValue; //setting up last value in array
    LastValue = vector->value[vector->size-1]; // getting the n-1 value from array
    if(LastValue != 0) // error handling
        vector->size--; // decrement size of vector
        return LastValue;
};


// Return the number of elements in the vector
// Pre: 'vector' != NULL
size_t vector_size(const Vector *vector){
    if(vector->size != 0)// error handling
        return vector->size;  //Returning size of vector
    return 0;
};


// Return the current capacity of the vector
// Pre: 'vector' != NULL
size_t vector_capacity(const Vector *vector){
    if(vector->capacity != 0)// error handling
        return vector->capacity; //Returning capacity level
    return 0;
};


// Return the value at the given index
// Pre: index < vector_size(vector)
void *vector_get_element(const Vector *vector, size_t index){
    if( index < vector->size) //setting conditions on when to return element
        return vector->value[index]; //Returning element from value array
    return NULL;
};


// Return a pointer to the underlying array
void **vector_get_array(const Vector *vector){
    return (void*)vector->value; //returning pointer to the top of vector array
};
