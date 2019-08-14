#include <stdio.h>
#include <stdlib.h>
#include "hangmanGame.h"

int main(void) {
	while(1) {
		puts("+++ HANGMAN +++");
		playHangmanGame();
		puts("\n\n");
	}
	system("pause");
	return 0;
}