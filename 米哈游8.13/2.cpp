//输入n,m表示矩形大小，左下角坐标为1，1，接下来给出三个坐标，初始位于第一个坐标，然后需要先走到第二个坐标，然后再走到第三个坐标，判断至少走几步
//特性：左边界和右边界相邻，上边界和下边界相邻
//为什么才40%  感觉是对的啊

//草 考虑得片面了  你考虑的情况只是三个点都在边界的情况，而没有考虑一个在边界，另一个离边界很近的情况

//min x ： Math.min(Math.abs(x1-x0), Math.abs(x1-n-x0), Math.abs(x0-n-x1))；
// min y ： Math.min(Math.abs(y1-y0), Math.abs(y1-m-y0), Math.abs(y0-m-y1))；
// 两个 min x 和两个 min y 相加即可

#include <bits/stdc++.h>
using namespace std;
int a[3][3];
int main() {
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            cin>>a[i][j];
        }
    }
    int s1=abs(a[0][0]-a[1][0]);
    if(s1==n-1) s1=1;
    int s2=abs(a[0][1]-a[1][1]);
    if(s2==m-1) s2=1;
    int s3=abs(a[1][0]-a[2][0]);
    if(s3==n-1) s3=1;
    int s4=abs(a[1][1]-a[2][1]);
    if(s4==m-1) s4=1;
    ans=s1+s2+s3+s4;
    cout<<ans;
}
