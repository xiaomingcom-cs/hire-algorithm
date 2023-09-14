#include <iostream>
using namespace std;
string s[100010];
int main() {
    int n,tmp=0,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            char c;
            cin>>c;
            if(c=='0'){
                tmp++;
            }
        }
        if(tmp>=4){
            tmp=0;
            ans++;
        }
    }
    cout<<ans;
}
