/**
 * @file p48_memoryPool.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 内存池，malloc会有内存碎片
 * @version 0.1
 * @date 2023-07-24
 * 
 * @copyright Copyright (c) 2023
 * 通过写一个通讯录小程序练习增删改查
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person
{
    char name[40];
    char phone[20];
    struct Person *next;
}Person_t;

void GetInput(Person_t *person);
void PrintPerson(Person_t *person);
void AddPerson(Person_t **contacts);
void ChangePerson(Person_t *contacts);
void DelPerson(Person_t **contacts);
Person_t *FindPerson(Person_t *contacts);
void DisplayContacts(Person_t *contacts);
void ReleaseContacts(Person_t **contacts);

void GetInput(Person_t *person)
{
    printf("Please enter a name: ");
    scanf("%s", person->name);
    printf("Please enter a tel number: ");
    scanf("%s", person->phone);
}

void AddPerson(Person_t **contacts)
{
    Person_t *person;
    Person_t *temp;
    person = (Person_t *)malloc(sizeof(Person_t));
    if (person == NULL) {
        printf("Malloc fail!\n");
        exit(1);
    }
    GetInput(person);

    if (*contacts != NULL) {
        temp = *contacts;
        *contacts = person;
        person->next = temp;
    }
    else {
        *contacts = person;
        person->next = NULL;
    }
}
void PrintPerson(Person_t *person)
{
    printf("Contacts : %s\n", person->name);
    printf("Phone : %s\n", person->phone);
}

int main(void)
{

}
