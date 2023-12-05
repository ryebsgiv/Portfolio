/**
 * @file functions.h
 * @author Ben Givcns
 * @brief Headerfile for pwd
 * @date 2023-10-25
 */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "stdio.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int getInode(const char *dir);
void recursion(int first_inode,int current_inode);
#endif