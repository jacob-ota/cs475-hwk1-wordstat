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
	char *space;
	WordStats stats;
	bool notHashtag = true;
	bool isFinished = false;
	stats = initStats(stats);
	//get userinput until they enter a '#'
	printf("Enter strings (Enter # to stop)\n");
	while(notHashtag) {
		scanf("%s", input);
		//update the stats and delimit spaces
		space = strtok(input, " ");
		while(space != NULL) {
			stats = updateVowelCons(stats, input);
			stats = updateWordCount(stats, input);
			updateHistogram(stats.histo, input);
			space = strtok(NULL, " ");
		}
		//end on a hashtag
		if(strcmp(input, hashtag) == 0) {
			notHashtag = false;
		}
	}
	//start up the menu unless an exit is called
	while(!isFinished) {
		printf("\n");
		// TODO: repeatedly print menu options and prompt for an option
		int check = getMenuOption();
		//check the menu input and print out the correct stats for that input
		if(check == MENU_VC) { //#1
			printVowelConsFreq(stats);
		}
		else if(check == MENU_WC) { //#2
			printWordCount(stats);
		}
		else if(check == MENU_HISTO) { //#3
			printHistogram(stats);
		}
		else if(check == MENU_RET) { //#4
			notHashtag = true;
			printf("Enter strings (Enter # to stop)\n");
			while(notHashtag) {
				scanf("%s", input);
				space = strtok(input, " ");
				while(space != NULL) {
					stats = updateVowelCons(stats, input);
					stats = updateWordCount(stats, input);
					updateHistogram(stats.histo, input);
					space = strtok(NULL, " ");
				}
				if(strcmp(input, hashtag) == 0) {
					notHashtag = false;
				}
			}	
		}
		else if(check == MENU_EXIT) { //#5
			isFinished = true;
		}
		else { //if the user puts a bad input
			printf("Error: Unknown option %d. Try again!\n", check);
		}
	}
	printf("Exiting...\n");
	return 0;
}
