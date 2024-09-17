#ifndef _KMP_H_
#define _KMP_H_

// typedef char* String;

// 获取字符串T的next数组
void GetNext(char *T, int *next);
void GetNextVal(char *T, int *nextval);
int Index_KMP(char *s, char *t, int pos);




#endif