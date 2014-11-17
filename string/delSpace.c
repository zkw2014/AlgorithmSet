/************************************************************************
    > File: delSpace.c
    > By: zkw
    > Description: 一个字符串，去除空格,(泡椒网面试算法题)
 ************************************************************************/

#include <stdio.h>
#include <assert.h>

void display(const char *str);
void del_space(char (*str)[30]);

int main(void)
{
	char str[30] = " h e l  l o world ";

	printf("origin str is:");
	display(str);
	printf("\n");

	del_space(&str);

	printf("after del space, the str is:");
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

void del_space(char (*str)[30])
{
	assert(NULL != *str);
	char *p_old = *str, *p_new = *str; //p_old指针去找非空格字符
	while (*p_old != '\0') {
		if (*p_old == ' ') {
			++p_old;
			continue;
		} else {
			if (p_new != p_old) { //杜绝自身复制问题
				*p_new = *p_old;
			}
			++p_new;
			++p_old;
		}
	}
	*p_new = '\0'; //注意最后要加'\0'
}
