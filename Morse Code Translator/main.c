/******************************************************************************************************
*   Program name: main.c,
*   Author name: NiyojOli (https://www.github.com/niyoj),
*   Created Path: /Morse Code Translator/main.c,
*   Created Date: 13 Oct 2021, 01:14:34 (DD MON YYYY, HH:MM:SS),
*   Description: This  program is used to translate the morse code to english language.
*******************************************************************************************************/

/*
Morse Code translator is used to translate the morse code input by the user to english language.

Note that: . symbolizes dot in morse code and - symbolizes the dash in morse code.
            Also you should use space after every code
*/

char A[] = ".-";
char B[] = "-...";
char C[] = "-.-.";
char D[] = "-..";
char E[] = ".";
char F[] = "..-.";
char G[] = "--.";
char H[] = "....";
char I[] = "..";
char J[] = ".---";
char K[] = "-.-";
char L[] = ".-..";
char M[] = "--";
char N[] = "-.";
char O[] = "---";
char P[] = ".--.";
char Q[] = "--.-";
char R[] = ".-.";
char S[] = "...";
char T[] = "-";
char U[] = "..-";
char V[] = "...-";
char W[] = ".--";
char X[] = "-..-";
char Y[] = "-.--";
char Z[] = "--..";

char N1[] = ".----";
char N2[] = "..---";
char N3[] = "...--";
char N4[] = "....-";
char N5[] = ".....";
char N6[] = "-....";
char N7[] = "--...";
char N8[] = "---..";
char N9[] = "----.";
char N0[] = "-----";

#include <stdio.h>
#include <termios.h>
#include <string.h>

#define MAX_LETTER 1000                     //maximum amount of the letter that the program can hold. Configure it

static struct termios old, current;

//Initialize new terminal i/o settings
void initTermios() {
    tcgetattr(0, &old);                     //grab old terminal i/o settings 
    current = old;                          //make new settings same as old settings
    current.c_lflag &= ~ICANON;             //disable buffered i/o
    current.c_lflag |= ECHO;                //set echo mode
    tcsetattr(0, TCSANOW, &current);        //use these new terminal i/o settings now
}

//Restore old terminal i/o settings
void resetTermios(void) {
    tcsetattr(0, TCSANOW, &old);
}

//Read 1 character - echo defines echo mode
char getch() {
    char ch;
    initTermios();
    ch = getchar();
    resetTermios();
    return ch;
}

char translate_morse();

int main(void) {
    printf("\n Welcome to the Morse Code Translator.\n\n");
    printf("Start typing the morse code here (dot = . and dash = -): ");
    
    char output[MAX_LETTER] = {};
    char temp[6] = {};
    int i=0, j=0;

    char c;
    while((c = getch()) != '*') {
        if(c == ' ' || c == '\n') {
            temp[i] = '\0';
            output[j] = translate_morse(temp);
            j++;
            i = 0;
            strcpy(temp, "");
        } else {
            temp[i] = c;
            i++;
        }

        if (c == '\n') {
            break;
        }
    }

    printf("The word is: %s.\n", output);

    return 0;       //Keeping the compiler happy
}

char translate_morse(char morse[]) {
    if(strcmp(A, morse) == 0){
        return 'A';
    } else if (strcmp(B, morse) == 0) {
        return 'B';
    } else if (strcmp(C, morse) == 0) {
        return 'C';
    } else if (strcmp(D, morse) == 0) {
        return 'D';
    } else if (strcmp(E, morse) == 0) {
        return 'E';
    } else if (strcmp(F, morse) == 0) {
        return 'F';
    } else if (strcmp(G, morse) == 0) {
        return 'G';
    } else if (strcmp(H, morse) == 0) {
        return 'H';
    } else if (strcmp(I, morse) == 0) {
        return 'I';
    } else if (strcmp(J, morse) == 0) {
        return 'J';
    } else if (strcmp(K, morse) == 0) {
        return 'K';
    } else if (strcmp(L, morse) == 0) {
        return 'M';
    } else if (strcmp(N, morse) == 0) {
        return 'N';
    } else if (strcmp(O, morse) == 0) {
        return 'O';
    } else if (strcmp(P, morse) == 0) {
        return 'P';
    } else if (strcmp(Q, morse) == 0) {
        return 'Q';
    } else if (strcmp(R, morse) == 0) {
        return 'R';
    } else if (strcmp(S, morse) == 0) {
        return 'S';
    } else if (strcmp(T, morse) == 0) {
        return 'T';
    } else if (strcmp(U, morse) == 0) {
        return 'U';
    } else if (strcmp(V, morse) == 0) {
        return 'V';
    } else if (strcmp(W, morse) == 0) {
        return 'W';
    } else if (strcmp(X, morse) == 0) {
        return 'X';
    } else if (strcmp(Y, morse) == 0) {
        return 'Y';
    } else if (strcmp(Z, morse) == 0) {
        return 'Z';
    } else if (strcmp(N0, morse) == 0) {
        return '0';
    } else if (strcmp(N1, morse) == 0) {
        return '1';
    } else if (strcmp(N2, morse) == 0) {
        return '2';
    } else if (strcmp(N3, morse) == 0) {
        return '3';
    } else if (strcmp(N4, morse) == 0) {
        return '4';
    } else if (strcmp(N5, morse) == 0) {
        return '5';
    } else if (strcmp(N6, morse) == 0) {
        return '6';
    } else if (strcmp(N7, morse) == 0) {
        return '7';
    } else if (strcmp(N8, morse) == 0) {
        return '8';
    } else if (strcmp(N9, morse) == 0) {
        return '9';
    } else {
        return '\0';
    }
}