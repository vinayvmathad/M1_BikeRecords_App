/**
 * @file header.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef HEADER_H
#define HEADER_H

/**
 * @brief structure to store data of a contact
 * 
 */

typedef struct 
{
    char BikeName[25];
    char Year[11];
    char CC[25];
} Bike;


/* enumerator for different search types */

/**
 * @brief thsi enum is for serching through the database
 * 
 */
typedef enum { Bike_NAME, year, CC, TEST } search_t;

/**
 * @brief this function is for adding new entries to the structure
 * 
 */
int addBikeName();

/**
 * @brief this function shows the specific record of the structure
 * 
 * @param index it is the index to identify the record
 */

int displayRecord(int index);

/**
 * @brief this function displays all the records of the structure
 * 
 */
int displayAllRecords();

/**
 * @brief this function searches for a specific record in the structure
 * 
 * @param key user input to search the specific record
 * @param type search by name, last name or mobile number
 */
int searchContact(char *input, search_t attribute);

/**
 * @brief this function is used to delete the record with phone number
 * 
 * @param phoneNumber 
 */
int removeContact(char *phoneNumber);

/**
 * @brief this function fetches the data from the file
 * 
 */
int retriveFromFile();

/**
 * @brief this function saves the structure and its data to the file
 * 
 */
int storeToFile();

#endif // HEADER_H