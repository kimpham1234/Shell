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
#include <stdlib.h>
#define MAXLINE 80

int main(void) {
    char* args[MAXLINE/2 + 1];
    char input[100];
    char* token;
    const char delim[2] = " ";
    int background;
    int status;
    int result = 0;
    
    int should_run = 1;
    printf("CS149 Shell from Kim Pham\n");
    
    while(should_run){
        printf("CutieBoo-000>");
        fflush(stdout);
        
        //read user output
        fgets(input, 100, stdin);
        
        //trim '\n' at the end
        int len =(int) strlen(input);
        input[len-1] = '\0';
        
        //start spliting tokens
        token = strtok(input, delim);
        args[0] = token;
        int i = 1;
        while(token){
            token = strtok(NULL, delim);
            args[i] = token;
            i++;
        }
       //done spliting tokens
        
        printf("%s\n", args[0]);
        printf("%s\n", args[1]);

        
        //check for exit command
        if(strcmp(args[0], "exit")==0 || strcmp(args[0], "exit\n")==0){
            printf("yesbgvgvh\n");
            should_run = 0;
        }else{
            printf("No");
        }
        
        if(should_run==1){
            //check for background process command
            if(strcmp(args[i-2], "&")==0){
                background = 1;
                args[i-2] = NULL;
            }else
                background = 0;
            
            //fork a new process
            int pid = fork();
            
            if(pid == -1){
                printf("Error in fork");
            }else if(pid == 0){ //child process
                result = execvp(args[0], args);
                if(result == -1){
                    perror("error");
                    exit(0);
                }
            }
            else{ //parent
                if(background == 0)
                    waitpid(pid, &status, 0);
            }
        }
        
    }
    return 0;
}


/*
 char* args[3];
 args[0] = "sleep";
 args[1] = "5m";
 args[2] = NULL;
 
 if(fork()==0){
 int result = execvp(args[0], args);
 if(result == -1){
 printf("Error");
 }
 }
 }
 */

/*
 for(int j = 0; j < i; j++){
 printf("%s\n", args[j]);
 }*/



