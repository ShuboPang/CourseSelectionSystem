#ifndef _FILEOPTION_H_
#define _FILEOPTION_H_
#include "link.h"

/// 读文件
int readFile(const char* fileName, link** course);

/// 写文件
int writeFile(const char* fileName, link* course);

#endif