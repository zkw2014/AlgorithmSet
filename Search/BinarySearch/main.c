/************************************************************************
  > File: binary_search.c
  > By: zkw
  > Description: 实现折半查找算法 
 ************************************************************************/

#include "def.h"

int main(void)
{
	COMPARE_METHOD compare_method = small_to_big;
	srand(time(NULL));
	//1.随机生成一个数组
	int arr[ARR_LEN] = {0};
	init_arr(arr, ARR_LEN);
	print_arr(arr, ARR_LEN);

	//2.对数组bubble排序
	bubble_sort(arr, ARR_LEN, compare_method);
	print_arr(arr, ARR_LEN);
	
	//3.输入数据，查找，给出结果
	int search_data = 0;
	while (scanf("%d", &search_data) == 1) {
		int find_pos = binary_search(arr, ARR_LEN, search_data);
		give_evaluation(arr, ARR_LEN, find_pos);
	}

	return 0;
}
