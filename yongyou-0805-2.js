//给定nums数组，初始时在第一个元素位置，每个元素代表该位置可跳的最大长度，假设总是可以跳到最后一个位置，求最少跳跃次数，要求跳到最后一个元素的位置

//贪心
function jump(nums) {
    const n = nums.length;
    let maxPos = 0, end = 0, steps = 0;
    for (let i = 0; i < n - 1; i++) {
      maxPos = Math.max(maxPos, i + nums[i]);
      if (i === end) {
        end = maxPos;
        steps++;
      }
    }
    return steps;
  }