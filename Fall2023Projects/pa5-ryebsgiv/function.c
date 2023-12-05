/**
 * @file function.c
 * @author Ben Givens
 * @brief Functions for shell program
 * @date 2023-11-04
 */
#include "function.h"

/**
 * @brief Main loop of program
 * 
 */
void loop()
{ 
    //array is the char array that contains the users input       
    char array[100];
    //holder is the array of strings that holds the tokenized version of the users input
    char *holder[20];
    //pid_t value which represents the child after the fork
    pid_t child;
    //used for wait command to determine status of child
    int status;

    //Continous loop
    while (1)
    {
        //display message to user and get their input
        printf("bgshell> ");
        if (fgets(array, sizeof(array), stdin) == NULL) {
            printf("Error with input\n");
            break;
        }

        //removes newlines from user input
        removeNewLine(array);
        //tokenize the input
        char* token = strtok(array, " ");
        int num=0;
        while(token!=NULL)
        {
            //saves the token in holder[num]
            holder[num]=token;
            //Iterate through string
            token=strtok(NULL, " ");
            num++;
        }
        //set final value to NULL
        holder[num]=NULL;

        //Handle the tokens
        if (num>0)
        {   
            //if user enters exit then break the loop
            if (strcmp(holder[0], "exit")==0){
                break;
            }
            //if user enters help they display help message
            else if(strcmp(holder[0], "help")==0){
                help();
            }
            //else prepare to fork
            else
            {
                child=fork();
                if (child<0)
                {
                    perror("Problem with fork");
                    exit (1);
                }
                else if(child==0) 
                {
                    execvp(holder[0], holder);
                    perror("whoops");
                    exit(1);
                }
                else
                {
                    waitpid(child, &status, 0);
                }
            }
        }
    }
}
/**
 * @brief Displays the help message
 * 
 */
void help()
{
    printf("pwd  - Print the current working directory\nexit - Exit Shell\nhelp - Display this message\n<UNIX cmd>    - Spawn child process, execute <UNIX cmd> in the foreground\n");
}
/**
 * @brief Removes the new lines from the array
 * 
 * @param arry user input stored in array
 */
void removeNewLine(char *arry)
{
        // for (int i=0; i<sizeof(arry);i++)
        // {
        //     if (arry[i]=='\n'){
        //         arry[i]='\0';
        //     }
        // }
        arry[strcspn(arry, "\n")] = '\0';
}