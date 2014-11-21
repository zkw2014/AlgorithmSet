/************************************************************************
  > File: itoa.c
  > By: zkw
  > Description: 整型转字符串
 ************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

uint32_t negativeToPositive(char **p, int32_t data);
void integerToAscii(char **str, uint32_t data);

int main(void)
{
	int data;
	char str[100];
	while (1) {
		char *p = str;
		data = 0;
		memset(str, 0, sizeof(str));
		scanf("%d", &data);

		uint32_t positive_data = negativeToPositive(&p, data); //负数变正数
		integerToAscii(&p, positive_data); //整数转ASCII

		puts(str);
	}

	return 0;
}

uint32_t negativeToPositive(char **p, int32_t data) //之所以char **str,是因为当为负数时，要改变str
{
	int negative = 1;
	char *str = *p;
	if (data < 0) {
		negative = -1;
		data = -data;
		str[0] = '-';
		++*p;
	}

	return data;
}

void integerToAscii(char **str, uint32_t data) //递归实现
{
	if (0 == data)
		return;

	integerToAscii(str, data/10);
	**str = data%10 + '0';
	(*str)++;
}
