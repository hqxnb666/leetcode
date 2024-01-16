#define _CRT_SECURE_NO_WARNINGS

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
ʵ��һ��ʮ�������ֱ��������밴�����ִ�С�����˳�򷵻�һ���������У������д����� 1 ��ʼ�������������� cnt λ���ֽ�����



ʾ�� 1:

���룺cnt = 2
�����[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99]
int* countNumbers(int cnt, int* returnSize) {
    int maxNumber = 1;
    for (int i = 0; i < cnt; i++) {
        maxNumber *= 10;
    }
    maxNumber -= 1; // ��ȥ1�Եõ�����cntλ����

    *returnSize = maxNumber; // ���÷�������Ĵ�С

    int* arr = malloc(maxNumber * sizeof(int)); // �����ڴ�
    if (arr == NULL) {
        *returnSize = 0; // ����ڴ����ʧ�ܣ��򷵻ش�СΪ0
        return NULL;
    }

    for (int i = 0; i < maxNumber; i++) {
        arr[i] = i + 1; // �������
    }

    return arr;
}
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef char STDataType;

typedef struct Stack
{
    STDataType* a;
    int top;
    int capacity;
}ST;

void STInit(ST* pst);

void STDestroy(ST* pst);

void STPush(ST* pst, STDataType x);

void STPop(ST* pst);

bool STEmpty(ST* pst);

STDataType STTop(ST* pst);

STDataType STSize(ST* pst);

void STInit(ST* pst)
{
    assert(pst);
    pst->a = NULL;
    pst->capacity = 0;
    pst->top = 0;
    //topΪ-1����ָ��ջ��Ԫ��  Ϊ0����ָ��ջ��Ԫ�ص���һ��λ��

}
void STDestroy(ST* pst)
{
    assert(pst);
    free(pst->a);
    pst->a = NULL;
    pst->capacity = pst->top = 0;
}
void STPush(ST* pst, STDataType x)
{
    assert(pst);
    if (pst->top == pst->capacity)
    {
        int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
        STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
        if (tmp == NULL)
        {
            perror("realloc fail");
        }
        pst->a = tmp;
        pst->capacity = newcapacity;
    }
    pst->a[pst->top] = x;
    pst->top++;
}
void STPop(ST* pst)
{
    assert(pst);
    assert(pst->top);
    pst->top--;
}
bool STEmpty(ST* pst)
{
    assert(pst);
    return pst->top == 0;
}
STDataType STTop(ST* pst)
{
    assert(pst);
    assert(pst->top > 0);
    return pst->a[pst->top - 1];
}

STDataType STSize(ST* pst)
{
    assert(pst);
    return pst->top;
}
bool isValid(char* s) {
    ST st;
    STInit(&st);
    while (*s)
    {
        if (*s == '(' || *s == '{' || *s == '[')
        {
            STPush(&st, *s);
        }
        else
        {
            if (STEmpty(&st))
            {
                STDestroy(&st);
                return false;
            }

            char top = STTop(&st);
            STPop(&st);
            //����������˳������
            //��������������ƥ��
            if ((*s == ')' && top != '(')
                || (*s == '}' && top != '{')
                || (*s == ']' && top != '['))
            {
                STDestroy(&st);
                return false;
            }
        }
        ++s;
    }
    bool ret = STEmpty(&st);
    //�������������Ҷ�
    STDestroy(&st);
    return ret;
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef char STDataType;

typedef struct Stack
{
    STDataType* a;
    int top;
    int capacity;
}ST;

void STInit(ST* pst);

void STDestroy(ST* pst);

void STPush(ST* pst, STDataType x);

void STPop(ST* pst);

bool STEmpty(ST* pst);

STDataType STTop(ST* pst);

STDataType STSize(ST* pst);

void STInit(ST* pst)
{
    assert(pst);
    pst->a = NULL;
    pst->capacity = 0;
    pst->top = 0;
    //topΪ-1����ָ��ջ��Ԫ��  Ϊ0����ָ��ջ��Ԫ�ص���һ��λ��

}
void STDestroy(ST* pst)
{
    assert(pst);
    free(pst->a);
    pst->a = NULL;
    pst->capacity = pst->top = 0;
}
void STPush(ST* pst, STDataType x)
{
    assert(pst);
    if (pst->top == pst->capacity)
    {
        int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
        STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
        if (tmp == NULL)
        {
            perror("realloc fail");
        }
        pst->a = tmp;
        pst->capacity = newcapacity;
    }
    pst->a[pst->top] = x;
    pst->top++;
}
void STPop(ST* pst)
{
    assert(pst);
    assert(pst->top);
    pst->top--;
}
bool STEmpty(ST* pst)
{
    assert(pst);
    return pst->top == 0;
}
STDataType STTop(ST* pst)
{
    assert(pst);
    assert(pst->top > 0);
    return pst->a[pst->top - 1];
}

STDataType STSize(ST* pst)
{
    assert(pst);
    return pst->top;
}
bool isValid(char* s) {
    ST st;
    STInit(&st);
    while (*s)
    {
        if (*s == '(' || *s == '{' || *s == '[')
        {
            STPush(&st, *s);
        }
        else
        {
            if (STEmpty(&st))
            {
                STDestroy(&st);
                return false;
            }

            char top = STTop(&st);
            STPop(&st);
            //����������˳������
            //��������������ƥ��
            if ((*s == ')' && top != '(')
                || (*s == '}' && top != '{')
                || (*s == ']' && top != '['))
            {
                STDestroy(&st);
                return false;
            }
        }
        ++s;
    }
    bool ret = STEmpty(&st);
    //�������������Ҷ�
    STDestroy(&st);
    return ret;
}