/************************************************************************
  > File: sort.c
  > By: zkw
  > Description: 各种排序算法的具体实现 
 ************************************************************************/

#include "def.h"

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

void select_sort(int *arr, unsigned int len, COMPARE_METHOD compare_method)
{
	int ix = 0;
	for (; ix != len-1; ++ix) { //[0, len-2]
		int min = arr[ix];
		int min_index = ix;
		int iy = ix+1;
		for (; iy != len; ++iy) {
			if (compare_method(arr[iy], min)) {
				min = arr[iy];
				min_index = iy;
			}
		}
		if (min_index != ix)
			swap(&arr[ix], &arr[min_index]);
	}
}

void insert_sort(int *arr, unsigned int len, COMPARE_METHOD compare_method)
{
	int ix = 0;
	for (; ix != len-1; ++ix) {
		int temp = arr[ix+1];
		if (!compare_method(temp, arr[ix]))
			continue;
		int iy = ix;
		for (; iy >= 0; --iy) {
			if (compare_method(temp, arr[iy]))
				arr[iy+1] = arr[iy];
			else
				break;
		}
		arr[iy+1] = temp;
	}
}

void aid_quick_sort(int *arr, int left, int right, COMPARE_METHOD compare_method) //实现快排所有功能
{
	if (left >= right) //递归结束条件
		return;
	int left_store = left;
	int right_store = right;
	int temp = arr[left];
	int space_index = left;
	++left;
	while (left <= right) {
		while ( compare_method(temp, arr[right]) && (left <= right) ) { //right向左移，直到找到比temp小的数据
			--right;
		}
		if (left > right)
			break;
		arr[space_index] = arr[right];
		space_index = right;
		--right;
		while ( compare_method(arr[left], temp) && (left <= right) ) { //left向右移，直到找到比temp大的数据
			++left;
		}
		if (left > right)
			break;
		arr[space_index] = arr[left];
		space_index = left;
		++left;
	}
	arr[space_index] = temp; //temp放到合适位置
	aid_quick_sort(arr, left_store, space_index-1, compare_method); //左半部分
	aid_quick_sort(arr, space_index+1, right_store, compare_method); //右半部分
}

void quick_sort(int *arr, unsigned int len, COMPARE_METHOD compare_method) //为了接口对接
{
	aid_quick_sort(arr, 0, len-1, compare_method);
}

void adjust_heap_downward(int *arr, unsigned int len, int coordinate, COMPARE_METHOD compare_method) //调堆
{
	int lchild_index = coordinate*2 + 1;
	int rchild_index = lchild_index + 1;
	int bigger_child_index = 0;
	bool have_child = true;
	if (rchild_index <= len-1) { //两个孩子都有
		bigger_child_index = arr[lchild_index] >= arr[rchild_index] ? lchild_index : rchild_index;
	} else if (lchild_index <= len-1) { //只有左孩子
		bigger_child_index = lchild_index;
	} else { //没有孩子
		have_child = false;
	}

	while (have_child && arr[coordinate] < arr[bigger_child_index]) {
		swap(&arr[coordinate], &arr[bigger_child_index]);
		coordinate = bigger_child_index; //目的是为了往下调堆

		lchild_index = coordinate*2 + 1;
		rchild_index = lchild_index + 1;
		have_child = true;
		if (rchild_index <= len-1) { //两个孩子都有
			bigger_child_index = arr[lchild_index] >= arr[rchild_index] ? lchild_index : rchild_index;
		} else if (lchild_index <= len-1) { //只有左孩子
			bigger_child_index = lchild_index;
		} else { //没有孩子
			have_child = false;
		}
	}
}

void heap_sort(int *arr, unsigned int len, COMPARE_METHOD compare_method) //大顶堆
{
	//先建堆,本质上也是调堆的过程
	int ix = 0;
	for (ix = len/2-1; ix >= 0; --ix) {
		adjust_heap_downward(arr, len, ix, compare_method);
	}

	unsigned int count_data_well_placed = 0; //用来记录被放好位置的元素的个数
	while (count_data_well_placed < len-1) { //先交换，然后不断的调堆
		swap(&arr[0], &arr[len - count_data_well_placed - 1]); //将第一个元素和最后一个元素交换
		count_data_well_placed++;
		adjust_heap_downward(arr, len - count_data_well_placed, 0, compare_method); //对第一个元素调堆
	}
}
