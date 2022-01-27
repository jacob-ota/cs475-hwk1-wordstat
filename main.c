#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
#include "stats.h"
#include "menu.h"

#define MAX_INPUT_LEN 128 /** maximum length of input users can enter */

/**
 * Main function
 * 
 * @param argc the number of command line arguments (ignore for this assignment)
 * @param argv an array of command line arguments (ignore for this assignment)
 */
int main(int argc, char **argv)
{
	char input[MAX_INPUT_LEN]; //holds user-input string
	char hashtag[MAX_INPUT_LEN] = "#";
	bool notHashtag = true;
	bool isFinished = false;
	//get userinput until they enter a '#'
	printf("Enter strings (Enter # to stop)\n");
	while(notHashtag) {
		scanf("%s", input);
		if(strcmp(input, hashtag) == 0) {
			printf("Move to menu \n");
			notHashtag = false;
		}
	}
	//start up the menu unless an exit is called
	while(!isFinished) {
		printf("\n");
		// TODO: repeatedly print menu options and prompt for an option
		int check = getMenuOption();
		if(check == 1) {
			printf("This is option 1!\n");
		}
		else if(check == 2) {
			printf("This is option 2!\n");
		}
		else if(check == 3) {
			printf("This is option 3!\n");
		}
		else if(check == 4) {
			printf("This is option 4!\n");
		}
		else if(check == 5) {
			isFinished = true;
		}
		else {
			printf("Error: Unknown option %d. Try again!\n", check);
		}
		// TODO: display the proper output
	}

	printf("Exiting...\n");
	return 0;
}
