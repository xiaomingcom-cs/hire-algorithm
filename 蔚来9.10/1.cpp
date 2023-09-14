#include <bits/stdc++.h>
#include <vector>
using namespace std;
bool isPrime(int num){
    if(num<=1) return false;
    for(int i=2;i*i<=num;i++){
        if(num%i ==0) return false;
    }
    return true;
}
int main() {
    vector<int> primes;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=2;i<=n;i++){
            if(isPrime(i)) primes.push_back(i);
        }
        vector<int> dp(n+1,0);
        for(int i=2;i<=n;i++){
            // dp[i]=i;
            for(int j=0;j<primes.size()&&primes[j]<=i;j++){
                dp[i]=max(dp[i],dp[i-primes[j]]+1);
            }
        }
        cout<<dp[n]<<endl;
        
    }
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")