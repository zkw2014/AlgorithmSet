/************************************************************************
    > File: func.c
    > By: zkw
    > Description: 
 ************************************************************************/

#include "def.h"

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

void init_arr(int *arr, unsigned int len)
{
	unsigned int ix = 0;
	for (; ix != len; ++ix) {
		arr[ix] = rand()%10;
	}
}

void print_arr(const int *arr, unsigned int len)
{
	unsigned int ix = 0;
	for (; ix != len; ++ix) {
		printf("%-3d", arr[ix]);
	}
	printf("\n");
}

void bubble_sort(int *arr, unsigned int len, COMPARE_METHOD compare_method)
{
	int ix = 0, iy = 0;
	for (; ix != len-1; ++ix) {
		bool have_sorted = true;
		for (iy = 0; iy != len-ix-1; ++iy)
			if (compare_method(arr[iy+1], arr[iy])) {
				have_sorted = false;
				swap(&arr[iy], &arr[iy+1]);
			}
		if (have_sorted) return; //在某一趟排序中，如果发现已经排好序了，则直接退出
	}
}

int binary_search(const int *arr, unsigned int len, int search_data) //找到返回下标，找不到，返回-1
{
	int left = 0, right = len-1;
	int middle = (left + right)/2;
	while ( (left < right) && (arr[middle] != search_data) ) {
		if (search_data < arr[middle]) { //在左半部分找
			right = middle -1;
		}
		if (search_data > arr[middle]) { //在右半部分找
			left = middle + 1;
		}
		middle = (left + right)/2;
	}
	if (arr[middle] == search_data)
		return middle;
	return -1;
}

void give_evaluation(const int *arr, unsigned int len, int find_pos)
{
	if (-1 == find_pos) {
		printf("not found\n");
		return;
	}
	assert( (find_pos >= 0) && (find_pos <= len-1) );
	printf("have found, arr[%d] = %d\n", find_pos, arr[find_pos]);
}
