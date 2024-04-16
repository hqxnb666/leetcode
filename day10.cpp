https://leetcode.cn/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/
#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string str) {
        int i = 0, sign = 1, result = 0;
        while (str[i] == ' ') { i++; }  // 跳过空白字符

        if (str[i] == '-' || str[i] == '+') {  // 检查符号
            sign = (str[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < str.size() && isdigit(str[i])) {
            int digit = str[i] - '0';
            // 检查溢出
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            result = 10 * result + digit;
            i++;
        }

        return sign * result;
    }
};

https://leetcode.cn/problems/add-strings/
class Solution {
public:
    string addStrings(string num1, string num2) {
        int next = 0;
        int end1 = num1.size()-1;
        int end2 = num2.size()-1;
        string s3;
        s3.reserve(num1.size() > num2.size() ? num1.size() : num2.size()+1);
        while(end1 >=0 || end2 >=0 || next >0)
        {
            int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
            int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;

            int ret = val1+val2 + next;
            next = ret / 10;
            ret %= 10;

            s3 += ('0' + ret);
            
        }
        reverse(s3.begin(), s3.end());
        return s3;
    }
    
};
