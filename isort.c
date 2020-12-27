#include <stdio.h>
#include "isort.h"
#define ArraySize 50

// shift element function
void shift_element(int* arr, int i) {
    int t = *(arr + i);
    for(int *j = arr + i; j > arr; j--) {
        *j = *(j - 1);
    }
    *arr = t;
}


// insertion sort algorithm function
void insertion_sort(int* arr, int len) {
    for(int i = 1; i < len; i++) { 
        int t = *(arr + i);
        int j = i - 1;
        while(j >= 0 && *(arr + j) > t) { 
            *(arr + 1 + j) = *(arr + j); 
            j = j - 1; 
        }
        *(arr + 1 + j) = t; 
    }
}

// printing array function
void printArray (int* arr, int len) {
    for(int i=0; i<len; i++){
        printf("%d", *(arr+i));
        if (i !=len-1) {
            printf(",");
        }
    }
    printf("\n");
}

// main function
int main() {

    // scan 50 integer from user into arr array
    printf("Enter 50 integers:\n");
    int arr[ArraySize];
    int input = 0;
    while(input < ArraySize) {
        int input_number;
        scanf("%d", &input_number);
        *(arr + input) = input_number;
        ++input;
    }
    
    // sorting array
    insertion_sort(arr, ArraySize);

    // print array
    printArray(arr, ArraySize);
    return 0;
}