//描述：有n类电池要买k类，k<n,要求差异度最大，差异度定义为任两种电池的电压绝对差的最小值，输入n,k和n类电池的电压，输出最大差异度。
//样例：   input 6 3
//          13 5 1 8 21 2
//        output 8
//二分法：将输入的电池电压进行排序，然后设定一个左边界left为0，一个右边界right为最大电压与最小电压的差值。然后，通过二分查找的方式在[left, right]的范围内找到一个最大的差异度。
//在每次二分查找的过程中，我们设定一个中间值mid，然后统计在当前差异度mid下，能够满足要求的电池类别数量cnt。
//我们从第一个电池开始，依次与后面的电池进行比较，如果两者的电压差大于等于mid，则认为它们属于不同的类别，将cnt加1，并将当前电池作为新的起点。
//最后，如果cnt大于等于k，说明当前差异度mid满足要求，我们更新答案ans为mid，并将左边界left设为mid+1，继续查找更大的差异度。否则，说明当前差异度mid不满足要求，我们将右边界right设为mid-1，继续查找更小的差异度。

//暴力方法
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