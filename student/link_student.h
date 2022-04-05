#ifndef _LINK_STUDENT_H_
#define _LINK_STUDENT_H_



// 学生信息结构体，用于存储学生基本信息
typedef struct{
    int index;
    char name[128];
    char english_name[128];
    int course[4];
    int course_num;
    int total;
}Student;

// 链表节点
typedef struct LinkStudent {
    Student  elem;
    struct LinkStudent* next;
}linkStudent;

// 链表初始的函数，用于创建头节点
linkStudent* initLink_student(Student elem);

// 链表末尾添加的函数，p是链表，elem是插入的结点的数据域
linkStudent* appendElem_student(linkStudent* p, Student elem);

// 链表插入的函数，p是链表，elem是插入的结点的数据域，add是插入的位置
linkStudent* insertElem_student(linkStudent* p, Student elem, int add);

// 删除结点的函数，p代表操作链表，add代表删除节点的位置
linkStudent* delElem_student(linkStudent* p, int add);

// 更新结点的函数，newElem为新的数据域的值
linkStudent* updateElem_student(linkStudent* p, int add, Student newElem);

// 求链表长度
int getElemLength_student(linkStudent* p);

// 取节点
Student getElem_student(linkStudent* p,int index);

/// <summary>
///  根据课程编号获取课程
/// </summary>
/// <param name="p"></param>
/// <param name="index"></param>
/// <returns></returns>
Student getElemByName_student(linkStudent* p, const char* name);

#endif