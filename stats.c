
#include "stats.h"
#include <stdio.h>
#include <string.h>

/**
 * Initializes the statistics structure
 * @param st an uninitialized WordStats struct
 * @return an initialized WordStats struct 
 */
WordStats initStats(WordStats st)
{
	// TODO initialize all fields in the st struct before returning it
	for (int i = 0; i < ALPHABET_SIZE; ++i) {
		st.histo[i] = 0;
	}
	st.wordCount = 0;
	st.vowelCount = 0;
	st.consonantCount = 0;
	return st;
}

/**
 * Updates vowels and consonants in the struct
 * @param st WordStats structure
 * @param input the user-input string
 * @return an updated WordStats struct 
 */
WordStats updateVowelCons(WordStats st, const char str[])
{
	// TODO - update the vowel and consonant count
	//        in the st struct before returning it
	for (int i = 0; i < strlen(str); ++i) {
		if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
			if(str[i] == 'A' || str[i] == 'a') {
				st.vowelCount++;
			}
			else if(str[i] == 'E' || str[i] == 'e') {
				st.vowelCount++;
			}
			else if(str[i] == 'I' || str[i] == 'i') {
				st.vowelCount++;
			}
			else if(str[i] == 'O' || str[i] == 'o') {
				st.vowelCount++;
			}
			else if(str[i] == 'U' || str[i] == 'u') {
				st.vowelCount++;
			}
			else {
				st.consonantCount++;
			}
		}
		
	}
	return st;
}

/**
 * Updates word count in the struct
 * @param st 
 * @param str 
 * @return an updated WordStats struct 
 */
WordStats updateWordCount(WordStats st, const char str[])
{
	// TODO - update the word count in the st struct before returning it
	return st;
}

/**
 * Outputs vowel and consonant stats
 * @param st WordStats structure
 */
void printVowelConsFreq(WordStats st)
{
	int total = st.consonantCount + st.vowelCount;
	double vowelPercent = ((double) st.vowelCount / (double) total) * 100;
	double conPercent = ((double) st.consonantCount / (double) total) * 100;
	// TODO: print vowel and consonant frequency
	printf("Vowels: %d (%.2lf%%), ", st.vowelCount, vowelPercent);
	printf("Consonants: %d (%.2lf%%), ", st.consonantCount, conPercent);
	printf("Total: %d\n", total);
}

/**
 * Outputs word count
 * @param st WordStats structure
 */
void printWordCount(WordStats st)
{
	// TODO: prints word count
}

/**
 * Outputs histogram vertically
 * @param st WordStats structure
 */
void printHistogram(WordStats st)
{
	// TODO: Prints vertical histogram
}

/**
 * Update the histogram
 * @param histo	the histogram
 * @param str	the string used to update the histogram
 */
void updateHistogram(int histo[], const char str[])
{
	// TODO: updates the frequencies in the histogram, given the letters in the input string
}
