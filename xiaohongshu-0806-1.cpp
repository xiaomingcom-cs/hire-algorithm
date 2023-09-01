//输入14行字符串，每两行代表一天的开始时间和结束时间。
//保证开始时间一定迟于17:00，结束时间一定早于03:00（即小红在下午5点之后才会开始刷小红书，且一定会在凌晨3点前睡觉）。
//输出一个整数，代表小红总共刷小红书的时间。

#include<bits/stdc++.h>
using namespace std;
int main(){
  string s[20];
  int ans=0;
  for(int i=0;i<14;i++){
    //   cout<<i<<endl;
    cin>>s[i];
  }
  for(int j=0;j<14;j++){
    //   cout<<i<<endl;
    // int jj =i;
    if(j%2!=0) continue;
    // cout<<j<<endl;
    string s1=s[j],s2=s[j+1];
    int hour1=(s1[0]-'0')*10+(s1[1]-'0');
    int min1=(s1[3]-'0')*10+(s1[4]-'0');
    int hour2=(s2[0]-'0')*10+(s2[1]-'0');
    int min2=(s2[3]-'0')*10+(s2[4]-'0');
    // cout<<hour1<<" "<<min1<<endl;
    if(hour1>3&&hour2>3){
      ans+=hour2*60+min2-(hour1*60+min1);
    }
    if(hour1>3&&hour2<=3){
      ans+=(hour2+24)*60+min2-(hour1*60+min1);
    }
    if(hour1<=3&&hour2<=3){
      ans+=(hour2)*60+min2-(hour1*60+min1);
    }
    
  }
  cout<< ans;
}