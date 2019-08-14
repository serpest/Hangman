#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "wordsGetter.h"

#define MAXIMUM_NUMBER_OF_MISTAKES 6 //If your number of mistakes is equal to this you lose



/*
 * It replace a char in a string.
 */
static void replaceCharInStr(char word[], const char newChar, const int index) {
	word[index] = newChar;
}

/*
 * It upgrade the shownWord using the user's newChar.
 * It returns true if the newChar is in the secretWord.
 */
static bool upgradeShownWord(char* secretWord, char shownWord[], const char newChar) {
	bool returnValue = false;
	bool currentFoundCharBool;
	char* currentSecretWord = secretWord - 1;
	do {
		currentSecretWord = strchr(currentSecretWord + 1, newChar);
		if (currentSecretWord) {
			returnValue = true;
			currentFoundCharBool = true;
			replaceCharInStr(shownWord, newChar, currentSecretWord - secretWord);
		}
		else {
			currentFoundCharBool = false;
		}
	} while (currentFoundCharBool);
	return returnValue;
}


/*
 * It manages the hangman game.
 */
void playHangmanGame(void) {
	int mistakes = 0;
	char* secretWord = getRandomWord();
	char shownWord[strlen(secretWord) + 1];
	int i;
	for (i = 0; i < strlen(secretWord); i++) {
		shownWord[i] = '-';
	}
	shownWord[strlen(secretWord)] = '\0';
	char newChar;
	bool foundWord = false;
	while (!foundWord && mistakes < MAXIMUM_NUMBER_OF_MISTAKES) {
			printf("Word: %s\nYou can do %i mistakes yet. Enter a character: ", shownWord, MAXIMUM_NUMBER_OF_MISTAKES - mistakes);
			newChar = getchar();
			while (getchar() != '\n') {};
			if (!upgradeShownWord(secretWord, shownWord, newChar)) {
					mistakes++;
			}
			if (!(strcmp(secretWord, shownWord))) {
				foundWord = true;
			}
	}
	if (foundWord) {
		printf("Word: %s\n", shownWord);
		puts("You won!");
	}
	else {
		puts("You lost.");
		printf("The secret word is %s.\n", secretWord);
	}
	closeWordsFile();
}