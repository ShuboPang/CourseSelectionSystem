#include "link.h"
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

link* initLink(Course elem) {
    link* p = (link*)malloc(sizeof(link));//创建一个头结点
    if(p == NULL) {
        return NULL;
    }
    p->elem = elem;
    p->next = NULL;
    return p;
}

link* appendElem(link* p, Course elem) {
    link* temp = p;//创建临时结点temp
    // 遍历链表，找到最后一个
    for (;;) {
        if (temp->next == NULL) {
            break;
        }
        temp = temp->next;
    }
    //创建插入结点c
    link* c = (link*)malloc(sizeof(link));
    if (c == NULL) {
        return NULL;
    }
    c->elem = elem;
    //向链表中添加结点
    c->next = NULL;
    temp->next = c;
    return p;
}

link* insertElem(link* p, Course elem, int add) {
    link* temp = p;//创建临时结点temp
    //首先找到要插入位置的上一个结点
    for (int i = 1; i < add; i++) {
        if (temp == NULL) {
            printf("插入位置无效\n");
            return p;
        }
        temp = temp->next;
    }
    //创建插入结点c
    link* c = (link*)malloc(sizeof(link));
    if (c == NULL) {
        return NULL;
    }
    c->elem = elem;
    //向链表中插入结点
    c->next = temp->next;
    temp->next = c;
    return  p;
}

link* delElem(link* p, int add) {
    link* temp = p;
    //遍历到被删除结点的上一个结点
    for (int i = 1; i < add; i++) {
        temp = temp->next;
    }
    link* del = temp->next;//单独设置一个指针指向被删除结点，以防丢失
    temp->next = temp->next->next;//删除某个结点的方法就是更改前一个结点的指针域
    free(del);//手动释放该结点，防止内存泄漏
    return p;
}


link* updateElem(link* p, int add, Course newElem) {
    link* temp = p;
    for (int i = 0; i < add; i++) {
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

int getElemLength(link* p){
    int count = 0;
    link* temp = p;
    while (temp)
    {
        temp = temp->next;
        ++count;
    }
    return count;
}

Course getElem(link* p,int index){
    Course c;
    c.index = -1;
    int count = 0;
    link* temp = p;
    while (temp)
    {
        if(count == index){
            memcpy(&c,&(temp->elem),sizeof(Course));
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