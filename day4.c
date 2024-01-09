#define _CRT_SECURE_NO_WARNINGS
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

进阶：

如果有大量输入的 S，称作 S1, S2, ..., Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

致谢：bool isSubsequence(char* s, char* t) {
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


给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

例如，121 是回文，而 123 不是。

bool isPalindrome(int x) {
    // 负数不是回文数，以及如果最后一位是0，那么只有0本身才是回文数
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除中间的数字。
    // 例如，对于数字 12321，在 while 循环的末尾，我们得到 x = 12，revertedNumber = 123，
    // 由于中间的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
    return x == revertedNumber || x == revertedNumber / 10;
}


给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。

元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。



示例 1：

输入：s = "hello"
输出："holle"
示例 2：

输入：s = "leetcode"
输出："leotcede"


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
        // 查找左侧的元音字母
        while (left < right && !isVowel(s[left])) {
            left++;
        }

        // 查找右侧的元音字母
        while (left < right && !isVowel(s[right])) {
            right--;
        }

        // 交换元音字母
        if (left < right) {
            swap(&s[left], &s[right]);
            left++;
            right--;
        }
    }

    return s;
}



给你一个下标从 0 开始的 正 整数数组 nums 。

如果 nums 的一个子数组满足：移除这个子数组后剩余元素 严格递增 ，那么我们称这个子数组为 移除递增 子数组。比方说，[5, 3, 4, 6, 7] 中的[3, 4] 是一个移除递增子数组，因为移除该子数组后，[5, 3, 4, 6, 7] 变为[5, 6, 7] ，是严格递增的。

请你返回 nums 中 移除递增 子数组的总数目。

注意 ，剩余元素为空的数组也视为是递增的。

子数组 指的是一个数组中一段连续的元素序列。



示例 1：

输入：nums = [1, 2, 3, 4]
输出：10
解释：10 个移除递增子数组分别为：[1], [2], [3], [4], [1, 2], [2, 3], [3, 4], [1, 2, 3], [2, 3, 4] 和[1, 2, 3, 4]。移除任意一个子数组后，剩余元素都是递增的。注意，空数组不是移除递增子数组。
示例 2：

输入：nums = [6, 5, 7, 8]
输出：7
解释：7 个移除递增子数组分别为：[5], [6], [5, 7], [6, 5], [5, 7, 8], [6, 5, 7] 和[6, 5, 7, 8] 。
nums 中只有这 7 个移除递增子数组。
示例 3：

输入：nums = [8, 7, 6, 6]
输出：3
解释：3 个移除递增子数组分别为：[8, 7, 6], [7, 6, 6] 和[8, 7, 6, 6] 。注意[8, 7] 不是移除递增子数组因为移除[8, 7] 后 nums 变为[6, 6] ，它不是严格递增的。



int incremovableSubarrayCount(int nums[], int numsSize) {
    int count = 0;

    // 遍历所有可能的子数组
    for (int i = 1; i <= numsSize; i++) {
        for (int l = 0; l + i - 1 < numsSize; l++) {
            int r = l + i - 1;
            // 检查移除当前子数组后，剩余部分是否严格递增
            int* arr = (int*)malloc(sizeof(int) * 100);
            int f = 0;
            int arrSize = 0;

            // 填充 arr 数组，不包括子数组 [l, r]
            for (int j = 0; j < l; j++) {
                arr[arrSize++] = nums[j];
            }
            for (int j = r + 1; j < numsSize; j++) {
                arr[arrSize++] = nums[j];
            }

            // 检查剩余部分是否严格递增
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
