/**
 * @file functions.c
 * @author Ben Givens
 * @brief Functions for pwd page. The functions are getInode which returns the Inode number, and Recursion which prints the file path.
 * @date 2023-10-25
 */
#include "functions.h"
/**
 * @brief Get the Inode from a directory
 * 
 * @param dir directory to get inode from
 * @return int inode number from directory
 */
int getInode(const char *dir) 
{
    //structure stat allows user to read information through links.
    //Note, this doesn't work for symbolic links.
    struct stat x;
    if (stat(dir, &x) == -1) 
    {
        perror("problem with finding stat");
        exit(1);
    }
    return x.st_ino;
}
/**
 * @brief Recursion function for cycling through the directories and printing the filepath
 * 
 * @param first_inode This is the root inode that is the target
 * @param current_inode This is the inode which the program is currently at
*/
void recursion(int first_inode, int current_inode) 
{
    //Set the current Inode as the current directories inode
    current_inode=getInode(".");

    //Change the directory to parent directory
    chdir("..");

    //Create directory variable using the current directory
    DIR *dirp=opendir(".");
    struct dirent *x;
    if (dirp==NULL)
    {
        perror("opendir failed");
        exit(1);
    }

    //Base case for recursion | if the current Inode = target inode
    //Else use recursion with the orgininal inode and the changed Inode value
    if (current_inode==first_inode)
    {
        return;
        
    }
    else
    {
        recursion(first_inode,current_inode);
        while ((x = readdir(dirp)) != NULL) 
        {
            //If the file inode = target inode then print name
            if (x->d_ino == current_inode) 
            { 
                printf("/%s", x->d_name);
            }
        }
    }
    closedir(dirp);
}