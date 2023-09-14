#include <bits/stdc++.h>
using namespace std;
// string lis[100010];
vector<string> lis;
string s;
int n,m;
bool pan(int i,int j){
    for(int k=0;k<m;k++){
        if(s.substr(i,j-i+1)==lis[k]) return true;
    }
    return false;
}
int main() {
    int ans=0;
    cin>>n>>m;
    
    cin>>s;
    for(int i=0;i<m;i++){
        string tmp;
        cin>>tmp;
        lis.push_back(tmp);
    }
    for(string word: lis){
        size_t pos = s.find(word);
        while(pos != string::npos){
            ans++;
            pos=s.find(word,pos+1);
        }
    }
    cout<<ans;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")