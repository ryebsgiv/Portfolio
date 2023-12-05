# PA2: Shells Part I

**Purpose:** To recall the use of `fork()` and `execvp()`.

## Introduction
In this assignment, you will implement a simple shell program similar to the Unix shell bash or the command prompt in Windows. You will call your `emshell` (where `em` should be replaced with your initials).

The shell will support the execution of programs in UNIX. You must implement your solution in C.

Be sure to study the man pages for the various functions suggested in this assignment.

## Requirements
- [ ] Use three file structure
    * Make your program modular. Break the program into functions.
    * Each file should have a file header comment
    * Each function should have a function header comment
        - [ ] A brief description of what the function does
        - [ ] A description of each parameter
        - [ ] A description of what the function returns
- [ ] Create a `Makefile` to build and maintain the program.
- [ ] Commit your code frequently and provide descriptive commit messages.
- [ ] Refactor code that uses efficient approaches.
- [ ] Write in-line comments in your code for readability.
- [ ] DO NOT use `system()`

### Part 1: Basic execution
- [ ] Using `fgets()` create a shell that prompts the user with the prompt `emshell>` continually until the user enters the command `exit`.

- [ ] When the shell first starts to display the message:
```
Created By: <Your Name>
Type "help" to see implemented commands

emshell>
```
- [ ] This shell should ignore all commands except `exit`, which ends the program.

Here is a sample session of how your shell should look:

```
$ ./emshell
Created By: Ekaterina Miller
Type "help" to see implemented commands

emshell> help
emshell> ls -l
emshell> exit
$
```
- [ ] Test and make sure the program is working correctly. Commit and push code to GitHub. 

### Part 2: Help
- [ ] If the user types:
    ```
    emshell> help
    ```
    Display the message:
    ```
    pwd  - Print the current working directory
    exit - Exit Shell
    help - Display this message
    <UNIX cmd>    - Spawn child process, execute <UNIX cmd> in the foreground
    ```
Here is a sample session:
```
$ ./emshell
Created By: Ekaterina Miller
Type "help" to see implemented commands

emshell> help
pwd  - Print the current working directory
exit - Exit Shell
help - Display this message
<UNIX cmd>    - Spawn child process, execute <UNIX cmd> in the foreground

emshell> exit
$
```
- [ ] Test and make sure the program is working correctly. Commit and push code to GitHub. 

### Part 3: `fork()` and `execvp()`
- [ ] Using `fork()` and `execvp()`, implement the ability for the user to execute arbitrary commands using your shell.
- [ ] If the user types:
    ```
    emshell> ls -l /usr
    ```
    Your shell should execute the `ls` command with the parameters `-l` and `/usr`, which should result in the contents of the directory `/usr` being displayed on the screen.
    
- [ ]  `excecvp`, requires an array of C-string as one of its parameters. You will have to convert the C-string `ls -l /usr` into an array of strings with the last element assigned with `NULL`. You did it in PA1. You may reuse your code or write a new one. This time you can use `strtok` function
    ```cpp
    // Example of the use of execvp, but your approach should work for any command and should be dynamic
    char *args[4];
    args[0] = "ls";
    args[1] = "-l";
    args[2] = "/usr";
    args[3] = NULL;
    execvp(args[0], args);
    ```
    
Here is a sample session of how your shell should look:
```
$ ./emshell
Created By: Ekaterina Miller
Type "help" to see implemented commands

emshell> help
pwd  - Print the current working directory
exit - Exit Shell
help - Display this message
<UNIX cmd>    - Spawn child process, execute <UNIX cmd> in the foreground

emshell> ls -l /usr
total 5
drwxr-xr-x   2 root root 69632 Apr  4 05:44 bin
drwxr-xr-x   4 root root  4096 Jun 23 10:48 doc
drwxr-xr-x   2 root root  4096 Mar 14 01:13 etc
drwxr-xr-x   2 root root  4096 Mar 14 08:32 games
drwxr-xr-x 123 root root 16384 Mar 19 04:18 include
emshell> exit
$
```
- [ ] Test and make sure the program is working correctly. Commit and push code to GitHub. 

## Submitting Assignments
1. Test your code in the Codespace.
2. Ensure that you `push` your local copy of this PA's repo to GitHub. Verify that the code in GitHub is the same code you have on your local computer.
3. You may continue to update and push your code into this repo as long as it is before the deadline.
4. It is VERY IMPORTANT that besides pushing the code to GitHub you still submit the GitHub URL of this programming assignment in Canvas. This allows the instructor to be notified of your final submission and that you are ready for grading.

> **_NOTE: By submitting your code to be graded, you are stating that your submission does not violate the Academic Integrity Policy outlined in the syllabus._**
