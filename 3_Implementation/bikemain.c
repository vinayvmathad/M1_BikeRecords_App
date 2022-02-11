/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include "main.h"

    char bikerbikename[40]; /// string to store name of the employee
 
    long int recsize; /// size of each record of employee
    
     FILE *fp, *ft; /// file pointers
    char another, choice;

 void List_BikeRecord(){
     rewind(fp); ///this moves file cursor to start of the file
                while(fread(&b,recsize,1,fp)==1){ /// read the file and fetch the record one record per fetch
                    printf("\n%s %d %d\n",b.bikename,b.year,b.cc); /// print the bikename, year and cc
                }

     
 }

  void Modify_BikeRecord(){
another = 'y';
                while(another == 'y'){
                    printf("Enter the bike name to modify: ");
                    scanf("%s",bikerbikename);
                    rewind(fp);
                    while(fread(&b,recsize,1,fp)==1){ /// fetch all record from file
                        if(strcmp(b.bikename,bikerbikename) == 0){ ///if entered name matches with that in file
                            printf("\nEnter new bikename,year and cc: ");
                            scanf("%s%d%d",b.bikename,&b.year,&b.cc);
                            fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
                            fwrite(&b,recsize,1,fp); /// override the record
                            break;
                        }
                    }
                    printf("\nModify another record(y/n)");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }

 }
void Delete_BikeRecord(){
another = 'y';
                while(another == 'y'){
                    flush();
                    printf("\nEnter name of bike to delete: ");
                    fgets(bikerbikename,40, stdin);
                    ft = fopen("Temp.dat","wb");  /// create a intermediate file for temporary storage
                    rewind(fp); /// move record to starting of file
                    while(fread(&b,recsize,1,fp) == 1){ /// read all records from file
                        if(strcmp(b.bikename,bikerbikename) != 0){ /// if the entered record match
                            fwrite(&b,recsize,1,ft); /// move all records except the one that is to be deleted to temp file
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("BIKE.DAT"); /// remove the orginal file
                    rename("BIKE.dat","BIKE.DAT"); /// rename the temp file to original file name
                    fp = fopen("BIKE.DAT", "rb+");
                    printf("Delete another record(y/n)");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }
 }
 
 void Exit(){
             fclose(fp);  /// close the file
                exit(0); /// exit from the program
 }
 


int main(){


    /// sizeo of each record i.e. size of structure variable e
    recsize = sizeof(b);

    /** open the file in binary read and write mode
    * if the file EMP.DAT already exists then it open that file in read write mode
    * if the file doesn't exit it simply create a new copy
    */
    fp = fopen("BIKE.DAT","rb+");
    if(fp == NULL){
        fp = fopen("BIKE.DAT","wb+");
        if(fp == NULL){
            printf("Connot open file");
            exit(1);
        }
    }
 
    /// infinite loop continues untile the break statement encounter
    while(1){
        printf("1. Add BikeRecord\n"); /// option for add record
        printf("2. List BikeRecords\n"); /// option for showing existing record
        printf("3. Modify BikeRecords\n"); /// option for editing record
        printf("4. Delete BikeRecords\n"); /// option for deleting record
        printf("5. Exit\n"); /// exit from the program
        printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
        fflush(stdin); /// flush the input buffer
        scanf("\n%c", &choice); /// get the input from keyboard
        switch(choice){
            case '1':  /// if user press 1
                Add_BikeRecord();
                break;
            case '2':
                List_BikeRecord();
                break;
 
            case '3':  /// if user press 3 then do editing existing record
                Modify_BikeRecord();
                break;
            case '4':
                Delete_BikeRecord();
                break;
            case '5':
                Exit();
        }
    }
    return 0;

   
}