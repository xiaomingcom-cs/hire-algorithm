//好矩阵：仅有A,B,C三种字符，且都出现过，且矩阵相邻的字符都不相等   输入n,m,然后n行，每行是长度为m的字符串，有多少个3*3的矩阵是好矩阵
#include <iostream>
using namespace std;
string s[1010];
bool pan(int i,int j){
    int a=0,b=0,c=0;
    for(int ii=i;ii<i+3;ii++){
        for(int jj=j;jj<j+3;jj++){
            if(s[ii][jj]=='A') a++;
            else if(s[ii][jj]=='B') b++;
            else if(s[ii][jj]=='C') c++;
            else return false;
        }
    }
    // cout<<a<<" "<<b<<" "<<c<<" "<<endl;
    if(a==0 || b==0 || c==0) return false;
    if(s[i+1][j+1]==s[i+1][j] || s[i+1][j+1]==s[i][j+1] || s[i+1][j+1]==s[i+1][j+2] || s[i+1][j+1]==s[i+2][j+1]) return false;
    if(s[i][j]==s[i][j+1] || s[i][j]==s[i+1][j]) return false;
    if(s[i+2][j]==s[i+1][j] || s[i+2][j]==s[i+2][j+1]) return false;
    if(s[i][j+2]==s[i][j+1] || s[i][j+2]==s[i+1][j+2]) return false;
    if(s[i+2][j+2]==s[i+2][j+1] || s[i+2][j+2]==s[i+1][j+2]) return false;
    return true;
}
int main() {
    int m,n,ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>s[i];
    if(n<3 || m<3) cout<<0;
    else{
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                if(pan(i,j)) ans++;
            }
        }
        cout<<ans;
    }
}

