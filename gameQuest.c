#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 
 
/* --------------------- Game 1 : Escape Room --------------------- */ 
void game_escape_room() { 
    char guess[256]; 
 
    printf("~~~~~~~~~~~~~~ JUMBLED WORD PUZZLE ~~~~~~~~~~~~~\n"); 
    printf("Guess the correct and meaningful word from the given jumbled word.\n"); 
    printf("Jumbled word (caps): IHTSAFLHGL\n"); 
    printf("Hint: The first thing we grab when power outage happens, while cooking maggie in hostel secretly.\n"); 
 
    while (1) { 
        printf("Enter the word you have guessed: "); 
        scanf("%s", guess); 
        if (strcmp(guess, "FLASHLIGHT") == 0) { 
            printf("YAY!! You have successfully completed the first puzzle.\n"); 
            break; 
        } else { 
            printf("Wrong answer. Try again (use hint).\n"); 
        } 
    } 
 
    printf("\n~~~~~~~~~~~~~~~~~~ RIDDLE ~~~~~~~~~~~~~~~~~~~~\n"); 
    printf("I am TALL when I am YOUNG and SHORT when I am OLD; GUESS WHAT AM I?\n"); 
 
    while (1) { 
        printf("Enter your guessed answer (lowercase): "); 
        scanf("%s", guess); 
        if (strcmp(guess, "candle") == 0) { 
            printf("HOORAY!! You have solved the riddle successfully.\n"); 
            break; 
        } else { 
            printf("Wrong answer. Try again.\n"); 
        } 
    } 
 
    printf("\n~~~~~~~~~~~~~~ FINAL DOOR CODE ~~~~~~~~~~~~~\n"); 
    printf("Hint: First letters of answers of puzzle1, puzzle2 and the thing they produce.\n"); 
 
    while (1) { 
        printf("Enter the final code (CAPS): "); 
        scanf("%s", guess); 
        if (strcmp(guess, "CFL") == 0) { 
            printf("WOOHOOO!!! CONGRATULATIONS!! YOU HAVE ESCAPED THE ROOM.\n"); 
            break; 
        } else { 
            printf("Wrong code. Try again.\n"); 
        } 
    } 
} 
 
/* --------------------- Game 2 : 4-Digit Guess (Your Code Inserted) --------------------- */ 
void game_4digit_guess() { 
    int secret[4] = {9, 1, 5, 3}; // fixed secret number 9153 
    int guess[4]; 
    int i, correctPlace, correctDigit; 
    int num, tries = 0; 
 
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"); 
    printf(" Welcome to the 4-Digit Guessing Game!\n"); 
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"); 
    printf("Try to guess the secret 4-digit number. \nShhh... It's a secret!\n"); 
    printf("After each guess, you'll see:\n"); 
    printf("- Digits correct and rightly placed.\n"); 
    printf("- Digits correct but wrongly placed.\n\n"); 
    printf("Best of luck!\n\n"); 
 
    while (1) { 
        printf("Enter your 4-digit guess: "); 
        scanf("%d", &num); 
 
        // split number into digits 
        for (i = 3; i >= 0; i--) { 
            guess[i] = num % 10; 
            num /= 10; 
        } 
 
        correctPlace = 0; 
        correctDigit = 0; 
 
        int usedSecret[4] = {0}; 
        int usedGuess[4] = {0}; 
 
        // check correct places 
        for (i = 0; i < 4; i++) { 
            if (guess[i] == secret[i]) { 
                correctPlace++; 
                usedSecret[i] = 1; 
                usedGuess[i] = 1; 
            } 
        } 
 
        // check correct digits (wrong place) 
        for (i = 0; i < 4; i++) { 
            if (!usedGuess[i]) { 
                for (int j = 0; j < 4; j++) { 
                    if (!usedSecret[j] && guess[i] == secret[j]) { 
                        correctDigit++; 
                        usedSecret[j] = 1; 
                        break; 
                    } 
                } 
            } 
        } 
 
        tries++; 
        printf(" Digits in correct place: %d\n", correctPlace); 
        printf(" Digits correct but in wrong place: %d\n", correctDigit); 
        printf("----------------------------------------\n"); 
 
        if (correctPlace == 4) { 
            printf("Congratulations! You guessed it in %d tries!\n", tries); 
            printf("The secret number was: 9153\n"); 
            break; 
        } 
    } 
} 
 
/* --------------------- Game 3 : Maths Quiz  --------------------- */ 
int ask_question(int diAiculty) { 
    int a, b, ans, user; 
    char op; 
 
    if (diAiculty == 1) { a = rand()%10 + 1; b = rand()%10 + 1; } 
    else if (diAiculty == 2) { a = rand()%20 + 1; b = rand()%20 + 1; } 
    else { a = rand()%50 + 1; b = rand()%50 + 1; } 
 
    int type = rand() % 4; 
    if (type == 0) { op = '+'; ans = a + b; } 
    else if (type == 1) { op = '-'; ans = a - b; } 
    else if (type == 2) { op = '*'; ans = a * b; } 
    else { op = '/'; ans = a; a = a * b; } 
 
    printf("%d %c %d = ?  ", a, op, b); 
    scanf("%d", &user); 
 
    if (user == ans) { 
        printf("Correct!\n"); 
        return 1; 
    } else { 
        printf("Wrong! Correct answer: %d\n", ans); 
        return 0; 
    } 
} 
 
void game_maths_quiz() { 
    int diAiculty, num_questions, score = 0; 
 
    printf("Select DiAiculty (1=Easy, 2=Medium, 3=Hard): "); 
    scanf("%d", &diAiculty); 
    if (diAiculty < 1 || diAiculty > 3) { 
        printf("Invalid diAiculty. Returning to menu.\n"); 
        return; 
    } 
 
    printf("Enter number of questions: "); 
    scanf("%d", &num_questions); 
    if (num_questions <= 0) { 
        printf("Invalid number. Returning to menu.\n"); 
        return; 
    } 
 
    srand(time(NULL)); 
 
    for (int i = 0; i < num_questions; i++) { 
        printf("\nQ%d. ", i+1); 
        score += ask_question(diAiculty); 
        printf("Current score: %d\n", score); 
    } 
 
    printf("\nFinal Score: %d/%d\n", score, num_questions); 
} 
 
/* --------------------- Main Menu --------------------- */ 
int main() { 
    int ch; 
    while (1) { 
        printf("\n====================================\n"); 
        printf("          GAME MENU\n"); 
        printf("====================================\n"); 
        printf("1. Escape Room\n"); 
        printf("2. 4-Digit Guess Game\n"); 
        printf("3. Maths Quiz\n"); 
        printf("4. Exit\n"); 
        printf("Choose: "); 
        scanf("%d", &ch); 
 
        if (ch == 1) game_escape_room(); 
        else if (ch == 2) game_4digit_guess(); 
        else if (ch == 3) game_maths_quiz(); 
        else if (ch == 4) { 
            printf("Thanks for playing!\n"); 
            break; 
        } else { 
            printf("Invalid choice!\n"); 
        } 
    } 
    return 0; 
} 
 