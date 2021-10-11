#include <stdio.h>

int n; // To store the users choice

int menu()
{
    /* Main Screen i.e the screen that has to be dispplayed at the first so that the user can tell the 
    system what it wants to do */

    printf("*************** C Banking System *************** \n\n");
    printf("**********  Please Select one of the option *********\n\n");
    
    printf("[1]. Create a new account\n");
    
    printf("[2]. Search for account details\n");
    
    printf("[3]. Delete/Block an account\n");
    
    printf("[4]. Show the last transactions made by the user\n");
    
    printf("-> ");
    scanf("%d", &n);
}