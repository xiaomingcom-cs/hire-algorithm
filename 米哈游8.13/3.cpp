//没有卡时间 其实可以区间查询优化一下
//输入书的总页数和看书天数，然后输入每天从第几页看到第几页，输出每天看的部分是之前没有看过的
#include <iostream>
using namespace std;
int l[100010],r[100010],ans[100010],tmp[100010];
int main() {
    int n,q;
    cin>>n>>q;
    for(int i=0;i<q;i++){
        cin>>l[i]>>r[i];

        for(int j=l[i];j<=r[i];j++){
            if(tmp[j]==0){
                ans[i]++;
                tmp[j]=1;
            }
        }

    }
    for(int i=0;i<q;i++) cout<<ans[i]<<endl;
    // ans[]

}
