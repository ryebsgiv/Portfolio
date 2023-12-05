# PA4 PWD (50 pts)

## Learner Objectives
At the conclusion of this programming assignment, participants should be able to:
* Use **`opendir`**,**`closedir`**, **`readdir`** and **`chdir`** functions.


## Program Details
For this assignment, you will be required to write your own version of the Linux `pwd` command. 
The function can be written using recursion or iteration. It is your choice how you want to implement it.
### Hint1:
 * **`struct dirent`** does not give you the name of the current directory
 * To find the name of the current directory, you need to get the i-node of the current directory
 * Change the current directory to the parent directory
 * Search the parent directory(now current directory) for the entry with this i-node 
 * Print the name of this entry
 * For the recursive implementation, you will need to print the name after the recursive call
 * For iteration implementation, you will need to add the name to the array
 * Remember: the parent of the root directory is the root directory itself (same inodes)

### Hint2:
 * Read the man pages for **`opendir`**,**`closedir`**, **`readdir`** and **`chdir`**.



### Requirements
 - [ ] The output of your program must be exactly the same as the output of the Linux `pwd` command
 - [ ] Use three file structure
- [ ] Use function header comments and file header comments
- [ ]  Use correct indentation
- [ ]  DO NOT COPY CODE!!!
- [ ]  Do not use `pwd`, `getwd`, `getcwd`, `pwdx`, etc.

## Submitting Assignments
1. Test your code in the Codespace.
2. Ensure that you `push` your local copy of this PA's repo to GitHub. Verify that the code in GitHub is the same code you have on your local computer.
3. You may continue to update and push your code into this repo as long as it is before the deadline.
4. It is VERY IMPORTANT that besides pushing the code to GitHub you still submit the GitHub URL of this programming assignment in Canvas. This allows the instructor to be notified of your final submission and that you are ready for grading.

> **_NOTE: By submitting your code to be graded, you are stating that your submission does not violate the Academic Integrity Policy outlined in the syllabus._**
