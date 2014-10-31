/************************************************************************
    > File: def.h
    > By: zkw
    > Description: 
 ************************************************************************/

#ifndef DEF_H
#define DEF_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>

#define ARR_LEN 10

typedef enum {false, true} bool;
typedef bool(*COMPARE_METHOD)(int, int);

bool small_to_big(int a, int b);
void big_to_small(int a, int b);
void swap(int *a, int *b);
void init_arr(int *arr, unsigned int len);
void print_arr(const int *arr, unsigned int len);
void bubble_sort(int *arr, unsigned int len, COMPARE_METHOD compare_method);
int binary_search(const int *arr, unsigned int len, int search_data); //找到返回下标，找不到，返回-1
void give_evaluation(const int *arr, unsigned int len, int find_pos);

#endif //DEF_H
