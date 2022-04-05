#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"
#include "fileoption.h"
#include "student/fileoption_student.h"
#include "student/link_student.h"

#define FILE_PATH "course.ini"
#define FILE_STUDENT_PATH "student.ini"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

static link* course_link = NULL;
static linkStudent* student_link = NULL;

void ShowTitle(const char* title) {
	system("CLS");
	printf("----------------------------------------------------------------------\n");
	printf(" 		%s ����:�ǳ�������                         \n", title);
	printf("----------------------------------------------------------------------\n");
	printf("\n");
}

int ShowOptionSel() {
	int a = 0;
	printf("\n");
	printf("\n");
	printf("��ѡ�������");
	scanf("%d", &a);
	return a;
}


void InputErrorTip() {
	system("CLS");
	int a = 0;
	printf("----------------------------------------------------------------------\n");
	printf(" 		�������                      \n");
	printf("----------------------------------------------------------------------\n");
	printf("\n");
	printf("\n");
	printf("�����������ֻ���һ��\n");
	scanf("%d", &a);
}


void SaveCourseFile() {
	writeFile(FILE_PATH, course_link);;
}

void SaveStudentFile() {
	writeFile_student(FILE_STUDENT_PATH, student_link);
}

int FirstPage() {
	ShowTitle("��ӭʹ��ѧ������ϵͳ");
	printf("		1. ����ѡ�� \n");
	printf("		2. �γ̲��� \n");
	printf("		3. ѧ������ \n");
	printf("		0. �˳� \n");
	return ShowOptionSel();
}

/// <summary>
/// ѡ�β���
/// </summary>
/// <returns></returns>
int SelectionCourseOption() {
	ShowTitle("ѡ�β���");
	printf("		1. ��ʾѧ��ѡ�ν�� \n");
	printf("		2. ��ʼѡ�� \n");
	printf("		3. ��ѯ \n");
	printf("		0. �˳� \n");
	return ShowOptionSel();
}

/// <summary>
/// ѧ��ѡ�ν��
/// </summary>
/// <returns></returns>
int SelectionCourseOption_display() {
	ShowTitle("ѧ��ѡ�ν��");
	printf("���  ѧ������  Ӣ������  �γ̱��1  �γ̱��2  �γ̱��3  �γ̱��4  ��ѡ�γ�����  ��ѧ�� \n");
	linkStudent* s = student_link;
	linkStudent* student_temp = student_link;
	int n = 0; 
	while (s)
	{
		n++;
		s = s->next;
	}
	if(n == 0){
		printf("����ѧ�����������ѧ��\n");
	} else {
		int i, j;
		// ð������ 
	    for (i = 0; i < n; ++i) {
	        // ֮ǰ��ѭ���Ѿ���i��Ԫ���͵�ĩβ������Ҫ�ٴαȽϣ��ʼ�ȥ����Ϊ����һ��Ԫ�رȽϣ�Ϊ�˱���������ʼ�һ
	        for (j = 0; j < n - i - 1; ++j) {
	            // �����ǰ��Ԫ�رȺ�һ��Ԫ��С���ͽ���
	            if (student_temp->elem.total > student_temp->next->elem.total) 
				{
	                s = student_temp;
	            }
	            else if(student_temp->elem.total < student_temp->next->elem.total){
					s = student_temp->next;
				}
				else if(student_temp->elem.total == student_temp->next->elem.total)
				{
					if(strcmp(student_temp->elem.english_name, student_temp->next->elem.english_name) > 0){
						s = student_temp->next;
					}
				}
	        }
			printf("%d 	  %s 	%s 	 %d 	%d 		%d 		%d 		%d 		%d\n", s->elem.index, s->elem.name, s->elem.english_name,
				s->elem.course[0], s->elem.course[1],
				s->elem.course[2], s->elem.course[3], s->elem.course_num, s->elem.total);
	    }
	}
	printf("--------------------------------------------------------------------------------------------\n");
	printf("\n");
	printf("\n");
	printf("		0. �˳� \n");
	return ShowOptionSel();
}

int electionCourseOption_sel() {

	ShowTitle("��ʼѡ��");
	printf("�γ̱��   �γ����� �γ����� ��ѧʱ �ڿ�ѧʱ ʵ����ϻ�ѧʱ  ѧ�� �γ����� ��ѡ����\n");
	link* s = course_link;
	while (s)
	{
		printf("%d 		%s 		%d 		%d 		%d 		%d 		%d    %d     %d\n",
			s->elem.index, s->elem.name, s->elem.type,
			s->elem.total_time, s->elem.teach_time,
			s->elem.test_time, s->elem.credit, s->elem.person_num, s->elem.num);
		s = s->next;
	}
START_SEL:
	printf("\n");
	printf("\n");
	printf("������ѧ������ �γ̱��\n");
	char stu[128];
	int course_index = 0;
	scanf("%s %d", &stu, &course_index);


	//< ���ѧ��
	Student st;
	memset(&st, 0, sizeof(Student));
	memcpy(&st.name, &stu, sizeof(stu));
	sprintf(st.english_name, "%s", "null");

	if (student_link == NULL) {
		student_link = initLink_student(st);
	}
	else
	{
		Student tmp = getElemByName_student(student_link, st.name);
		if (tmp.index != -1) {
			memcpy(&st, &tmp, sizeof(Student));
		}
		else {
			appendElem_student(student_link, st);
		}
	}
	Course c = getElemByCourseIndex(course_link, course_index);
	if (st.course_num == 4) {
		printf("��ѧ��ѡ���Ѿ��ﵽ4�� \n");
		printf("�����²���!\n");
		goto GOTO_MENU;
	}
	if (c.index == -1) {
		printf("%d  �γ̲����� !\n", course_index);
		printf("�����²���!\n");
	}
	else {

		if (c.num == c.person_num) {
			printf("ѡ���ε���������!\n");
			printf("�����²���!\n");
			goto GOTO_MENU;
		}

		if (st.total + c.credit > 10) {
			printf("��ѧ�ֳ���10��!\n");
			printf("�����²���!\n");
			goto GOTO_MENU;
		}
		int i;
		for (i = 0; i < st.course_num; i++)
		{
			if (st.course[i] == c.index) {
				printf("��ѡ����ÿγ̣������ظ�ѡ��\n");
				printf("�����²���!\n");
				goto GOTO_MENU;
				break;
			}
		}

		// �γ�״̬����
		c.num++;
		updateElemByCourseIndex(course_link, c.index, c);
		SaveCourseFile();

		// ѧ��״̬����
		st.course[st.course_num] = c.index;
		st.course_num++;
		st.total += c.credit;
		updateElemByName_student(student_link, st.name, st);
		SaveStudentFile();
		printf("ѡ�γɹ�!!\n");
	}
GOTO_MENU:
	printf("		1. ����ѡ�� \n");
	printf("		0. �˳� \n");
	int ret = ShowOptionSel();
	if (ret == 0) {
		return ret;
	}
	else if (ret == 1)
	{
		goto START_SEL;
	}
	else
	{
		InputErrorTip();
		goto GOTO_MENU;
	}
}


int SelectionCourse() {
	int step = 0;
SELECTION_COURSE:
	step = SelectionCourseOption();
	if (step == 0) {
		return 0;
	}
	else if (step == 1) {
		SelectionCourseOption_display();
	}
	else if (step == 2) {
		electionCourseOption_sel();
	}
	goto SELECTION_COURSE;
	return step;
}

/// �γ̲���
int CourseOption() {
	ShowTitle("�γ̲���");
	printf("		1. ��ʾ���пγ� \n");
	printf("		2. �޸Ŀγ� \n");
	printf("		3. ���ӿγ� \n");
	printf("		4. ɾ���γ� \n");
	printf("		0. �˳��γ̹��� \n");
	return ShowOptionSel();
}

/// <summary>
/// ���ӿγ�
/// </summary>
/// <returns></returns>
int CourseOption_insert() {
	ShowTitle("���ӿγ�");
	Course s;
INSERT_COURSE:
	memset(&s, 0, sizeof(Course));
	printf("�밴���¸�ʽ���룺\n");
	printf("�γ̱��  �γ����� �γ����� ��ѧʱ �ڿ�ѧʱ ʵ����ϻ�ѧʱ  ѧ�� �γ����� \n");
	scanf("%d %s %d %d %d %d %d %d", &s.index, s.name, &s.type,
		&s.total_time, &s.teach_time,
		&s.test_time, &s.credit, &s.person_num);
	s.num = 0;
	if (course_link == NULL) {
		course_link = initLink(s);
	} else {
		Course tmp = getElemByCourseIndex(course_link, s.index);
		if (tmp.index == -1) {
			appendElem(course_link, s);
		}
		else {
			printf("--------------------------------------------------------------------------------------------\n");
			printf("�γ̱�ų�ͻ��\n");
			printf("--------------------------------------------------------------------------------------------\n");
		}
	}
	int a = 0;
INPUT_ERROR:
	printf(" 	1:��������	\n");
	printf(" 	0:������һ�� \n");
	printf("��ѡ�������");
	scanf("%d", &a);
	if (a == 0) {
		SaveCourseFile();
		return a;
	}
	else if (a == 1) {
		goto INSERT_COURSE;
	}
	goto INPUT_ERROR;
}

int CourseOption_delete() {


}

int CourseOption_update() {
	ShowTitle("�޸Ŀγ�");
	Course s;
	Course c;
	int a;
	printf("�밴���¸�ʽ���룺\n");
	printf("�γ̱��   �γ����� �γ����� ��ѧʱ �ڿ�ѧʱ ʵ����ϻ�ѧʱ  ѧ�� �γ����� ��ѡ����\n");
UPDATE_COURSE:
	scanf("%d %s %d %d %d %d %d %d %d", &s.index, &s.name, &s.type,
		&s.total_time, &s.teach_time,
		&s.test_time, &s.credit, &s.person_num, &s.num);
	c = getElemByCourseIndex(course_link, s.index);
	if (c.index == -1) {
		printf("%d  �γ̲�����", s.index);
	}
	else {
		updateElemByCourseIndex(course_link, s.index, s);
		SaveCourseFile();
		printf("���³ɹ�!!\n");
	}
INPUT_ERROR:
	printf(" 	1:��������	\n");
	printf(" 	0:������һ�� \n");
	printf("��ѡ�������");
	scanf("%d", &a);
	if (a == 0) {
		return a;
	}
	else if (a == 1) {
		goto UPDATE_COURSE;
	}
	goto INPUT_ERROR;
}

/// <summary>
/// ��ʾ���пγ�
/// </summary>
/// <returns></returns>
int DisplayShowCourse() {
	ShowTitle("�γ��б�");
	printf("�γ����� %d \n", getElemLength(course_link));
	printf("�γ̱��   �γ����� �γ����� ��ѧʱ �ڿ�ѧʱ ʵ����ϻ�ѧʱ  ѧ�� �γ����� ��ѡ����\n");
	link* s = course_link;
	while (s)
	{
		printf("%d 		%s 		%d 		%d 		%d 		%d 		%d     %d    %d\n",
			s->elem.index, s->elem.name, s->elem.type,
			s->elem.total_time, s->elem.teach_time,
			s->elem.test_time, s->elem.credit, s->elem.person_num, s->elem.num);
		s = s->next;
	}
	printf("--------------------------------------------------------------------------------------------\n");
	printf("\n");
	printf("\n");
	printf("��������ֵ������һ��\n");
	return ShowOptionSel();
}


int main(int argc, char* argv[]) {

	int step = 0;
	int substep = 0;
	readFile(FILE_PATH, &course_link);
	readFile_student(FILE_STUDENT_PATH, &student_link);


MAIN_MENU:
	step = FirstPage();

	switch (step)
	{
	case 1:
		SelectionCourse();
		break;
	case 2:
	COURSE_OPTION:
		substep = CourseOption();
		if (substep == 0) {		//< �˳��γ̹���
			break;
		}
		else if (substep == 1) {		//< ��ʾ���пγ�
			DisplayShowCourse();
		}
		else if (substep == 2) {		//< �޸Ŀγ�
			CourseOption_update();
		}
		else if (substep == 3) {		//< ����γ�
			CourseOption_insert();
		}
		else if (substep == 4) {		//< ɾ���γ�
			CourseOption_delete();
		}
		else if (substep == 5) {
			
		}
		else {
			InputErrorTip();
		}
		goto COURSE_OPTION;
		break;
	case 0:
		return 0;
	default:
		InputErrorTip();
		break;
	}
	goto MAIN_MENU;
	return 0;
}
