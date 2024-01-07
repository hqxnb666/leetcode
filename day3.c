#define _CRT_SECURE_NO_WARNINGS
给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 - 1 。



示例 1：

输入 : s = "leetcode"
输出 : 0
示例 2 :

	输入 : s = "loveleetcode"
	输出 : 2
	示例 3 :

	输入 : s = "aabb"
	输出 : -1


	提示 :

	1 <= s.length <= 105
	s 只包含小写字母
    int firstUniqChar(char* s) {
    int frequency[256] = { 0 };
    for (int i = 0; s[i] != '\0'; i++)
    {
        frequency[s[i]]++;
    }
    for (int i = 0; s[i] != 0; i++)
    {
        if (frequency[s[i]] == 1)
            return i;
    }
    return -1;
}

给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。



示例 1：

输入：ransomNote = "a", magazine = "b"
输出：false
示例 2：

输入：ransomNote = "aa", magazine = "ab"
输出：false
示例 3：

输入：ransomNote = "aa", magazine = "aab"
输出：true


提示：

1 <= ransomNote.length, magazine.length <= 105
ransomNote 和 magazine 由小写英文字母组成
bool canConstruct(char* ransomNote, char* magazine) {
    int frequency[256] = { 0 }; // 创建一个频率数组来统计字符

    // 计算 magazine 中每个字符的频率
    for (int i = 0; magazine[i] != '\0'; i++) {
        frequency[magazine[i]]++;
    }

    // 检查 ransomNote 中的每个字符
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        // 如果 magazine 中字符的频率小于 ransomNote 中的频率，返回 false
        if (--frequency[ransomNote[i]] < 0) {
            return false;
        }
    }

    // 如果所有字符都检查通过，返回 true
    return true;
}