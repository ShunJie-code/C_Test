/**
 * @file p48_memoryPool.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 内存池，malloc会有内存碎片，先不free
 * @version 0.1
 * @date 2023-07-24
 *
 * @copyright Copyright (c) 2023
 * 通过写一个通讯录小程序练习增删改查
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

typedef struct Person
{
    char name[40];
    char phone[20];
    struct Person *next;
} Person_t;

Person_t *pool = NULL;
static int count;


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
    // 如果内存池非空则从内存池获取
    if (pool != NULL) {
        person = pool;
        pool = pool->next;
        count--;
    }
    else {
        person = (Person_t *)malloc(sizeof(Person_t));
        if (person == NULL)
        {
            printf("Malloc fail!\n");
            exit(1);
        }
    }
    GetInput(person);

    // 头插法
    if (*contacts != NULL)
    {
        temp = *contacts;
        *contacts = person;
        person->next = temp;
    }
    else
    {
        *contacts = person;
        person->next = NULL;
    }
}
void PrintPerson(Person_t *person)
{
    printf("Contacts : %s\n", person->name);
    printf("Phone : %s\n", person->phone);
}

Person_t *FindPerson(Person_t *contacts)
{
    Person_t *current;
    char input[40];

    printf("please enter contacts: ");
    scanf("%s", input);

    current = contacts;
    while (current != NULL && strcmp(current->name, input))
    {
        current = current->next;
    }
    return current;
}

void ChangePerson(Person_t *contacts)
{
    Person_t *person;
    person = FindPerson(contacts);
    // tips : 一定要注意
    if (person == NULL)
    {
        printf("Can't find the contacts!\n");
    }
    else
    {
        printf("Please enter a new telephone: ");
        scanf("%s", person->phone);
    }
}
// 需要对链表修改则传入指针的指针
void DelPerson(Person_t **contacts)
{
    Person_t *temp;
    Person_t *person;
    Person_t *current;
    Person_t *previous;

    person = FindPerson(*contacts);
    if (person == NULL)
    {
        printf("Can't find contacts!\n");
    }
    else
    {
        current = *contacts;
        previous = NULL;
        while (current != NULL && current != person)
        {
            previous = current;
            current = current->next;
        }
        if (previous == NULL)
        {
            *contacts = current->next;
        }
        else
        {
            previous->next = current->next;
        }
        // 判断内存池是不是有空位
        if (count < MAX)
        {
            if (pool != NULL)
            {
                temp = pool;
                pool = person;
                person->next = temp;
            }
            else {
                pool = person;
                person->next = NULL;
            }
            count++;
        }
        else{
            free(person);
        }
    }
}

void DisplayContacts(Person_t *contacts)
{
    Person_t *current;
    current = contacts;
    while (current != NULL)
    {
        PrintPerson(current);
        current = current->next;
    }
}

void ReleaseContacts(Person_t **contacts)
{
    Person_t *temp;
    while (*contacts != NULL)
    {
        temp = *contacts;
        *contacts = (*contacts)->next;
        free(temp);
    }
}

void ReleasePool(void)
{
    Person_t *temp;
    while (pool != NULL)
    {
        temp = pool;
        pool = pool->next;
        free(temp);   
    }
}
int main(void)
{
    int code;
    Person_t *contacts = NULL;
    Person_t *person;
    printf("|Welcome to the address book!|\n");
    printf("|1 Insert new contacts! |\n");
    printf("|2 Find contacts!       |\n");
    printf("|3 Change contacts!     |\n");
    printf("|4 Delete contacts!     |\n");
    printf("|5 Display all contacts!|\n");
    printf("|6 Quit address book!   |\n");

    while (1)
    {
        printf("Please enter a cmd: ");
        scanf("%d", &code);
        switch (code)
        {
        case 1:
            AddPerson(&contacts);
            break;
        case 2:
            person = FindPerson(contacts);
            if (person == NULL)
            {
                printf("Can't find contacts\n");
            }
            else
            {
                PrintPerson(person);
            }
            break;
        case 3:
            ChangePerson(contacts);
            break;
        case 4:
            DelPerson(&contacts);
            break;
        case 5:
            DisplayContacts(contacts);
            break;
        case 6:
            goto END;
        default:
            break;
        }
    }
END:
    ReleaseContacts(&contacts);
    ReleasePool();
    return 0;
}
