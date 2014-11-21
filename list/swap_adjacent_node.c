/************************************************************************
  > File: swap_adjacent.c
  > By: zkw
  > Description: 交换一个单链表中的相邻结点，当元素个数为奇数时，最后一个结点不需要交换
 ************************************************************************/
//难度适中，比较经典的一道题，对于练习思维很有帮助
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define LIST_LEN 20

typedef struct node {
	int32_t data_;
	struct node *next_;
} node_t;

node_t *create_list(node_t *head, uint32_t len);
void print_list(const node_t *head);
void swap_adjacent_node(node_t **p);

int main(void)
{
	srand(time(NULL));
	node_t *head = NULL;
	uint32_t len = LIST_LEN;
	head = create_list(head, len); //建立原始链表
	printf("origin list is: ");
	print_list(head); //打印原始链表

	swap_adjacent_node(&head); //交换相邻节点

	printf("the swaped list is: ");
	print_list(head); //打印交换后的链表

	return 0;
}

node_t *create_list(node_t *head, uint32_t len)
{
	assert(len > 0);

	node_t *tail = NULL;
	while (len-- != 0) {
		node_t *cur = (node_t *)malloc(sizeof(node_t));
		memset(cur, 0, sizeof(node_t));
		cur->data_ = rand()%10;
		if (len == LIST_LEN-1) { //第一个节点特殊处理
			head = cur;
			tail = head;
			continue;
		}
		tail->next_ = cur;
		tail = cur;
	}

	return head;
}

void print_list(const node_t *head)
{
	while (head) {
		printf("%-2d", head->data_);
		head = head->next_;
	}
	printf("\n");
}

void swap_adjacent_node(node_t **p) //比较好的练习思维的算法
{
	assert(NULL!=p && NULL!=*p);

	node_t *head = *p;
	node_t *left = head;
	node_t *right = NULL;
	node_t *pre = NULL;

	while (NULL != left) {
		right = left->next_; //判断右结点是否存在
		if (NULL == right)
			break;

		left->next_ = right->next_;
		right->next_ = left;
		if (head == left) { //当前两个数据交换时，要修改头指针
			*p = right;
		} else {
			pre->next_ = right;
		}

		pre = left; //为下一循环做准备,注意原来的left实际上是现在的right
		left = left->next_;
	}
}
