/************************************************************************
    > File: reserve_list.c
    > By: zkw
    > Description: 用头插法实现链表的逆置
 ************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define LIST_LEN 5

typedef struct node {
	int32_t data_;
	struct node *next_;
} node_t;

node_t *create_list(node_t *head, uint32_t len);
void print_list(const node_t *head);
node_t *reserve_list(node_t *head); //链表逆置

int main(void)
{
	srand(time(NULL));
	node_t *head = NULL;
	uint32_t len = LIST_LEN;
	head = create_list(head, len); //建立原始链表
	printf("origin list is: ");
	print_list(head); //打印原始链表

	head = reserve_list(head); //逆置链表
	printf("reserved list is: ");
	print_list(head); //打印逆置后的链表

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

node_t *reserve_list(node_t *head) //用头插法实现
{
	if (NULL == head || NULL == head->next_) // 0 或 1
		return head;

	node_t *cur = head->next_, *left = NULL;
	head->next_ = NULL; //使逆置后最后一个节点的指针域为NULL
	while (cur) {
		left = cur->next_;
		cur->next_ = head;
		head = cur;
		cur = left;
	}

	return head;
}
