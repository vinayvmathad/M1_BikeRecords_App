/**
 * @file function.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include "main.h"
void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
    long int recsize; /// size of each record of bikelist
     FILE *fp, *ft; /// file pointers
    char another, choice;
    struct biker{
        char bikename[40]; ///name of bike
        int year; /// manufacture/production of bike
        int cc; /// cubic capacity of the bike
    };
    struct biker b; /// structure variable creation
 
 void  Add_BikeRecord(){
     fseek(fp,0,SEEK_END); /// search the file and move cursor to end of the file
                          /// here 0 indicates moving 0 distance from the end of the file
             another = 'y';
                while(another == 'y'){ /// if user want to add another record
                    flush();
                    printf("\nEnter bikename: ");
                    fgets(b.bikename, 40, stdin);
                    printf("\nEnter year: ");
                    scanf("%d", &b.year);
                    printf("\nEnter cubic capcity: ");
                    scanf("%d", &b.cc);
 
                    fwrite(&b,recsize,1,fp); /// write the record in the file
 
                    printf("\nAdd another record(y/n) ");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }
   
            
 }
 
 



 