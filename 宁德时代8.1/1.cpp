//��������n����Ҫ��k�࣬k<n,Ҫ��������󣬲���ȶ���Ϊ�����ֵ�صĵ�ѹ���Բ����Сֵ������n,k��n���صĵ�ѹ�����������ȡ�
//������   input 6 3
//          13 5 1 8 21 2
//        output 8
//���ַ���������ĵ�ص�ѹ��������Ȼ���趨һ����߽�leftΪ0��һ���ұ߽�rightΪ����ѹ����С��ѹ�Ĳ�ֵ��Ȼ��ͨ�����ֲ��ҵķ�ʽ��[left, right]�ķ�Χ���ҵ�һ�����Ĳ���ȡ�
//��ÿ�ζ��ֲ��ҵĹ����У������趨һ���м�ֵmid��Ȼ��ͳ���ڵ�ǰ�����mid�£��ܹ�����Ҫ��ĵ���������cnt��
//���Ǵӵ�һ����ؿ�ʼ�����������ĵ�ؽ��бȽϣ�������ߵĵ�ѹ����ڵ���mid������Ϊ�������ڲ�ͬ����𣬽�cnt��1��������ǰ�����Ϊ�µ���㡣
//������cnt���ڵ���k��˵����ǰ�����mid����Ҫ�����Ǹ��´�ansΪmid��������߽�left��Ϊmid+1���������Ҹ���Ĳ���ȡ�����˵����ǰ�����mid������Ҫ�����ǽ��ұ߽�right��Ϊmid-1���������Ҹ�С�Ĳ���ȡ�

//��������
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int left = 0, right = v[n-1] - v[0], ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 1, start = v[0];
        for (int i = 1; i < n; i++) {
            if (v[i] - start >= mid) {
                cnt++;
                start = v[i];
            }
        }
        if (cnt >= k) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}