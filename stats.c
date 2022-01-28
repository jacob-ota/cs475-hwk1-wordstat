
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
	for (int i = 0; i < ALPHABET_SIZE; ++i)
	{
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
	for (int i = 0; i < strlen(str); ++i)
	{
		//check if the str spot is an actual letter
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			//add to vowels if it is a vowel
			if (str[i] == 'A' || str[i] == 'a')
			{
				st.vowelCount++;
			}
			else if (str[i] == 'E' || str[i] == 'e')
			{
				st.vowelCount++;
			}
			else if (str[i] == 'I' || str[i] == 'i')
			{
				st.vowelCount++;
			}
			else if (str[i] == 'O' || str[i] == 'o')
			{
				st.vowelCount++;
			}
			else if (str[i] == 'U' || str[i] == 'u')
			{
				st.vowelCount++;
			}
			//add to consonant if not a vowel
			else
			{
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
	//word must start with a letter then it is considered a word
	if ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z'))
	{
		st.wordCount++;
	}
	return st;
}

/**
 * Outputs vowel and consonant stats
 * @param st WordStats structure
 */
void printVowelConsFreq(WordStats st)
{
	//get total of vowels and consonants
	int total = st.consonantCount + st.vowelCount;
	//get the frequencies in percentages
	double vowelPercent = ((double)st.vowelCount / (double)total) * 100;
	double conPercent = ((double)st.consonantCount / (double)total) * 100;
	// TODO: print vowel and consonant frequency
	printf("Vowels = %d (%.2lf%%), ", st.vowelCount, vowelPercent);
	printf("Consonants = %d (%.2lf%%), ", st.consonantCount, conPercent);
	printf("Total = %d\n", total);
}

/**
 * Outputs word count
 * @param st WordStats structure
 */
void printWordCount(WordStats st)
{
	// TODO: prints word count
	printf("Words: %d\n", st.wordCount);
}

/**
 * Outputs histogram vertically
 * @param st WordStats structure
 */
void printHistogram(WordStats st)
{
	// TODO: Prints vertical histogram
	char alphabet[ALPHABET_SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	int maxNum = st.histo[0];
	//get the most frequent letter of the histogram
	for (int i = 0; i < ALPHABET_SIZE; ++i)
	{
		if (st.histo[i] >= maxNum)
		{
			maxNum = st.histo[i];
		}
	}
	//use the maxNum to start the vertical printing of *
	for (int i = maxNum; i > 0; --i)
	{
		for (int j = 0; j < ALPHABET_SIZE; ++j)
		{
			//print a * in that row if there is that freq of letter
			if (st.histo[j] >= i)
			{
				printf("* ");
			}
			//else just print a space
			else
			{
				printf("  ");
			}
		}
		//go to next row
		printf("\n");
	}
	//print the alphabet
	for (int i = 0; i < ALPHABET_SIZE; ++i)
	{
		printf("%c ", alphabet[i]);
	}
	printf("\n");
	//print the frequency of letters
	for (int i = 0; i < ALPHABET_SIZE; ++i)
	{
		printf("%d ", st.histo[i]);
	}
	printf("\n");
}

/**
 * Update the histogram
 * @param histo	the histogram
 * @param str	the string used to update the histogram
 */
void updateHistogram(int histo[], const char str[])
{
	// TODO: updates the frequencies in the histogram, given the letters in the input string
	for (int i = 0; i < strlen(str); ++i)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			//Do all the letters in the alphabet and
			//add 1 to the frequency array if letter matches
			if (str[i] == 'A' || str[i] == 'a')
			{
				histo[0] = histo[0] + 1;
			}
			else if (str[i] == 'B' || str[i] == 'b')
			{
				histo[1] = histo[1] + 1;
			}
			else if (str[i] == 'C' || str[i] == 'c')
			{
				histo[2] = histo[2] + 1;
			}
			else if (str[i] == 'D' || str[i] == 'd')
			{
				histo[3] = histo[3] + 1;
			}
			else if (str[i] == 'E' || str[i] == 'e')
			{
				histo[4] = histo[4] + 1;
			}
			else if (str[i] == 'F' || str[i] == 'f')
			{
				histo[5] = histo[5] + 1;
			}
			else if (str[i] == 'G' || str[i] == 'g')
			{
				histo[6] = histo[6] + 1;
			}
			else if (str[i] == 'H' || str[i] == 'h')
			{
				histo[7] = histo[7] + 1;
			}
			else if (str[i] == 'I' || str[i] == 'i')
			{
				histo[8] = histo[8] + 1;
			}
			else if (str[i] == 'J' || str[i] == 'j')
			{
				histo[9] = histo[9] + 1;
			}
			else if (str[i] == 'K' || str[i] == 'k')
			{
				histo[10] = histo[10] + 1;
			}
			else if (str[i] == 'L' || str[i] == 'l')
			{
				histo[11] = histo[11] + 1;
			}
			else if (str[i] == 'M' || str[i] == 'm')
			{
				histo[12] = histo[12] + 1;
			}
			else if (str[i] == 'N' || str[i] == 'n')
			{
				histo[13] = histo[13] + 1;
			}
			else if (str[i] == 'O' || str[i] == 'o')
			{
				histo[14] = histo[14] + 1;
			}
			else if (str[i] == 'P' || str[i] == 'p')
			{
				histo[15] = histo[15] + 1;
			}
			else if (str[i] == 'Q' || str[i] == 'q')
			{
				histo[16] = histo[16] + 1;
			}
			else if (str[i] == 'R' || str[i] == 'r')
			{
				histo[17] = histo[17] + 1;
			}
			else if (str[i] == 'S' || str[i] == 's')
			{
				histo[18] = histo[18] + 1;
			}
			else if (str[i] == 'T' || str[i] == 't')
			{
				histo[19] = histo[19] + 1;
			}
			else if (str[i] == 'U' || str[i] == 'u')
			{
				histo[20] = histo[20] + 1;
			}
			else if (str[i] == 'V' || str[i] == 'v')
			{
				histo[21] = histo[21] + 1;
			}
			else if (str[i] == 'W' || str[i] == 'w')
			{
				histo[22] = histo[22] + 1;
			}
			else if (str[i] == 'X' || str[i] == 'x')
			{
				histo[23] = histo[23] + 1;
			}
			else if (str[i] == 'Y' || str[i] == 'y')
			{
				histo[24] = histo[24] + 1;
			}
			else
			{
				histo[25] = histo[25] + 1;
			}
		}
	}
}