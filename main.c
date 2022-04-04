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
	printf("请选择操作：");
	scanf("%d",&a);
	return a;
}

int FirstPage(){
	ShowTitle("欢迎使用学生管理系统");
	printf("		1. 进入选课 \n");
	printf("		2. 课程操作 \n");
	printf("		3. 学生管理 \n");
	printf("		0. 退出 \n");
	return ShowOptionSel();
}

/// <summary>
/// 选课操作
/// </summary>
/// <returns></returns>
int SelectionCourseOPtion() {
	ShowTitle("选课操作");
	printf("		1. 显示学生选课结果 \n");
	printf("		2. 开始选课 \n");
	printf("		3. 查询 \n");
	printf("		0. 退出 \n");
	return ShowOptionSel();
}

/// <summary>
/// 学生选课结果
/// </summary>
/// <returns></returns>
int SelectionCourseOPtion_display() {
	ShowTitle("学生选课结果");



	return ShowOptionSel();
}


int SelectionCourse() {
	int step = SelectionCourseOPtion();
	if (step == 1) {
		
	}
	return step;
}

/// 课程操作
int CourseOption(){
	ShowTitle("课程操作");
	printf("		1. 显示所有课程 \n");
	printf("		2. 修改课程 \n");
	printf("		3. 插入课程 \n");
	printf("		4. 删除课程 \n");
	printf("		0. 退出课程管理 \n");
	return ShowOptionSel();
}

/// <summary>
/// 插入课程
/// </summary>
/// <returns></returns>
int CourseOption_insert(){
	ShowTitle("插入课程");
	Course s;
	printf("请按以下个数输入：\n");
	printf("课程编号   课程名称 课程性质 总学时 授课学时 实验或上机学时  学分 课程容量 \n");
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
	printf(" 	1:继续插入	\n");
	printf(" 	0:返回上一层 \n");
	printf("请选择操作：");
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
/// 显示所有课程
/// </summary>
/// <returns></returns>
int DisplayShowCourse(){
	ShowTitle("课程列表");
	printf("课程总数 %d",getElemLength(course_link));
	printf("课程编号   课程名称 课程性质 总学时 授课学时 实验或上机学时  学分 课程容量 \n");
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
	printf("输入任意值返回上一层\n");
	return ShowOptionSel();
} 


void InputErrorTip(){
	system("CLS");
	int a = 0;
	printf("----------------------------------------------------------------------\n");
	printf(" 		输入错误                      \n");
	printf("----------------------------------------------------------------------\n");

	printf("\n");
	printf("\n");
	printf("输入任意值返回上一层\n");
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
		if(substep == 0){		//< 退出课程管理
			break;
		}
		else if(substep == 1){		//< 显示所有课程
			DisplayShowCourse();
			goto COURSE_OPTION;
		}
		else if (substep == 2) {		//< 修改课程
			CourseOption_update();
			goto COURSE_OPTION;
		}
		else if(substep == 3){		//< 插入课程
			CourseOption_insert();
			goto COURSE_OPTION;
		}
		else if (substep == 4) {		//< 删除课程
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
