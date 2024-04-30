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
