#ifndef _FILEOPTION_STUDENT_H_
#define _FILEOPTION_STUDENT_H_
#include "link_student.h"

/// 读文件
int readFile_student(const char* fileName, linkStudent** stu);

/// 写文件
int writeFile_student(const char* fileName, linkStudent* stu);

#endif