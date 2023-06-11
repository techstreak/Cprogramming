#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
// Seed the random number generator
srand(time(0));

// Generate a random number
//between 1 and 10 for player and dealer

int playerCard = rand() % 10 + 1;
int dealerCard = rand() % 10 + 1;

// Calculate the initial scores
int playerScore = playerCard;
int dealerScore = dealerCard;

printf("Welcome to Blackjack!\n\n");

// Player's turn
printf("Player's turn:\n");
printf("Your card: %d\n", playerCard);

char choice;
printf("Do you want to hit (h) or stand (s)? ");
scanf(" %c", &choice);

if (choice == 'h') {
// Draw another card
int newCard = rand() % 10 + 1;
printf("New card: %d\n", newCard);

playerScore += newCard;
printf("Player's score: %d\n", playerScore);
}

    // Dealer's turn
printf("\nDealer's turn:\n");
printf("Dealer's card: %d\n", dealerCard);

while (dealerScore < 17) {
// Draw another card for the dealer
int newCard = rand() % 10 + 1;
printf("New card: %d\n", newCard);

dealerScore += newCard;
printf("Dealer's score: %d\n", dealerScore);
    }

// Determine the winner
printf("\nResults:\n");
printf("Player's score: %d\n", playerScore);
printf("Dealer's score: %d\n", dealerScore);

if (playerScore > 21) {
printf("Player busts! Dealer wins.\n");
} else if (dealerScore > 21) {
printf("Dealer busts! Player wins.\n");
} else if (playerScore > dealerScore) {
printf("Player wins!\n");
} else if (playerScore < dealerScore) {
printf("Dealer wins!\n");
} else {
printf("It's a tie!\n");
}

return 0;
}