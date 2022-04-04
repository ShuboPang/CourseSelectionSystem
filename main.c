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

void ShowTitle(char* title){
	system("CLS");
	printf("----------------------------------------------------------------------\n");
	printf(" 		%s                          \n",title);
	printf("----------------------------------------------------------------------\n");
	printf("\n");
}

int ShowOptionSel(){
	int a = 0;
	printf("\n");
	printf("\n");
	printf("��ѡ�������");
	scanf("%d",&a);
	return a;
}

int FirstPage(){
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
int SelectionCourseOPtion() {
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
int SelectionCourseOPtion_display() {
	ShowTitle("ѧ��ѡ�ν��");



	return ShowOptionSel();
}


int SelectionCourse() {
	int step = SelectionCourseOPtion();
	if (step == 1) {
		
	}
	return step;
}

/// �γ̲���
int CourseOption(){
	ShowTitle("�γ̲���");
	printf("		1. ��ʾ���пγ� \n");
	printf("		2. �޸Ŀγ� \n");
	printf("		3. ����γ� \n");
	printf("		4. ɾ���γ� \n");
	printf("		0. �˳��γ̹��� \n");
	return ShowOptionSel();
}

/// <summary>
/// ����γ�
/// </summary>
/// <returns></returns>
int CourseOption_insert(){
	ShowTitle("����γ�");
	Course s;
	printf("�밴���¸������룺\n");
	printf("�γ̱��   �γ����� �γ����� ��ѧʱ �ڿ�ѧʱ ʵ����ϻ�ѧʱ  ѧ�� �γ����� \n");
	INSERT_COURSE:
	scanf("%d %s %d %d %d %d %d %d", &s.index, &s.name, &s.type,
                         &s.total_time, &s.teach_time,
                         &s.test_time,&s.credit,&s.person_num);
	if(course_link == NULL) {
		course_link = initLink(s);
	} else {
		appendElem(course_link, s);
	} 
	int a = 0;
	INPUT_ERROR:
	printf("\n");
	printf("\n");
	printf(" 	1:��������	\n");
	printf(" 	0:������һ�� \n");
	printf("��ѡ�������");
	scanf("%d",&a);
	if(a == 0){
		writeFile(FILE_PATH,course_link);
		return a;
	}
	else if(a == 1){
		goto INSERT_COURSE;
	}
	goto INPUT_ERROR;
}

int CourseOption_delete() {
	

}

int CourseOption_update() {


}

/// <summary>
/// ��ʾ���пγ�
/// </summary>
/// <returns></returns>
int DisplayShowCourse(){
	ShowTitle("�γ��б�");
	printf("�γ����� %d",getElemLength(course_link));
	printf("�γ̱��   �γ����� �γ����� ��ѧʱ �ڿ�ѧʱ ʵ����ϻ�ѧʱ  ѧ�� �γ����� \n");
	link* s = course_link;
	while (s)
	{
		printf("%d %s %d %d %d %d %d %d \n", s->elem.index, s->elem.name, s->elem.type,
			s->elem.total_time, s->elem.teach_time,
			s->elem.test_time, s->elem.credit, s->elem.person_num);
		s = s->next;
	}

	printf("\n");
	printf("\n");
	printf("��������ֵ������һ��\n");
	return ShowOptionSel();
} 


void InputErrorTip(){
	system("CLS");
	int a = 0;
	printf("----------------------------------------------------------------------\n");
	printf(" 		�������                      \n");
	printf("----------------------------------------------------------------------\n");

	printf("\n");
	printf("\n");
	printf("��������ֵ������һ��\n");
	scanf("%d",&a);
}

int main(int argc, char *argv[]) {

	int step =0;
	int substep = 0;
	readFile(FILE_PATH,&course_link);


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
		if(substep == 0){		//< �˳��γ̹���
			break;
		}
		else if(substep == 1){		//< ��ʾ���пγ�
			DisplayShowCourse();
			goto COURSE_OPTION;
		}
		else if (substep == 2) {		//< �޸Ŀγ�
			CourseOption_update();
			goto COURSE_OPTION;
		}
		else if(substep == 3){		//< ����γ�
			CourseOption_insert();
			goto COURSE_OPTION;
		}
		else if (substep == 4) {		//< ɾ���γ�
			CourseOption_delete();
			goto COURSE_OPTION;
		}
		else{
			InputErrorTip();
			goto COURSE_OPTION;
		}
		break;
	case 0:
		return 0;
	default:
		InputErrorTip();
		goto MAIN_MENU;
		break;
	}
	goto MAIN_MENU;
	return 0;
}
