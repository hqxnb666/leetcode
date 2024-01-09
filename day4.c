#define _CRT_SECURE_NO_WARNINGS
�����ַ��� s �� t ���ж� s �Ƿ�Ϊ t �������С�

�ַ�����һ����������ԭʼ�ַ���ɾ��һЩ��Ҳ���Բ�ɾ�����ַ������ı�ʣ���ַ����λ���γɵ����ַ����������磬"ace"��"abcde"��һ�������У���"aec"���ǣ���

���ף�

����д�������� S������ S1, S2, ..., Sk ���� k >= 10�ڣ�����Ҫ���μ�������Ƿ�Ϊ T �������С�����������£���������ı���룿

��л��bool isSubsequence(char* s, char* t) {
    int n = strlen(s);
    int m = strlen(t);
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (s[i] == t[j])
        {
            i++;
        }
        j++;
    }
    return i == n;
}


����һ������ x ����� x ��һ���������������� true �����򣬷��� false ��

��������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������

���磬121 �ǻ��ģ��� 123 ���ǡ�

bool isPalindrome(int x) {
    // �������ǻ��������Լ�������һλ��0����ôֻ��0������ǻ�����
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    // �����ֳ���Ϊ����ʱ�����ǿ���ͨ�� revertedNumber/10 ȥ���м�����֡�
    // ���磬�������� 12321���� while ѭ����ĩβ�����ǵõ� x = 12��revertedNumber = 123��
    // �����м�����ֲ�Ӱ����ģ����������Լ���ȣ����������ǿ��Լ򵥵ؽ���ȥ����
    return x == revertedNumber || x == revertedNumber / 10;
}


����һ���ַ��� s ������ת�ַ����е�����Ԫ����ĸ�������ؽ���ַ�����

Ԫ����ĸ���� 'a'��'e'��'i'��'o'��'u'���ҿ����Դ�Сд������ʽ���ֲ�ֹһ�Ρ�



ʾ�� 1��

���룺s = "hello"
�����"holle"
ʾ�� 2��

���룺s = "leetcode"
�����"leotcede"


#include <string.h>

void swap(char* p1, char* p2)
{
    char tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

char* reverseVowels(char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        // ��������Ԫ����ĸ
        while (left < right && !isVowel(s[left])) {
            left++;
        }

        // �����Ҳ��Ԫ����ĸ
        while (left < right && !isVowel(s[right])) {
            right--;
        }

        // ����Ԫ����ĸ
        if (left < right) {
            swap(&s[left], &s[right]);
            left++;
            right--;
        }
    }

    return s;
}



����һ���±�� 0 ��ʼ�� �� �������� nums ��

��� nums ��һ�����������㣺�Ƴ�����������ʣ��Ԫ�� �ϸ���� ����ô���ǳ����������Ϊ �Ƴ����� �����顣�ȷ�˵��[5, 3, 4, 6, 7] �е�[3, 4] ��һ���Ƴ����������飬��Ϊ�Ƴ����������[5, 3, 4, 6, 7] ��Ϊ[5, 6, 7] �����ϸ�����ġ�

���㷵�� nums �� �Ƴ����� �����������Ŀ��

ע�� ��ʣ��Ԫ��Ϊ�յ�����Ҳ��Ϊ�ǵ����ġ�

������ ָ����һ��������һ��������Ԫ�����С�



ʾ�� 1��

���룺nums = [1, 2, 3, 4]
�����10
���ͣ�10 ���Ƴ�����������ֱ�Ϊ��[1], [2], [3], [4], [1, 2], [2, 3], [3, 4], [1, 2, 3], [2, 3, 4] ��[1, 2, 3, 4]���Ƴ�����һ���������ʣ��Ԫ�ض��ǵ����ġ�ע�⣬�����鲻���Ƴ����������顣
ʾ�� 2��

���룺nums = [6, 5, 7, 8]
�����7
���ͣ�7 ���Ƴ�����������ֱ�Ϊ��[5], [6], [5, 7], [6, 5], [5, 7, 8], [6, 5, 7] ��[6, 5, 7, 8] ��
nums ��ֻ���� 7 ���Ƴ����������顣
ʾ�� 3��

���룺nums = [8, 7, 6, 6]
�����3
���ͣ�3 ���Ƴ�����������ֱ�Ϊ��[8, 7, 6], [7, 6, 6] ��[8, 7, 6, 6] ��ע��[8, 7] �����Ƴ�������������Ϊ�Ƴ�[8, 7] �� nums ��Ϊ[6, 6] ���������ϸ�����ġ�



int incremovableSubarrayCount(int nums[], int numsSize) {
    int count = 0;

    // �������п��ܵ�������
    for (int i = 1; i <= numsSize; i++) {
        for (int l = 0; l + i - 1 < numsSize; l++) {
            int r = l + i - 1;
            // ����Ƴ���ǰ�������ʣ�ಿ���Ƿ��ϸ����
            int* arr = (int*)malloc(sizeof(int) * 100);
            int f = 0;
            int arrSize = 0;

            // ��� arr ���飬������������ [l, r]
            for (int j = 0; j < l; j++) {
                arr[arrSize++] = nums[j];
            }
            for (int j = r + 1; j < numsSize; j++) {
                arr[arrSize++] = nums[j];
            }

            // ���ʣ�ಿ���Ƿ��ϸ����
            int isIncreasing = 1;
            for (int j = 0; j < arrSize - 1; j++) {
                if (arr[j] >= arr[j + 1]) {
                    f = 1;
                    break;
                }
            }
            if (f == 0)
                count++;
        }
    }
    return count;
}
