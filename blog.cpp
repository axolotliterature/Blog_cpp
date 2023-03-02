#include "blog.h"

void menu() {

}

//allocates for Author global variable, prompts user to input name, stores as Author var
void getName() {
    Author = (char*)malloc(sizeof(char)*BUFFER);
    if (Author == NULL) { //malloc error check
        std::cout <<"Failed to allocate: Author\n";
        exit(-1);
    }
    std::cout << "Please enter your name: ";
    std::cin >> Author;
    std::cin.ignore('\n');

}