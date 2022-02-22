/**
 * @file main.c
 * @author vinay mathad (vinay.mathad@ltts.com)
 * @brief main fuction is written
 * @version 0.1
 * @date 2022-02-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"  // user defined header file
extern void test_main();
int main()
{
    // #if 0 // Uncomment while Unit testing
    retriveFromFile();
    char input[50];
    int user_choice;
    while(1)
    {
        printf("\nBike Records\n\n");
        printf("    1. Add a BikeName\n");
        printf("    2. Display Records\n");
        printf("    3. Delete a BikeRecord \n");
        printf("    4. Save Records\n");
        printf("    5. Exit\n");
        
        do {
            printf("\nEnter your choice: \n");
            fgets(input,50,stdin);
            user_choice = atoi(input);
        } 
        while (user_choice < 1 || user_choice > 5);

        switch(user_choice)
        {
        case 1:
            addBikeName ();
            break;
        case 2:
            displayAllRecords();
            break;
            
        case 3:
            printf("Please enter the name of the bike to delete \n");
            fgets(input,50,stdin);
            removeContact(input);
            break;
        case 4:
            storeToFile();
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    }
    // Uncomment next 3 lines while unit testing
    /* #else
    test_main();
    #endif*/
    return 0;
}