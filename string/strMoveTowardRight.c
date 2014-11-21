/************************************************************************
    > File: strMoveTowardRight.c
    > By: zkw
    > Description: 字符串整体往右移动NUM_MOV位(泡椒网算法面试题)
 ************************************************************************/

//要求：空间复杂度为1，时间复杂度为O(n);
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

//NUM_MOV用来控制向右移动的位数
#define NUM_MOV 3

void display(const char *str);
void move_toward_right(char (*p)[13], uint32_t num_mov);

int main(void)
{
	char str[13] = "hello world"; //结果为"world hello"
	uint32_t num_mov = NUM_MOV;

	printf("the original arr is:");
	display(str);
	printf("\n");

	move_toward_right(&str, num_mov);

	printf("the result arr is:");
	display(str);
	printf("\n");

	return 0;
}

void display(const char *str)
{
	assert(NULL != str);
	
	while (*str != '\0') {
		putchar(*str);
		++str;
	}
}

//算法思想：先将str[0]的数据保存起来，然后将合适的数据填充到str[0]的位置，依次循环，最后把str[0]填充到合适位置
void move_toward_right(char (*p)[13], uint32_t num_mov)
{
	char *str = *p;
	uint32_t len = strlen(str);
	char temp = str[0];
	uint32_t index_space = 0; //记录空余位置
	uint32_t have_placed_num = 0;
	while (have_placed_num < len-1) {
		uint32_t index_left_move = (index_space-num_mov+len) % len;
		str[index_space] = str[index_left_move]; //在空余位置上填充数据
		index_space = index_left_move;
		++have_placed_num;
	}
	str[index_space] = temp;
}
