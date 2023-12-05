/**
 * @file function.h
 * @author Ben Givens
 * @brief Header file for functions for shell program
 * @date 2023-11-04
 */
#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
void loop();
void help();
void removeNewLine(char *array);
#endif