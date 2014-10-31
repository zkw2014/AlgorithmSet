/************************************************************************
  > File: main.c
  > By: zkw
  > Description: 实现所有排序算法，和检测程序
 ************************************************************************/

#include "def.h"

int main(void)
{
	SORT_FUNC func_sort_arr[SORT_FUNC_NUMS] = {NULL}; //排序方法集合
	init_func_sort_arr(func_sort_arr, SORT_FUNC_NUMS);
	COMPARE_METHOD compare_method = SMALL_TO_BIG; //初始化排序规制
	srand(time(NULL));

	int arr[ARR_LEN] = {0}; //待排序的数据
	int brr[ARR_LEN] = {0}; //用来拷贝arr
	int check_times = CHECK_TIMES;
	while (check_times--) {
		printf("check times: %d\n", CHECK_TIMES-check_times);
		bzero(arr, sizeof(arr));
		bzero(brr, sizeof(brr));
		init_arr(arr, ARR_LEN);
		print_arr(arr, ARR_LEN, INIT);
		printf("-----------------------------------------------------------------------\n");
		unsigned int ix = 0;
		for (; ix != SORT_FUNC_NUMS; ++ix) {
			copy_brr_from_arr(brr, arr, ARR_LEN);
			func_sort_arr[ix](brr, ARR_LEN, compare_method);  //进行排序
			print_arr(brr, ARR_LEN, ix);
			bool have_sorted = check_arr_is_sorted(brr, ARR_LEN, compare_method);
			give_evaluation(have_sorted, ix);
			printf("-----------------------------------------------------------------------\n");
		}
		printf("\n");
	}

	return 0;
}
