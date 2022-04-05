#include "link.h"
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

link* initLink(Course elem) {
	link* p = (link*)malloc(sizeof(link));//����һ��ͷ���
	if (p == NULL) {
		return NULL;
	}
	p->elem = elem;
	p->next = NULL;
	return p;
}

link* appendElem(link* p, Course elem) {
	link* temp = p;//������ʱ���temp
	// ���������ҵ����һ��
	for (;;) {
		if (temp->next == NULL) {
			break;
		}
		temp = temp->next;
	}
	//����������c
	link* c = (link*)malloc(sizeof(link));
	if (c == NULL) {
		return NULL;
	}
	c->elem = elem;
	//����������ӽ��
	c->next = NULL;
	temp->next = c;
	return p;
}

link* insertElem(link* p, Course elem, int add) {
	link* temp = p;//������ʱ���temp
	int i; 
	//�����ҵ�Ҫ����λ�õ���һ�����
	for (i = 1; i < add; i++) {
		if (temp == NULL) {
			printf("����λ����Ч\n");
			return p;
		}
		temp = temp->next;
	}
	//����������c
	link* c = (link*)malloc(sizeof(link));
	if (c == NULL) {
		return NULL;
	}
	c->elem = elem;
	//�������в�����
	c->next = temp->next;
	temp->next = c;
	return  p;
}

link* delElem(link* p, int add) {
	link* temp = p;
	int i;
	//��������ɾ��������һ�����
	for (i = 1; i < add; i++) {
		temp = temp->next;
	}
	link* del = temp->next;//��������һ��ָ��ָ��ɾ����㣬�Է���ʧ
	temp->next = temp->next->next;//ɾ��ĳ�����ķ������Ǹ���ǰһ������ָ����
	free(del);//�ֶ��ͷŸý�㣬��ֹ�ڴ�й©
	return p;
}


link* updateElem(link* p, int add, Course newElem) {
	link* temp = p;
	int i;
	for (i = 0; i < add; i++) {
		temp = temp->next;
	}
	temp->elem = newElem;
	return p;
}

link* updateElemByCourseIndex(link* p, int course_index, Course newElem) {
	link* temp = p;
	while (temp)
	{
		if (temp->elem.index == course_index) {
			temp->elem = newElem;
			break;
		}
		temp = temp->next;
	}
	return p;
}

int getElemLength(link* p) {
	int count = 0;
	link* temp = p;
	while (temp)
	{
		temp = temp->next;
		++count;
	}
	return count;
}

Course getElem(link* p, int index) {
	Course c;
	c.index = -1;
	int count = 0;
	link* temp = p;
	while (temp)
	{
		if (count == index) {
			memcpy(&c, &(temp->elem), sizeof(Course));
			break;
		}
		temp = temp->next;
		++count;
	}
	return c;
}

Course getElemByCourseIndex(link* p, int index) {
	Course c;
	c.index = -1;
	int count = 0;
	link* temp = p;
	while (temp)
	{
		if (temp->elem.index == index) {
			memcpy(&c, &(temp->elem), sizeof(Course));
			break;
		}
		temp = temp->next;
		++count;
	}
	return c;
}
