#ifndef TXTFIND_H
#define TXTFIND_H
#define LINE 256
#define WORD 30
#define MAX_TEXT_LINES 250

int word_length(char* s);
int line_length(char* s);
int similar(char* s, char* line, int index, int length);
int similar_sub(char* word,char* line, int index, int length);
void print_word(char* text, int index, int length);
void check_words(char s[],int length);
void print_line(char word[], int len);

#endif