// ���룺4 4
// XX..
// XXX.
// .X.X
// ..X.
// ��� 3 (X���ɵ�����������)

//����n,m��Ȼ�����������n�У�ÿ����һ���ַ���������m���ַ����ַ�ֻ��X��. ,����X��Ϊ�ĸ��ǹ��ɵĵ������εĸ���(�����ο�����б�ģ�ֻҪ�ĸ�����X����)
#include<bits/stdc++.h>
#define x first
#define y second
#define mem(a,b) memset(a,b,sizeof(a))
#define F(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;

const int N=52;

int n,m,a[N][N];
vector<pii> v;

bool check(pii x)
{
    for(auto p:v)
        if(p==x)
            return true;
    return false;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='X')
                v.push_back({i,j});
        }
    int ans=0;
    for(int i=0;i<v.size();i++)
        for(int j=i+1;j<v.size();j++)
    {
        pii a=v[i],b=v[j];
        pii c={b.x+b.y-a.y,b.y-(b.x-a.x)},d={a.x+b.y-a.y,a.y-(b.x-a.x)};
        if(check(c)&&check(d))
            ans++;
        c={b.x-(b.y-a.y),b.y+b.x-a.x},d={a.x-(b.y-a.y),a.y+b.x-a.x};
        if(check(c)&&check(d))
            ans++;
    }
    cout<<ans/4<<endl;
    return 0;
}
