#include <stdio.h>

FILE *fp;

int get_water();
void print_logo();
void print_welcome();

int main(void) {
    int repeat = 1;

    while(repeat) {
        int code;
        print_logo();
        print_welcome();

        printf("What do you want to do? ");
        scanf("%d", &code);

        if (code == 0) {
            int water = get_water();
            printf("Today you drank %d glasses of water.\n", water);
            
            if(water < 6) {
                printf("Keep going and achieve your target of at least 6 water per day.\n");
            } else {
                printf("Congrats! you have achieved your today's target.\n");
            }
        } else if (code == 1) {
            int water = get_water();
            fp = fopen("./data.txt", "w");
            fprintf(fp, "%d", water+1);
            fclose(fp);
            printf("\nCongrats for +1 water in your day.\n");
            printf("So far you have drank %d glasses of water today.\n", water);
        } else {
            continue;
        }

        char c;
        printf("Do you want to start again (y/n)? ");
        scanf(" %c", &c);
        if(c == 'y') repeat = 1; else repeat = 0;
    }
    return 0;
}

void print_logo() {
    printf("88       88  88        88  888888888     888888888888  888888888888  888888888888  8888888888\n"); 
    printf("88       88   88      88   88      88    88        88  88        88       88       88        \n");
    printf("88       88    88    88    88       88   88        88  88        88       88       88        \n");
    printf("88       88     88  88     88        88  88        88  88        88       88       88        \n");
    printf("88888888888      8888      88        88  888888888888  888888888888       88       888888888 \n");
    printf("88       88       88       88        88  88888         88        88       88       88        \n");
    printf("88       88       88       88       88   88  888       88        88       88       88        \n");
    printf("88       88       88       88      88    88    888     88        88       88       88        \n");
    printf("88       88       88       888888888     88      8888  88        88       88       8888888888\n");
    printf("\n--------------------------------------------------------------------------------------------------\n\n\n");
}

void print_welcome() {
    printf("welcome to hydrate!!\n");
    printf("What do you want to do today? See the reference below for code.\n");
    printf("\t0 => See total amount of water drank today,\n");
    printf("\t1 => Add another glass of water,\n\n");
}

int get_water() {
    fp = fopen("./data.txt", "r");

    if(fp == NULL) {
        printf("\nFile not found.\n");
        return 0;
    }

    int water;
    fscanf(fp, "%d", &water);
    fclose(fp);
    return water;
}