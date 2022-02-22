/**
 * @file function.c
 * @author vinay mathad (vinay.mathad@ltts.com)
 * @brief all the functions are written hear
 * @version 0.1
 * @date 2022-02-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_size 100
int currentSize = 0; //current no. of bike records

Bike bikes[MAX_size]; // array of structure

int addBikeName()
{
    if(currentSize == MAX_size) 
    {
        printf("\nRecord List Full\n");
        return 0;
    }
    else
    {
    Bike* b1;
    b1 = (Bike*)(malloc(sizeof(Bike)));
        int flag=0;
        printf("\n BikeName: ");
        fgets(b1->BikeName,25,stdin);
        printf("\n Year: ");
        fgets(b1->Year,11,stdin);
        printf("\n CC: ");
        fgets(b1->CC,50,stdin);
        bikes[currentSize] = *b1;
        ++currentSize;
        printf("\nBikeRecord sucessfully added.\n");
        free(b1);
    }
}

int displayRecord(int i)
{
    if(i < 0 || i >= currentSize) 
    {
        printf("\nInvalid index entered");
        return 0;
    }
    Bike* b1 = &bikes[i];
    printf("\nBikeName: %s\n", b1->BikeName);
    printf("Year : %s\n", b1->Year);
    printf("CC : %s\n\n",b1->CC);
    return 1;
}

int displayAllRecords()
{
    if(currentSize == 0) 
    {
        printf("\nNo Existing Record\n");
        return 0;
    }
    int k;
    for(k = 0;k< currentSize; k++)
    {
        displayRecord(k);
        printf("\n");
    }
}


int removeContact(char *BikeName)
{
    if(currentSize == 0) 
    {
        printf("\nBike records is empty, Cannot delete anything\n");
        return 0;
    }
    int i, j;
    int cnt = 0;
    for(i=0; i<currentSize; i++) 
    {
        if(strcmp(bikes[i].BikeName, BikeName) == 0) 
        {
            for(j=i; j<currentSize-1; j++) 
            {
                bikes[j] = bikes[j+1];
            }
            strcpy(bikes[j].BikeName, "");
            strcpy(bikes[j].Year, "");
            strcpy(bikes[j].CC, "");
            currentSize -= 1;
            ++cnt;
        }
    }
    if(cnt == 0) 
    {
        printf("\nNo Records is deleted\n");
    }
    else 
    {
        printf("%d Records deleted\n", cnt);
    }
}
int retriveFromFile()
{
    FILE *fp;
    if((fp = fopen("Bike_records.txt", "r")) == NULL) 
    {
        printf("\nError: Cannot load the Bike record file\n");
        return 5;
    }

    /* read the size of the bike record */
    if(fread(&currentSize, sizeof(currentSize), 1, fp) != 1) 
    {
        printf("\nError, Cannot read data\n");
        return 3;
    }

    /* read the actual bike record */
    if(fread(bikes, sizeof(bikes), 1, fp) != 1) 
    {
        printf("\nError, Cannot read data\n");
        return 4;
    }
    fclose(fp);
    return 5;

}
int storeToFile()
{
    FILE *fp;
    if( (fp = fopen("Bike_Records.txt", "w")) == NULL ) 
    {
        printf("\nCannot create bike record file\n");
        return 2;
    }

    /* Save the current size of the bike records */
    if (fwrite(&currentSize, sizeof(currentSize), 1, fp) != 1 ) 
    {
        printf("\nCannot save the contact\n");
        return 3;
    }
    /* save the bike records */
    if(fwrite(bikes, sizeof(bikes), 1, fp) != 1)
     {
        printf("\nCannot save the contact\n");
        return 4;
    }
    printf("\nBike records saved to file successfully! \n");
    fclose(fp);
    return 5;
}