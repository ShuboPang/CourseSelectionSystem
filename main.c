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
	printf(" 		%s 作者:非虫电子设计                         \n", title);
	printf("----------------------------------------------------------------------\n");
	printf("\n");
}

int ShowOptionSel() {
	int a = 0;
	printf("\n");
	printf("\n");
	printf("请选择操作：");
	scanf("%d", &a);
	return a;
}


void InputErrorTip() {
	system("CLS");
	int a = 0;
	printf("----------------------------------------------------------------------\n");
	printf(" 		输入错误                      \n");
	printf("----------------------------------------------------------------------\n");
	printf("\n");
	printf("\n");
	printf("输入任意数字回上一层\n");
	scanf("%d", &a);
}


void SaveCourseFile() {
	writeFile(FILE_PATH, course_link);;
}

void SaveStudentFile() {
	writeFile_student(FILE_STUDENT_PATH, student_link);
}

int FirstPage() {
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
int SelectionCourseOption() {
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
int SelectionCourseOption_display() {
	ShowTitle("学生选课结果");
	printf("编号  学生姓名  英文名字  课程编号1  课程编号2  课程编号3  课程编号4  已选课程数量  总学分 \n");
	linkStudent* s = student_link;
	linkStudent* student_temp = student_link;
	int n = 0; 
	while (s)
	{
		n++;
		s = s->next;
	}
	if(n == 0){
		printf("暂无学生，请先添加学生\n");
	} else {
		int i, j;
		// 冒泡排序 
	    for (i = 0; i < n; ++i) {
	        // 之前的循环已经将i个元素送到末尾，不需要再次比较，故减去，因为跟后一个元素比较，为了避免溢出，故减一
	        for (j = 0; j < n - i - 1; ++j) {
	            // 如果当前的元素比后一个元素小，就交换
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
	printf("		0. 退出 \n");
	return ShowOptionSel();
}

int electionCourseOption_sel() {

	ShowTitle("开始选课");
	printf("课程编号   课程名称 课程性质 总学时 授课学时 实验或上机学时  学分 课程容量 已选人数\n");
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
	printf("请输入学生姓名 课程编号\n");
	char stu[128];
	int course_index = 0;
	scanf("%s %d", &stu, &course_index);


	//< 检查学生
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
		printf("该学生选课已经达到4个 \n");
		printf("请重新操作!\n");
		goto GOTO_MENU;
	}
	if (c.index == -1) {
		printf("%d  课程不存在 !\n", course_index);
		printf("请重新操作!\n");
	}
	else {

		if (c.num == c.person_num) {
			printf("选本课的人数已满!\n");
			printf("请重新操作!\n");
			goto GOTO_MENU;
		}

		if (st.total + c.credit > 10) {
			printf("总学分超过10分!\n");
			printf("请重新操作!\n");
			goto GOTO_MENU;
		}
		int i;
		for (i = 0; i < st.course_num; i++)
		{
			if (st.course[i] == c.index) {
				printf("已选择过该课程，不能重复选择！\n");
				printf("请重新操作!\n");
				goto GOTO_MENU;
				break;
			}
		}

		// 课程状态更新
		c.num++;
		updateElemByCourseIndex(course_link, c.index, c);
		SaveCourseFile();

		// 学生状态更新
		st.course[st.course_num] = c.index;
		st.course_num++;
		st.total += c.credit;
		updateElemByName_student(student_link, st.name, st);
		SaveStudentFile();
		printf("选课成功!!\n");
	}
GOTO_MENU:
	printf("		1. 继续选课 \n");
	printf("		0. 退出 \n");
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

/// 课程操作
int CourseOption() {
	ShowTitle("课程操作");
	printf("		1. 显示所有课程 \n");
	printf("		2. 修改课程 \n");
	printf("		3. 增加课程 \n");
	printf("		4. 删除课程 \n");
	printf("		0. 退出课程管理 \n");
	return ShowOptionSel();
}

/// <summary>
/// 增加课程
/// </summary>
/// <returns></returns>
int CourseOption_insert() {
	ShowTitle("增加课程");
	Course s;
INSERT_COURSE:
	memset(&s, 0, sizeof(Course));
	printf("请按以下格式输入：\n");
	printf("课程编号  课程名称 课程性质 总学时 授课学时 实验或上机学时  学分 课程容量 \n");
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
			printf("课程编号冲突！\n");
			printf("--------------------------------------------------------------------------------------------\n");
		}
	}
	int a = 0;
INPUT_ERROR:
	printf(" 	1:继续插入	\n");
	printf(" 	0:返回上一层 \n");
	printf("请选择操作：");
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
	ShowTitle("修改课程");
	Course s;
	Course c;
	int a;
	printf("请按以下格式输入：\n");
	printf("课程编号   课程名称 课程性质 总学时 授课学时 实验或上机学时  学分 课程容量 已选人数\n");
UPDATE_COURSE:
	scanf("%d %s %d %d %d %d %d %d %d", &s.index, &s.name, &s.type,
		&s.total_time, &s.teach_time,
		&s.test_time, &s.credit, &s.person_num, &s.num);
	c = getElemByCourseIndex(course_link, s.index);
	if (c.index == -1) {
		printf("%d  课程不存在", s.index);
	}
	else {
		updateElemByCourseIndex(course_link, s.index, s);
		SaveCourseFile();
		printf("更新成功!!\n");
	}
INPUT_ERROR:
	printf(" 	1:继续更新	\n");
	printf(" 	0:返回上一层 \n");
	printf("请选择操作：");
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
/// 显示所有课程
/// </summary>
/// <returns></returns>
int DisplayShowCourse() {
	ShowTitle("课程列表");
	printf("课程总数 %d \n", getElemLength(course_link));
	printf("课程编号   课程名称 课程性质 总学时 授课学时 实验或上机学时  学分 课程容量 已选人数\n");
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
	printf("输入任意值返回上一层\n");
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
		if (substep == 0) {		//< 退出课程管理
			break;
		}
		else if (substep == 1) {		//< 显示所有课程
			DisplayShowCourse();
		}
		else if (substep == 2) {		//< 修改课程
			CourseOption_update();
		}
		else if (substep == 3) {		//< 插入课程
			CourseOption_insert();
		}
		else if (substep == 4) {		//< 删除课程
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
