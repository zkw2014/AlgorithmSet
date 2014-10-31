/************************************************************************
    > File: assist.c
    > By: zkw
    > Description: 
 ************************************************************************/

#include "def.h"

void init_arr(int *arr, unsigned int len)
{
	unsigned int ix = 0;
	for (; ix != len; ++ix) {
		arr[ix] = rand()%10;
	}
}

void copy_brr_from_arr(int *brr, const int *arr, unsigned int len)
{
	int ix = 0;
	for (; ix != len; ++ix)
		brr[ix] = arr[ix];
}

void init_func_sort_arr(SORT_FUNC *arr, unsigned int len) //将各种排序方法放到函数指针数组里
{
	unsigned int ix = 0;
	for (; ix != len; ++ix) {
		switch (ix) {
			case 0  : arr[ix] = bubble_sort; break;
			case 1  : arr[ix] = select_sort; break;
			case 2  : arr[ix] = insert_sort; break;
			case 3  : arr[ix] = quick_sort;  break;
			case 4  : arr[ix] = heap_sort;   break;
			default : printf("switch error\n");
		}
	}
}

bool small_to_big(int a, int b)
{
	return a <= b;
}

bool big_to_small(int a, int b)
{
	return a >= b;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_arr(int *arr, unsigned int len, sign_t sign)
{
	switch (sign) {
		case 0  : printf("bubble_sort, the arr is: "); break;
		case 1  : printf("select_sort, the arr is: "); break;
		case 2  : printf("insert_sort, the arr is: "); break;
		case 3  : printf("quick_sort,  the arr is: "); break;
		case 4  : printf("heap_sort,   the arr is: "); break;
		case 5  : printf("init arr is:             "); break;
		default : printf("switch error\n");
	}
	int ix = 0;
	for (; ix != len; ++ix)
		printf("%-3d", arr[ix]);
	if (sign == INIT)
		printf("\n");
}

bool check_arr_is_sorted(const int *arr, unsigned int len, COMPARE_METHOD compare_method)
{
	int ix = 0;
	for (; ix != len-1; ++ix) {
		if ( compare_method(arr[ix], arr[ix+1]) )
			continue;
		else
			return false;
	}

	return true;
}

void give_evaluation(bool have_sorted, unsigned int ix) //对排序结果进行评价
{
	if (have_sorted) {
		printf("   works well !\n");
	} else {
		printf("   is bad !\n");
	}
}
