/************************************************************************
  > File: atoi.c
  > By: zkw
  > Description: 字符串转整型
 ************************************************************************/

#include <stdio.h>
#include <assert.h>

int myAtoi(const char *str);

int main(void)
{
	char str[100] = "";
	scanf("%s", str);
	printf("The ASCII format is:%s\n", str);

	int num = myAtoi(str);

	printf("The INTEGER format is:%d\n", num);

	return 0;
}


int myAtoi(const char *str)
{
	assert(NULL != str);
	int sum = 0;
	int negative = 1; //判断是否是负数

	while (*str != '\0') {
		if (*str < '0' || *str > '9') {
			if (0==sum && *str=='-') //当有-符号时，记录符号位
				negative = -1;
			++str;
			continue;
		}
		if (0 != sum) {
			sum *= 10;
		}
		sum += *str-'0';
		++str;
	}

	return sum*negative;
}
