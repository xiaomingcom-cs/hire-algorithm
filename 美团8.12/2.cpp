//���쳤��Ϊn�����У�����Ȩֵ������С Ȩֵ���㷽��������a��������������͹��������b��Ȼ��b�����ֵ��ȥ��Сֵ��a�����Ȩֵ
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
