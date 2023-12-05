/**
 * @file pwd.c
 * @author Ben Givens
 * @brief File which prints the working directories file path
 * @date 2023-10-25
 */
#include "functions.h"

int main()
{
    //Call the recursion file with the target file being root and the current inode being the inode of the directory.
    recursion(getInode("/"),getInode("."));
    //Print an extra newline
    printf("\n");
    return 0;
}