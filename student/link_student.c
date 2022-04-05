#include "link_student.h"
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

linkStudent* initLink_student(Student elem) {
	linkStudent* p = (linkStudent*)malloc(sizeof(linkStudent));//创建一个头结点
	if (p == NULL) {
		return NULL;
	}
	p->elem = elem;
	p->next = NULL;
	return p;
}

linkStudent* appendElem_student(linkStudent* p, Student elem) {
	linkStudent* temp = p;//创建临时结点temp
	// 遍历链表，找到最后一个
	for (;;) {
		if (temp->next == NULL) {
			break;
		}
		temp = temp->next;
	}
	//创建插入结点c
	linkStudent* c = (linkStudent*)malloc(sizeof(linkStudent));
	if (c == NULL) {
		return NULL;
	}
	c->elem = elem;
	//向链表中添加结点
	c->next = NULL;
	temp->next = c;
	return p;
}

linkStudent* insertElem_student(linkStudent* p, Student elem, int add) {
	linkStudent* temp = p;//创建临时结点temp
	//首先找到要插入位置的上一个结点
	for (int i = 1; i < add; i++) {
		if (temp == NULL) {
			printf("插入位置无效\n");
			return p;
		}
		temp = temp->next;
	}
	//创建插入结点c
	linkStudent* c = (linkStudent*)malloc(sizeof(linkStudent));
	if (c == NULL) {
		return NULL;
	}
	c->elem = elem;
	//向链表中插入结点
	c->next = temp->next;
	temp->next = c;
	return  p;
}

linkStudent* delElem_student(linkStudent* p, int add) {
	linkStudent* temp = p;
	//遍历到被删除结点的上一个结点
	for (int i = 1; i < add; i++) {
		temp = temp->next;
	}
	linkStudent* del = temp->next;//单独设置一个指针指向被删除结点，以防丢失
	temp->next = temp->next->next;//删除某个结点的方法就是更改前一个结点的指针域
	free(del);//手动释放该结点，防止内存泄漏
	return p;
}


linkStudent* updateElem_student(linkStudent* p, int add, Student newElem) {
	linkStudent* temp = p;
	for (int i = 0; i < add; i++) {
		temp = temp->next;
	}
	temp->elem = newElem;
	return p;
}

linkStudent* updateElemByName_student(linkStudent* p, const char* name, Student newElem) {

	linkStudent* temp = p;
	while (temp)
	{
		if (strcmp(name, temp->elem.name) == 0) {
			break;
		}
		temp = temp->next;
	}
	if (temp == NULL) {
		return p;
	}
	temp->elem = newElem;
	return p;
}

int getElemLength_student(linkStudent* p) {
	int count = 0;
	linkStudent* temp = p;
	while (temp)
	{
		temp = temp->next;
		++count;
	}
	return count;
}

Student getElem_student(linkStudent* p, int index) {
	Student c;
	c.index = -1;
	int count = 0;
	linkStudent* temp = p;
	while (p)
	{
		if (count == index) {
			memcpy(&c, &(p->elem), sizeof(Student));
			break;
		}
		p = p->next;
		++count;
	}
	return c;
}

Student getElemByName_student(linkStudent* p, const char* name) {
	Student c;
	c.index = -1;
	linkStudent* temp = p;
	while (temp)
	{
		if (strcmp(name, temp->elem.name) == 0) {
			memcpy(&c, &(temp->elem), sizeof(Student));
			break;
		}
		temp = temp->next;
	}
	return c;
}