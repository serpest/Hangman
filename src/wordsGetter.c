#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#define WORDS_FILE_PATH "res/words.txt"
#define WORDS_COUNT 10
#define MAXIMUM_WORD_LENGTH 9 //"\n" must be included



static FILE* wordsFile = NULL;



/*
 * It removes the new line charapter from the str.
 */
static void removeNewLineFromStr(char* str) {
	str = strtok(str, "\r\n");
}

/*
 * It opens the wordsFile in read mode.
 * If the file doesn't exists it exits.
 */
static void openWordsFile(void) {
	wordsFile = fopen(WORDS_FILE_PATH, "r");
	assert(wordsFile && "Words file not found");
}

/*
 * It returns the Nth file's word, where N is the line index.
 */
static char* getWord(const int lineIndex) {
	if (!wordsFile) {
		openWordsFile();
	}
	size_t maxWordSize = (MAXIMUM_WORD_LENGTH + 1) * sizeof(char);
	char* word = malloc(maxWordSize);
	assert(word && "word is NULL");
	int i;
	for (i = 0; i <= lineIndex; i++) {
		getline(&word, &maxWordSize, wordsFile);
	}
	removeNewLineFromStr(word);
	return word;
}



/*
 * It returns a random word from the wordsFile.
 */
char* getRandomWord(void) {
	srand(time(NULL));
	return getWord(rand() % WORDS_COUNT);
}

/*
 * It closes the wordsFile.
 */
void closeWordsFile(void) {
	fclose(wordsFile);
	wordsFile = NULL;
}