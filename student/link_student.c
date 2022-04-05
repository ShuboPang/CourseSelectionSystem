#include "link_student.h"
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

linkStudent* initLink_student(Student elem) {
	linkStudent* p = (linkStudent*)malloc(sizeof(linkStudent));//����һ��ͷ���
	if (p == NULL) {
		return NULL;
	}
	p->elem = elem;
	p->next = NULL;
	return p;
}

linkStudent* appendElem_student(linkStudent* p, Student elem) {
	linkStudent* temp = p;//������ʱ���temp
	// ���������ҵ����һ��
	for (;;) {
		if (temp->next == NULL) {
			break;
		}
		temp = temp->next;
	}
	//����������c
	linkStudent* c = (linkStudent*)malloc(sizeof(linkStudent));
	if (c == NULL) {
		return NULL;
	}
	c->elem = elem;
	//����������ӽ��
	c->next = NULL;
	temp->next = c;
	return p;
}

linkStudent* insertElem_student(linkStudent* p, Student elem, int add) {
	linkStudent* temp = p;//������ʱ���temp
	//�����ҵ�Ҫ����λ�õ���һ�����
	for (int i = 1; i < add; i++) {
		if (temp == NULL) {
			printf("����λ����Ч\n");
			return p;
		}
		temp = temp->next;
	}
	//����������c
	linkStudent* c = (linkStudent*)malloc(sizeof(linkStudent));
	if (c == NULL) {
		return NULL;
	}
	c->elem = elem;
	//�������в�����
	c->next = temp->next;
	temp->next = c;
	return  p;
}

linkStudent* delElem_student(linkStudent* p, int add) {
	linkStudent* temp = p;
	//��������ɾ��������һ�����
	for (int i = 1; i < add; i++) {
		temp = temp->next;
	}
	linkStudent* del = temp->next;//��������һ��ָ��ָ��ɾ����㣬�Է���ʧ
	temp->next = temp->next->next;//ɾ��ĳ�����ķ������Ǹ���ǰһ������ָ����
	free(del);//�ֶ��ͷŸý�㣬��ֹ�ڴ�й©
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