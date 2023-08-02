// 120_9.6链表从指定节点后方插入新节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// 119——9.5统计链表节点个数及链表查找.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>

struct Test
{
	int data;
	struct Test* next;
};

void printLink(struct Test* head)
{
	struct  Test* point = head;
	while (point != NULL)
	{
		printf("%d ", point->data);
		point = point->next;
	}
	putchar('\n');
}
int getLinkTotalNumber(struct Test* head)
{
	int count = 0;
	struct  Test* point = head;
	while (point != NULL)
	{
		count++;
		point = point->next;
	}
	return count;
}
int searchLink(struct Test* head, int data, struct Test* niu)
{
	struct  Test* point = head;
	while (point != NULL)
	{
		if (point->data == data)
		{
			niu->next = point->next;
			point->next = niu;
			return 1;
		}
		point = point->next;
	}
	return 0;
}
int main()
{
	int i;

	int find;
	struct Test t1 = { 1,NULL };
	struct Test t2 = { 2,NULL };
	struct Test t3 = { 3,NULL };
	struct Test t4 = { 4,NULL };
	struct Test t5 = { 5,NULL };
	struct Test t6 = { 6,NULL };

	struct Test niu = { 100,NULL };



	t1.next = &t2;
	t2.next = &t3;
	t3.next = &t4;
	t4.next = &t5;
	t5.next = &t6;
	t6.next = NULL;//不写这一行也可以，因为t6的next不存在，所以，pointer成为了悬空指针指向了空，所以没必要写这一行

	printf("你想插到哪个数字后面 1 2 3 4 5 6\n\n");
	 
	scanf_s("%d", &find);
	int ret = searchLink(&t1, find, &niu);
	printf("链表里面添加了%d个数字\n", getLinkTotalNumber(&t1)-6);
	
	if (ret == 1)
	{
		printf("找到了%d\n",find);
	}
	else if (ret == 0)
	{
		printf("没找到了%d\n",find);
	}
	printLink(&t1);

	return 0;
}