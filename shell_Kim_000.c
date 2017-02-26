//
//  main.c
//  Shell_Kim_000
//
//  Created by Kim Pham on 2/25/17.
//  Copyright © 2017 BooBoo. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#define MAXLINE 80

/*
void split(char **array, char* input){
   // char* array[100];
    printf("Enter\n");
    char* token;
    const char delim[2] = " ";
    
    token = strtok(input, delim);
    *token+='\0';
    //array[0] = "hello";
    array[0] = token+'\0';
    printf("token %s\n", token);
    printf("array %s\n", array[0]);
    
   
    int i = 1;
    while(token!=NULL){
        token = strtok(NULL, delim);
        if(token!=NULL)
            *token+='\0';
        
      //  array[i] = "hi";
        array[i] = token+'\0';

        printf("token %s\n", token);
        printf("array %s\n", array[i]);
        
        i++;
    }
    printf("Leave\n");
    //return array;
}*/
/*
char** split(char* input){
    char* token;
    const char delim[2] = " ";
    int size = 1;
    char** array = malloc(sizeof(char*) * size);
    
    if(array==NULL)
        return NULL;
    
    token = strtok(input, delim);
    array[0] = token;
    
    while(token!=NULL){
        size++;
        array = realloc(array, sizeof(char*) * size++);
        token = strtok(NULL, input);
        array[size] = token;
    }
    array = realloc(array, sizeof(char*) * size++);
    array[size] = NULL;
    return array;
}
*/
int main(void) {
    char* args[40];
    char input[100];
    char* token;
    const char delim[2] = " ";
    int i = 1;

    int should_run = 1;
    printf("CS149 Shell from Kim Pham\n");
    
    //fgets(input, 100, stdin);
    //
    while(should_run){
        printf("CutieBoo-000>");
        fflush(stdout);
        fgets(input, 100, stdin);
        printf("%s", input);
        
        //trim
        int len =(int) strlen(input);
        input[len-1] = '\0';
        
        //start spliting
        token = strtok(input, delim);
        args[0] = token;
        while(token){
            token = strtok(NULL, delim);
            args[i] = token;
            i++;
        }
       //done spliting

//        printf("%s\n",args[0]);
//        printf("%s\n",args[1]);
//        printf("%s\n",args[2]);
  //      args[0] = "ls";
  //      args[1] = "-l";
  //      args[2] = NULL;
        int result = execvp(args[0], args);
        if(result == -1){
            printf("Error\n");
        }
        
       
        
        
        
        
        
        
        
        should_run--;
    }
    
    
    //split stuff
    
   
    
    
    
    return 0;
}
/*
 char* args[2];
 args[0] = argv[1];
 args[1] = NULL;
 
 
 
 int result = execvp(args[0], args);
 if(result == -1){
 printf("Error");
 }
 */

/*
 for(int j = 0; j < i; j++){
 printf("%s\n", args[j]);
 }*/



