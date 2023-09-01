//给定一个二维数组 'cropField'，其中每个元素代表农田中对应位置的作物产量。
//每个位置上的作物经过灌溉可使产量加1倍（即对应位置作物产量数*2），重复灌溉同一位置不能多次加倍。
//现在需要修建 2 条灌溉渠道，1条从上到下灌溉，1条从左到右灌溉。请确定哪行和哪列应该被灌溉，使得农田中作物的总产量最大化，并输出最大化的总产量。

//100%
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;
int sum=0;
class Solution {
public:

    /* Write Code Here */
    int calculateMaxTotalYie(vector < vector < int > > cropField) {
        int m=cropField.size(),n=cropField[0].size();
        int maxRow=0,idxRow=0,maxCol=0,idxCol=0;
        for(int i=0;i<m;i++){
          int tmp=0;
          for(int j=0;j<n;j++){
            tmp+=cropField[i][j];
          }
          if(tmp>maxRow){
            maxRow=tmp,idxRow=i;
          }
        }
        for(int i=0;i<n;i++){
            int tmp=0;
            for(int j=0;j<m;j++){
              tmp+=cropField[j][i];
            }
            if(tmp>maxCol){
              maxCol=tmp,idxCol=i;
            }
        }
        int ans = sum+maxCol+maxRow-cropField[idxRow][idxCol];
        return ans;
    }
};
int main() {
    int res;
  
    int cropField_rows = 0;
    int cropField_cols = 0;
    cin >> cropField_rows >> cropField_cols;
    vector< vector < int > > cropField(cropField_rows);
    for(int cropField_i=0; cropField_i<cropField_rows; cropField_i++) {
        for(int cropField_j=0; cropField_j<cropField_cols; cropField_j++) {
            int cropField_tmp;
            cin >> cropField_tmp;
            sum+=cropField_tmp;
            cropField[cropField_i].push_back(cropField_tmp);
        }
    }
    Solution *s = new Solution();
    res = s->calculateMaxTotalYie(cropField);
    cout << res << endl;
    
    return 0;

}
