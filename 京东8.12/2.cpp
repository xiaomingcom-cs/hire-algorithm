// 4
// 1 2 3 4

// 1 0 0 0 3 3 0 0 0 1
//对于输入的数组，只有两种操作， 末尾两个元素相加/相乘取个位数得到，
//样例正确但是超时了 6.25%  好像是忘记Mod100000007了吧
#include <iostream>
using namespace std;
int sz[200010];
int ans[11];
void dfs(int d, int* a) {
    // cout<<d<<endl;
    if (d == 0) {
        ans[a[0]] ++;
        return;
    }
    int tmp = a[d - 1];
    a[d - 1] = (a[d] + tmp) % 10;
    int b[d + 1];
    for (int ii = 0; ii < d; ii++) b[ii] = a[ii];
    dfs(d - 1, b);
    int c[d + 1];
    
    a[d - 1] = (a[d] * tmp) % 10;
    for (int ii = 0; ii < d; ii++) c[ii] = a[ii];
    dfs(d - 1, c);

}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> sz[i];
    dfs(n - 1, sz);
    for (int i = 0; i < 10; i++) {
        cout << ans[i] << " ";
    }
}

const int N=2e5+1000,mod=1e9+7;

ll cnt[N][10];

int main()
{
    int n;
    ll a[N];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==1)
    {
        for(int i=0;i<=9;i++)
        {
            if(i==a[1])
                cout<<1<<" ";
            else
                cout<<0<<" ";
        }
        return 0;

    }
    cnt[1][(a[n-1]+a[n])%10]++;
    cnt[1][(a[n-1]*a[n])%10]++;
    for(int i=2;i<=n-1;i++)
    {
        for(int j=0;j<=9;j++)
        {
            cnt[i][(j*a[n-i])%10]=(cnt[i][(j*a[n-i])%10]+cnt[i-1][j])%mod;
            cnt[i][(j+a[n-i])%10]=(cnt[i][(j+a[n-i])%10]+cnt[i-1][j])%mod;
        }
    }
    for(int i=0;i<=9;i++)
        cout<<cnt[n-1][i]<<" ";
    return 0;
}
