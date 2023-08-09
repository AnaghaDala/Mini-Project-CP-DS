#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 100

// Function to generate a random character from a given character array
char getRandomCharacter(const char *characters, int numCharacters) {
    return characters[rand() % numCharacters];
}

int main() {
    int numLetters, numCharacters, numNumbers;
    char password[MAX_PASSWORD_LENGTH + 1];
    const char *numbers = "0123456789";
    const char *letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *specialCharacters = "!@#$^&*()_+";

    srand((unsigned int)(time(NULL)));

    printf("Enter the number of letters you need: ");
    scanf("%d", &numLetters);
    printf("Enter the number of characters you need: ");
    scanf("%d", &numCharacters);
    printf("Enter the number of numbers you need: ");
    scanf("%d", &numNumbers);

    if (numLetters + numCharacters + numNumbers > MAX_PASSWORD_LENGTH) {
        printf("Error: Total password length exceeds maximum limit.\n");
        return 1;
    }

    int index = 0;

    for (int i = 0; i < numLetters; i++) {
        password[index++] = getRandomCharacter(letters, 52);
    }

    for (int i = 0; i < numCharacters; i++) {
        password[index++] = getRandomCharacter(specialCharacters, 10);
    }

    for (int i = 0; i < numNumbers; i++) {
        password[index++] = getRandomCharacter(numbers, 10);
    }

    password[index] = '\0'; // Null-terminate the password string

    printf("Generated password: %s\n", password);

    return 0;
}
