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
	WordStats stats;
	bool notHashtag = true;
	bool isFinished = false;
	stats = initStats(stats);
	//get userinput until they enter a '#'
	printf("Enter strings (Enter # to stop)\n");
	while(notHashtag) {
		scanf("%s", input);
		stats = updateVowelCons(stats, input);
		//add the updates here
		if(strcmp(input, hashtag) == 0) {
			notHashtag = false;
		}
	}
	//start up the menu unless an exit is called
	while(!isFinished) {
		printf("\n");
		// TODO: repeatedly print menu options and prompt for an option
		int check = getMenuOption();
		if(check == MENU_VC) {
			printVowelConsFreq(stats);
		}
		else if(check == MENU_WC) {
			printf("This is option 2!\n");
		}
		else if(check == MENU_HISTO) {
			for (int i = 0; i < ALPHABET_SIZE; ++i) {
				printf("%d", stats.histo[i]);
			}
		}
		else if(check == MENU_RET) {
			notHashtag = true;
			printf("Enter strings (Enter # to stop)\n");
			while(notHashtag) {
				scanf("%s", input);
				stats = updateVowelCons(stats, input);
				if(strcmp(input, hashtag) == 0) {
					notHashtag = false;
				}
			}	
		}
		else if(check == MENU_EXIT) {
			isFinished = true;
		}
		else {
			printf("Error: Unknown option %d. Try again!\n", check);
		}
	}
	printf("Exiting...\n");
	return 0;
}
