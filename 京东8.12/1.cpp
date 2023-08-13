#include <bits/stdc++.h>
using namespace std;
int a[110];
int main() {
    int n,ans=0;
    cin>>n;
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        cin>>a[i];
        map[a[i]]=0;
    }
    for(int i=0;i<n;i++){
        map[a[i]]++;
    }
    for(int i=0;i<n;i++){
        if(a[i]==map[a[i]]) ans++;
    }
    cout<<ans;

}