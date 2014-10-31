/************************************************************************
    > File: def.h
    > By: zkw
    > Description: 
 ************************************************************************/

#ifndef DEF_H
#define DEF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>

//数组长度
#define ARR_LEN 10
//检查的次数
#define CHECK_TIMES 10
//排序方法的种类
#define SORT_FUNC_NUMS 5
//排序规则
#define SMALL_TO_BIG small_to_big
#define BIG_TO_SMALL big_to_small

//模拟出bool类型
typedef enum {false, true} bool; 
typedef enum {BUBBLE, SELECT, INSERT, QUICK, HEAP, INIT} sign_t; //辅助print_arr函数
//定义两个函数指针类型
typedef bool (*COMPARE_METHOD)(int, int);
typedef void (*SORT_FUNC)(int *, unsigned int, COMPARE_METHOD);

void init_arr(int *arr, unsigned int len);
void copy_brr_from_arr(int *brr, const int *arr, unsigned int len);
void init_func_sort_arr(SORT_FUNC *arr, unsigned int len); //初始化排序方法集合

bool small_to_big(int a, int b);
bool big_to_small(int a, int b);
void swap(int *a, int *b);
void bubble_sort(int *arr, unsigned int len, COMPARE_METHOD compare_method); //参数依次是：数组首地址，数组长度, 比较规则
void select_sort(int *arr, unsigned int len, COMPARE_METHOD compare_method);
void insert_sort(int *arr, unsigned int len, COMPARE_METHOD compare_method);
void quick_sort(int *arr, unsigned int len, COMPARE_METHOD compare_method);
void heap_sort(int *arr, unsigned int len, COMPARE_METHOD compare_method);

void print_arr(int *arr, unsigned int len, sign_t sign);
bool check_arr_is_sorted(const int *arr, unsigned int len, COMPARE_METHOD compare_method); //检查是否排好序
void give_evaluation(bool have_sorted, unsigned int ix); //根据最后的排序结果对相应的排序算法给出评价

#endif //DEF_H
