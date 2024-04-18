最小花费爬楼梯
技能 线性dp
时间限制：1s 空间限制：256MB 限定语言：不限
题目描述：给定一个整数数组 ，其中 是从楼梯第 个台阶向上爬需要支付的费用，下标从0开始。一旦你支付此费用，即可选择向上爬一个或者两个台
阶。
你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
请你计算并返回达到楼梯顶部的最低花费。
数据范围：数组长度满足 ，数组中的值满足
输入描述：第一行输入一个正整数 n ，表示数组 cost 的长度。
第二行输入 n 个正整数，表示数组 cost 的值。
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;
int main() {
int n,j;
cin >> n ;
int* cost = (int*)malloc(sizeof(int) * (n+1));
int* dp = (int*)malloc(sizeof(int) * (n+1));
for(int i = 0; i<n; i++)
{
cin >> j;
cost[i] = j;
}
for(int i = 0; i<=n; i++){
if(i < 2) dp[i] = 0;
dp[i] = min((dp[i-2]+cost[i-2]),(dp[i-1]+cost[i-1]));
}
int result = dp[n];
cout << result << endl;
}
// 64 位输出请用 printf("%lld")



数组中两个字符串的最小距离
技能 哈希 双指针 字符串
时间限制：1s 空间限制：32MB
限定语言：C(clang11), C++(clang++11), Pascal(fpc 3.0.2), Java(javac 1.8), Python2(2.7.3), PHP(7.4.7), C#(mcs 5.4), ObjC(gcc 5.4), Python3(3.9), JavaScript Node(12.18.2), JavaScript
V8(6.0.0), Sqlite(3.7.9), R(4.0.3), Go(1.14.4), Ruby(2.7.1), Swift(5.3), matlab(Octave 5.2), pypy2(pypy2.7.13), pypy3(pypy3.6.1), Rust(1.44), Scala(2.11.12), Kotlin(1.4.10),
Groovy(3.0.6), TypeScript(4.1.2), Mysql(8.0)
题目描述：给定给定两个字符串str1和str2，再一个字符串数组strs，返回在strs中str1和str2的最小距离，如果str1或str2为null，或不在strs中，返回-1。
输入描述：输入包含有多行，第一输入一个整数n（ ），代表数组strs的长度，第二行有两个字符串分别代表str1和str2，接下来n行，每行一个字符
串，代表数组strs (保证题目中出现的所有字符串长度均小于等于10)。
输出描述：输出一行，包含一个整数，代表返回的值。
补充说明：时间复杂度 （ ），额外空间复杂度 （ ）
#include <iostream>
#include <string>
#include <cstdlib> // for abs()
#include <climits> // for INT_MAX
using namespace std;
int main() {
int n;
cin >> n;
string str1, str2;
cin >> str1 >> str2;
// 为了保证空间复杂度O(1)，不使用vector或数组存储输入的字符串
int minDistance = INT_MAX;
int index1 = -1, index2 = -1;
string temp;
for (int i = 0; i < n; i++) {
getline(cin, temp); // 读取一行作为字符串
if (temp == str1) {
index1 = i;
if (index2 != -1) { // 确保str2已被找到
minDistance = min(minDistance, abs(index1 - index2));
}
}
if (temp == str2) {
index2 = i;
if (index1 != -1) { // 确保str1已被找到
minDistance = min(minDistance, abs(index1 - index2));
}
}
}
if (index1 == -1 || index2 == -1) { // str1或str2没在数组中找到
cout << -1 << endl;
} else {
cout << minDistance << endl;
}
return 0
