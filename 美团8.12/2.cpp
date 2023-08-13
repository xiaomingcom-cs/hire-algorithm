//构造长度为n的排列，满足权值尽可能小 权值计算方法：首先a数组相邻两项求和构造出数组b，然后b中最大值减去最小值即a数组的权值
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int cnt=0,mm=1;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            cout<<n-cnt<<" ";
            cnt++;
        }else{
            cout<<mm<<" ";
            mm++;
        }
    }
    
}
