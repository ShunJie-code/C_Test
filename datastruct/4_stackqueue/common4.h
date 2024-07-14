#ifndef _COMMON_4_H_
#define _COMMON_4_H_

#define MAXSIZE 100
#define SUCCESS 0 
#define ERROR -1
#define TRUE 1
#define FALSE 0

// #define CHAR_TYPE
#define INT_TYPE

#ifdef INT_TYPE
typedef int ElemType;
#elif defined CHAR_TYPE
typedef char ElemType;
#endif

typedef int Status;

#endif