#define _CRT_SECURE_NO_WARNINGS
����һ���ַ��� s ���ҵ� ���ĵ�һ�����ظ����ַ����������������� ����������ڣ��򷵻� - 1 ��



ʾ�� 1��

���� : s = "leetcode"
��� : 0
ʾ�� 2 :

	���� : s = "loveleetcode"
	��� : 2
	ʾ�� 3 :

	���� : s = "aabb"
	��� : -1


	��ʾ :

	1 <= s.length <= 105
	s ֻ����Сд��ĸ
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

���������ַ�����ransomNote �� magazine ���ж� ransomNote �ܲ����� magazine ������ַ����ɡ�

������ԣ����� true �����򷵻� false ��

magazine �е�ÿ���ַ�ֻ���� ransomNote ��ʹ��һ�Ρ�



ʾ�� 1��

���룺ransomNote = "a", magazine = "b"
�����false
ʾ�� 2��

���룺ransomNote = "aa", magazine = "ab"
�����false
ʾ�� 3��

���룺ransomNote = "aa", magazine = "aab"
�����true


��ʾ��

1 <= ransomNote.length, magazine.length <= 105
ransomNote �� magazine ��СдӢ����ĸ���
bool canConstruct(char* ransomNote, char* magazine) {
    int frequency[256] = { 0 }; // ����һ��Ƶ��������ͳ���ַ�

    // ���� magazine ��ÿ���ַ���Ƶ��
    for (int i = 0; magazine[i] != '\0'; i++) {
        frequency[magazine[i]]++;
    }

    // ��� ransomNote �е�ÿ���ַ�
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        // ��� magazine ���ַ���Ƶ��С�� ransomNote �е�Ƶ�ʣ����� false
        if (--frequency[ransomNote[i]] < 0) {
            return false;
        }
    }

    // ��������ַ������ͨ�������� true
    return true;
}