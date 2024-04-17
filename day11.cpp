#include <iostream>
#include<string>
using namespace std;

int main() {
    string  str;
    string ans;
    getline(cin,str);
    if(str[0]>'Z')ans+=(str[0]-32);
    else ans+=str[0];
    for(int i=1;i<str.size();i++){
        if(str[i]!=' '&amp;&amp;str[i-1]==' '){
            if(str[i]>'Z')ans+=(str[i]-32);
            else ans+=str[i];
        }
    }
   cout<<ans;

    return 0;
}


#include <iostream>
using namespace std;
typedef long long ll;
const int N=1e7+10;
int a[N];
int main() {
    int n;
    int x;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
       cin>>a[i];
    }
    int ans=1e9;
    int star=1;
    ll sum=0;
    for(int i=1,j=1;i<=n;i++){
       sum+=a[i];
        while(sum>=x){
            if(i-j+1<ans){
                ans=i-j+1;
                star=j;
            }
            sum-=a[j];
            j++;
        }
    }
    cout<<star<<" "<<star+ans-1;
    return 0;
}

#include <iostream>
#include<queue>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    long long sum=0;//存总和
    priority_queue<int> q;
    while(n--){
        int x;
        cin>>x;
        sum+=x;
        if(x%2==0)q.push(x);//不是偶数直接滚
    }

    while(!q.empty()&amp;&amp;k){
       int it=q.top();
       q.pop();
       it/=2;
       sum-=it;
       k--;
       if(it%2==0)q.push(it);//不是偶数也没有再进去的必要了
    }
    cout<<sum;
    return 0;
}
