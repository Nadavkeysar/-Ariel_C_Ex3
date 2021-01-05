#include "txtfind.h"
#include <stdio.h>
#include <string.h>
#define LINE_SIZE 256
#define MAX_WORD_SIZE 30
#define MAX_LINES_SIZE 250

// getting the length of a word
int word_length(char* s) {
    for(int length = 0; length < MAX_WORD_SIZE; ++length) {
        if(*(s + length) == ' ' || *(s + length) == '\n' || *(s + length) == '\t' || *(s + length) == '\0') {
            return length;
        }
    }
    return MAX_WORD_SIZE;
}

// getting the length of a line
int line_length(char* s) {
    for(int length = 0; length < MAX_WORD_SIZE; ++length) {
        if(*(s + length)=='\n' || *(s + length) == EOF) {
            return length;
        }   
    }
    return LINE_SIZE;
}

// checking if word is similar to another word
int similar(char* s, char* line, int index, int length) {
    for(int i = 0; i < length; ++i) {
        if(*(line + index + i) != *(s + i)) {
            return 0;
        }
    }
    return 1;
}

// checking if word is similar to another word
int similar_sub(char* word,char* line, int index, int length){
    char s[length];
    for(int i =0; i < length; ++i) {
        if(*(line + index + i) == *(word + i) ){
            *(s + i) = *(line + index + i);
        } else if(*(line + index + i) != *(word + i) && *(line + index + i + 1) == *(word + i)) {
            *(s + i) = *(line + index + i + 1);
        } else if(*(line + index + i) != *(word + i) && *(line + index + i + 1) != *(word + i)) {
            return 0;
        }
    }
    return similar(word, s, 0, length);
}

// print a word
void print_word(char* text, int index, int length){
    for(int j = 0; j < length + 1; ++j) {
        printf("%c", *(text + index + j));
    }
    printf("\n");
}

// checking the given words
void check_words(char s[],int length){
    char text[MAX_LINES_SIZE * LINE_SIZE];
    while(fgets(text, MAX_LINES_SIZE * LINE_SIZE, stdin)){
        int line = line_length(text);
        for(int i = 0; i < line; ++i) {
            if(similar(s,text, i, length)) {
                print_word(text, i, length);
                break;
            } else if(similar_sub(s, text,i,length)) {
                print_word(text, i, length);
            }

            i += word_length(text + i);
        }
    }
}

// print a line string
void print_line(char word[], int len) {
    char text[MAX_LINES_SIZE * LINE_SIZE];
    while(fgets(text, MAX_LINES_SIZE * LINE_SIZE, stdin)) {
        int line = line_length(text);
        for (int i = 0; i < line; ++i) {
            if(similar(word,text, i, len)){
                printf(" %s", text);
                break;
            }
            i += word_length(text+i);
        }
    }
}

//main function
int main() {

    // all the text
    char text[MAX_LINES_SIZE * LINE_SIZE];

    // gettting the first word
    fgets(text,  MAX_LINES_SIZE * LINE_SIZE, stdin);

    // getting the length of the first word
    int length = word_length(text);

    // making the first word be a string
    char word[length];
    for (int i = 0; i < length; ++i) {
        *(word + i) = *(text + i);
    }

    // option a
    if(*(text + length + 1) == 'a') {

        // print line by option a
        print_line(word, length);
    
    // option b
    } else if(*(text + length + 1) == 'b') {

        // checking similer words by option b
        check_words(word, length);
    }
}
