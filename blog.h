#ifndef HEADER_FILE
#define HEADER_FILE

#include <iostream>
#define BUFFER 100
#define ENTRYBUFFER 500

//==================================== STRUCTURES AND GLOBAL VARIABLES

typedef struct Blog Blog;
struct Blog {
    int Date;
    char* Title;
    char* Type; //Diary, Hobby, Journalism, Art
    char* Entry;
    Blog* next;
};

extern struct Blog* postStart;
extern char* Author;

//==================================== FUNCTION PROTOTYPES

//==================================== MY FUNCTIONS (change this title please ffs)

void menu();
void getName();

#endif