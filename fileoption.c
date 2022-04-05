#include "fileoption.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int readFile(const char* fileName, link** course){
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
        Course s;
        int ret = fscanf(fp, "%d %s %d %d %d %d %d %d %d\n", &s.index, &s.name, &s.type,
                         &s.total_time, &s.teach_time,
                         &s.test_time,&s.credit,&s.person_num, &s.num);
        if(ret == EOF) {
            break;
        }
        if(*course == NULL) {
       		*course = initLink(s);
		} else {
			appendElem(*course, s);
		} 
    }
    int len = (int)ftell(fp);
    fclose(fp);
    return len;
}

int writeFile(const char* fileName, link* course) {
	
    FILE* fp = fopen(fileName, "w");
    link* temp = course;
    if (fp == NULL) {
        fprintf(stderr,"Fail to open file!\t\n");
        return -1;
    }

    // 将指针移动至文件开始
    fseek(fp, 0, SEEK_SET);
    for(;;){
        Course s = temp->elem;
            fprintf(fp, "%d %s %d %d %d %d %d %d %d\n", s.index, s.name, s.type,
                         s.total_time, s.teach_time,
                         s.test_time,s.credit,s.person_num, s.num);
        temp = temp->next;
        if(temp == NULL) {
            break;
        }
    }  
    fclose(fp);
    return 0;
}