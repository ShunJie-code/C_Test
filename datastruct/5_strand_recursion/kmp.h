#ifndef _KMP_H_
#define _KMP_H_

// typedef char* String;

// 获取字符串T的next数组
void GetNext(char *T, int *next);
int Index_KMP(char *s, char *t, int pos);

// 改良后的获取字符串T的next数组与KMP算法
void GetNextVal(char *T, int *nextval);
int Index_KMP_BETTER(char *s, char *t, int pos);



#endif