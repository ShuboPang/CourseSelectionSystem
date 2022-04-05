#ifndef _LINK_H_
#define _LINK_H_



// ѧ����Ϣ�ṹ�壬���ڴ洢ѧ��������Ϣ
typedef struct {
	int index;
	char name[128];
	int type;
	int total_time;
	int teach_time;
	int test_time;
	int credit;
	int person_num;         //< ��������
	int num;                //< ѡ������
}Course;

// ����ڵ�
typedef struct Link {
	Course  elem;
	struct Link* next;
}link;

// �����ʼ�ĺ��������ڴ���ͷ�ڵ�
link* initLink(Course elem);

// ����ĩβ��ӵĺ�����p������elem�ǲ���Ľ���������
link* appendElem(link* p, Course elem);

// �������ĺ�����p������elem�ǲ���Ľ���������add�ǲ����λ��
link* insertElem(link* p, Course elem, int add);

// ɾ�����ĺ�����p�����������add����ɾ���ڵ��λ��
link* delElem(link* p, int add);

// ���½��ĺ�����newElemΪ�µ��������ֵ
link* updateElem(link* p, int add, Course newElem);


link* updateElemByCourseIndex(link* p, int course_index, Course newElem);

// ��������
int getElemLength(link* p);

// ȡ�ڵ�
Course getElem(link* p, int index);

/// <summary>
///  ���ݿγ̱�Ż�ȡ�γ�
/// </summary>
/// <param name="p"></param>
/// <param name="index"></param>
/// <returns></returns>
Course getElemByCourseIndex(link* p, int index);

#endif