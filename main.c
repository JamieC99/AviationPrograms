#include <stdio.h>
#include <windows.h>
#include "pressalt.c"

void mainMenu(void)
{
    system("cls");

    printf("AVIATION PROGRAMS\n\n");
    printf("Would calculation would you like to perform?\n\n1) Density Altitude\n2)\n3) Quit\n");

    int choice;
    scanf("%i", &choice);

    switch(choice)
    {
        case 1: densityAltitudeMenu(); break;
        case 2: break;
        case 3: exit(0);
    }
}

int main(void)
{
    mainMenu();

    return 0;
}