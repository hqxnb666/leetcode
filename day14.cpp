class Solution {
public:
    string reverseStr(string s, int k) {
        int count = 0;
        if(k == 0)
        return s;
        int n =s.size();
       for(int i =0; i<s.size(); i += k * 2)
       {
        reverse(s.begin() + i,s.begin() + min(i + k,n));
       }
        return s;

    }
};
