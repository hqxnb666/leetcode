#define _CRT_SECURE_NO_WARNINGS
��һ���ַ��� s�����㽫 s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����� ���Ĵ� ������ s ���п��ܵķָ����

���Ĵ� �����Ŷ��ͷ��Ŷ���һ�����ַ�����



ʾ�� 1��

���룺s = "aab"
����� [["a", "a", "b"], ["aa", "b"]]
ʾ�� 2��

���룺s = "a"
����� [["a"]]


	��ʾ��

		1 <= s.length <= 16
		s ����СдӢ����ĸ���/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

        bool ifstr(char* s, int i, int j)//�ж��Ƿ�Ϊ���Ĵ�
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

