#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 6
#define MAX_WORD_LENGTH 20

void displayHangman(int attempts);
void displayWord(char word[], int length);

int main() {
    char word[MAX_WORD_LENGTH];
    char guessedWord[MAX_WORD_LENGTH];
    int wordLength;
    int tries = 0;
    int correctGuess = 0;
    char guess;

    printf("Enter the word to be guessed: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0';
    wordLength = strlen(word);

    memset(guessedWord, '_', wordLength);
    guessedWord[wordLength] = '\0';

    while (tries < MAX_TRIES && correctGuess < wordLength) {
        printf("\n");
        displayHangman(tries);
        displayWord(guessedWord, wordLength);

        printf("Enter a letter guess: ");
        guess = tolower(getchar());
        getchar();

        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess && guessedWord[i] != guess) {
                guessedWord[i] = guess;
                correctGuess++;
                found = 1;
            }
        }

        if (!found) {
            printf("Incorrect guess! Tries remaining: %d\n", MAX_TRIES - ++tries);
        }
    }

    printf("\n");
    displayHangman(tries);
    displayWord(guessedWord, wordLength);

    if (correctGuess == wordLength) {
        printf("\nCongratulations! You guessed the word correctly: %s\n", word);
    } else {
        printf("\nOops! You ran out of tries. The word was: %s\n", word);
    }

    return 0;
}

void displayHangman(int attempts) {
    printf("  _______\n");
    printf("  |/     |\n");
    printf("  |     %c%c%c\n", (attempts >= 1) ? '(' : ' ', (attempts >= 1) ? '_' : ' ', (attempts >= 1) ? ')' : ' ');
    printf("  |     %c%c%c\n", (attempts >= 3) ? '\\' : ' ', (attempts >= 2) ? '|' : ' ', (attempts >= 3) ? '/' : ' ');
    printf("  |      %c\n", (attempts >= 2) ? '|' : ' ');
    printf("  |     %c %c\n", (attempts >= 4) ? '/' : ' ', (attempts >= 4) ? '\\' : ' ');
    printf(" _|_\n\n");
}

void displayWord(char word[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%c ", word[i]);
    }
    printf("\n");
}
