#include "fileoption_student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int readFile_student(const char* fileName, linkStudent** stu){
    FILE* fp = fopen(fileName, "ab+");
    if (fp == NULL) {
        printf("Fail to open file!\n");
        return -1;
    }
    // 将指针移动至文件开头
    fseek(fp, 0, SEEK_END);
    if((int)ftell(fp) == 0){
        return 0;
    }

    rewind(fp);
    for(;;){
        Student s;
        int ret = fscanf(fp, "%d %s %s %d %d %d %d %d %d\n", &s.index, &s.name, &s.english_name,
            &s.course[0], &s.course[1],
            &s.course[2], &s.course[3],&s.course_num, &s.total);
        if(ret == EOF) {
            break;
        }
        if(*stu == NULL) {
       		*stu = initLink(s);
		} else {
			appendElem(*stu, s);
		} 
    }
    int len = (int)ftell(fp);
    fclose(fp);
    return len;
}

int writeFile_student(const char* fileName, linkStudent* stu) {
	
    FILE* fp = fopen(fileName, "w");
    linkStudent* temp = stu;
    if (fp == NULL) {
        fprintf(stderr,"Fail to open file!\t\n");
        return -1;
    }

    // 将指针移动至文件开始
    fseek(fp, 0, SEEK_SET);
    for(;;){
        Student s = temp->elem;
            fprintf(fp, "%d %s %s %d %d %d %d %d %d\n", s.index, s.name, s.english_name,
                         s.course[0], s.course[1],
                s.course[2], s.course[3], s.course_num,s.total);
        temp = temp->next;
        if(temp == NULL) {
            break;
        }
    }  
    fclose(fp);
    return 0;
}