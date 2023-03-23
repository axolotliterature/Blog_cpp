#include "blog.h"

//main menu UI andles majority of this program; loops for user selection, returning to the menu until exit is selected
void menu() {
    int choice = 0;
    while (1) {
        //MENU UI
        std::cout << "\n~=~=~=~=~=~=~=~=~=~=~=\n\n";
        std::cout << "Hello " << Author << ", what would you like to do?\n";
        std::cout << "\n1. Add Post \n2. Count Entries \n3. Print Post(s) \n4. Remove Post \n5. Exit Program \n";
        std::cout << "\n~=~=~=~=~=~=~=~=~=~=~=\n\n";
        std::cin.ignore('\n'); //clears buffer
        std::cin >> choice;
        std::cout << "\n";
        

        switch (choice) {
            case 1: //ADD POST
                addPost();
                break;
            case 2: //COUNT ENTRIES
                entryCount();
                break;
            case 3: //PRINT POSTS -- SUBMENU
                if (postStart == NULL) { //checks that start isn't null
                    std::cout << "!=========================!\n";
                    std::cout << "There are no blog post entries...\nPlease begin by adding a blog post.\n";
                    std::cout << "!=========================!\n";
                } else if (postStart != NULL) { //if blog start exists, continue
                    int selection = 0;
                    std::cout << "\n\n-=-=-=-=-=-=-=-=-=-=-=\n";
                    std::cout << "Which entries would you like to print:\n1. Print by Date\n2. Print by Title\n3. Print by Type\n4. Print all entries\n";
                    std::cout << "\n\n-=-=-=-=-=-=-=-=-=-=-=\n";
                    std::cin.ignore('\n'); //clears buffer
                    std::cin >> selection;

                    while (1) {
                        if (selection == 1) { //print by date
                            printDate(getDate());
                            break;
                        } else if (selection == 2) { //print by title
                            char titlename[BUFFER];
                            std::cout << "Title of post: ";
                            std::cin.ignore('\n'); //clears buffer
                            std::cin >> titlename;
                            printTitle(titlename);
                            break;
                        } else if (selection == 3) { //print by type                      
                            printType(getPrintType());
                            break;
                        } else if (selection == 4) { //print all
                            printAll();
                            break;
                        } else {
                            std::cout << "Invalid input of ( " << selection << " ), please enter a valid number\n";
                            std::cin.ignore('\n'); //clears buffer
                            std::cin >> selection;
                        };
                    };
                };
                break;
            case 4: //REMOVE POST
                int result;
                char postToDel[BUFFER];
                std::cout << "Please enter the title of the post you would like to remove...\n";
                std::cin >> postToDel;
                result = removePost(postToDel);
                if (result == 0) {
                    //success
                    std::cout << "Successfully removed blog post titled " << postToDel << ".\n";
                } else if (result == 1) {
                    //failed to find
                    std::cout << "Failed to find post titled " << postToDel << ".\n";
                    std::cout << "Please check spelling and try again.\n";
                } else if (result ==2) {
                    //iteration loop failed
                    std::cout << "Error: Iteration failure\n";
                } else {
                    //result is not 0-3, check removePost function returns
                    std::cout << "Error: return failure";
                }
                break;
            case 5: //EXIT PROGRAM
                freeMemory();
                exit(0);
                break;
            default: //WRONG INPUT ERROR, REPROMPTS FOR INPUT
                std::cout << "Invalid input of ( " << choice << " ), please enter a valid number\n";
        } //end switch (choice)
    } //end menu while loop
} //end menu

//allocates for Author global variable, prompts user to input name, stores as Author var
void getName() {
    Author = (char*)malloc(sizeof(char)*BUFFER);
    if (Author == NULL) { //malloc error check
        std::cout <<"Failed to allocate: Author\n";
        exit(-1);
    }
    std::cout << "Please enter your name: ";
    std::cin >> Author;
    std::cin.ignore('\n'); //clears buffer

}

//iterates through blog* list, freeing space of each previous blog
//then also frees Author and postStart
void freeMemory() {
    Blog* currentPos = postStart;
    Blog* prevPos = currentPos;

    while (currentPos != NULL) {
        prevPos = currentPos;
        currentPos = currentPos->next;
        free(prevPos->Title);
        free(prevPos->Type);
        free(prevPos->Entry);
        free(prevPos);
    }

//DEBUG CHECKS FOR above while loop and finishes frees
    if (currentPos != NULL) {
        std::cout << "Current Position has not been cleared\n";
    }
    if (Author != NULL) {
        free(Author);
    }
    if (postStart != NULL) {
        free(postStart);
    }


}