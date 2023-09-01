// 获取最大积分  同2，且跳到该位置即可获得当前元素积分 若跳到数组最后，秋最多积分 
function jumpWithScore(nums) {
    const n = nums.length;
    let maxPos = 0, end = 0, steps = 0, score = 0;
    for (let i = 0; i < n - 1; i++) {
      maxPos = Math.max(maxPos, i + nums[i]);
      score += nums[i];
      if (i === end) {
        end = maxPos;
        steps++;
        if (maxPos >= n - 1) {
          return score;
        }
      }
    }
    return -1;
  }