#define _CRT_SECURE_NO_WARNINGS
你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

回文串 是正着读和反着读都一样的字符串。



示例 1：

输入：s = "aab"
输出： [["a", "a", "b"], ["aa", "b"]]
示例 2：

输入：s = "a"
输出： [["a"]]


	提示：

		1 <= s.length <= 16
		s 仅由小写英文字母组成/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

        bool ifstr(char* s, int i, int j)//判断是否为回文串
    {
        while (i <= j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }


    void dfs(char*** ans, char* s, int* returnSize, int** returnColumnSizes, int len, char** path, int path_i, int index)
    {
        if (index >= len)
        {
            ans[*returnSize] = (char**)malloc(sizeof(char*) * path_i);
            for (int i = 0; i < path_i; i++)
            {
                ans[*returnSize][i] = (char*)malloc(sizeof(char) * (len + 1));
                strcpy(ans[*returnSize][i], path[i]);

            }
            (*returnColumnSizes)[(*returnSize)++] = path_i;
            return;
        }
        for (int i = index; i < len; i++)
        {
            if (ifstr(s, index, i) == false)
                continue;
            strncpy(path[path_i], s + index, i - index + 1);
            path[path_i][i - index + 1] = '\0';
            dfs(ans, s, returnSize, returnColumnSizes, len, path, path_i + 1, i + 1);
        }
        return;
    }

    char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
        char*** ans = (char***)malloc(sizeof(char**) * 50000);
        (*returnColumnSizes) = (int*)malloc(sizeof(int) * 50000);
        int len = strlen(s);
        char** path = (char**)malloc(sizeof(char*) * len);
        for (int i = 0; i < len; i++)
        {
            path[i] = (char*)malloc(sizeof(char) * (len + 1));
        }
        *returnSize = 0;
        dfs(ans, s, returnSize, returnColumnSizes, len, path, 0, 0);
        return ans;
    }

