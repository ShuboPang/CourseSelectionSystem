#ifndef _LINK_H_
#define _LINK_H_



// 学生信息结构体，用于存储学生基本信息
typedef struct {
	int index;
	char name[128];
	int type;
	int total_time;
	int teach_time;
	int test_time;
	int credit;
	int person_num;         //< 接纳人数
	int num;                //< 选课人数
}Course;

// 链表节点
typedef struct Link {
	Course  elem;
	struct Link* next;
}link;

// 链表初始的函数，用于创建头节点
link* initLink(Course elem);

// 链表末尾添加的函数，p是链表，elem是插入的结点的数据域
link* appendElem(link* p, Course elem);

// 链表插入的函数，p是链表，elem是插入的结点的数据域，add是插入的位置
link* insertElem(link* p, Course elem, int add);

// 删除结点的函数，p代表操作链表，add代表删除节点的位置
link* delElem(link* p, int add);

// 更新结点的函数，newElem为新的数据域的值
link* updateElem(link* p, int add, Course newElem);


link* updateElemByCourseIndex(link* p, int course_index, Course newElem);

// 求链表长度
int getElemLength(link* p);

// 取节点
Course getElem(link* p, int index);

/// <summary>
///  根据课程编号获取课程
/// </summary>
/// <param name="p"></param>
/// <param name="index"></param>
/// <returns></returns>
Course getElemByCourseIndex(link* p, int index);

#endif