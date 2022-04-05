#ifndef _LINK_STUDENT_H_
#define _LINK_STUDENT_H_



// ѧ����Ϣ�ṹ�壬���ڴ洢ѧ��������Ϣ
typedef struct {
	int index;
	char name[128];
	char english_name[128];
	int course[4];
	int course_num;
	int total;
}Student;

// ����ڵ�
typedef struct LinkStudent {
	Student  elem;
	struct LinkStudent* next;
}linkStudent;

// �����ʼ�ĺ��������ڴ���ͷ�ڵ�
linkStudent* initLink_student(Student elem);

// ����ĩβ��ӵĺ�����p������elem�ǲ���Ľ���������
linkStudent* appendElem_student(linkStudent* p, Student elem);

// �������ĺ�����p������elem�ǲ���Ľ���������add�ǲ����λ��
linkStudent* insertElem_student(linkStudent* p, Student elem, int add);

// ɾ�����ĺ�����p�����������add����ɾ���ڵ��λ��
linkStudent* delElem_student(linkStudent* p, int add);

// ���½��ĺ�����newElemΪ�µ��������ֵ
linkStudent* updateElem_student(linkStudent* p, int add, Student newElem);

linkStudent* updateElemByName_student(linkStudent* p, const char* name, Student newElem);

// ��������
int getElemLength_student(linkStudent* p);

// ȡ�ڵ�
Student getElem_student(linkStudent* p, int index);

/// <summary>
///  ���ݿγ̱�Ż�ȡ�γ�
/// </summary>
/// <param name="p"></param>
/// <param name="index"></param>
/// <returns></returns>
Student getElemByName_student(linkStudent* p, const char* name);

#endif