#define _CRT_SECURE_NO_WARNINGS

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
实现一个十进制数字报数程序，请按照数字从小到大的顺序返回一个整数数列，该数列从数字 1 开始，到最大的正整数 cnt 位数字结束。



示例 1:

输入：cnt = 2
输出：[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99]
int* countNumbers(int cnt, int* returnSize) {
    int maxNumber = 1;
    for (int i = 0; i < cnt; i++) {
        maxNumber *= 10;
    }
    maxNumber -= 1; // 减去1以得到最大的cnt位数字

    *returnSize = maxNumber; // 设置返回数组的大小

    int* arr = malloc(maxNumber * sizeof(int)); // 分配内存
    if (arr == NULL) {
        *returnSize = 0; // 如果内存分配失败，则返回大小为0
        return NULL;
    }

    for (int i = 0; i < maxNumber; i++) {
        arr[i] = i + 1; // 填充数组
    }

    return arr;
}
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

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
    //top为-1代表指向栈顶元素  为0代表指向栈顶元素的下一个位置

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
            //这里解决的是顺序问题
            //但还包括数量不匹配
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
    //这解决的是左少右多
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
    //top为-1代表指向栈顶元素  为0代表指向栈顶元素的下一个位置

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
            //这里解决的是顺序问题
            //但还包括数量不匹配
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
    //这解决的是左少右多
    STDestroy(&st);
    return ret;
}