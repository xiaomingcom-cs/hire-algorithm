//小红很喜欢前往小红书分享她的日常生活。已知她生活中有n个事件，分享第i个事件需要她花费ti的时间和hi的精力来编辑文章，并能获得ai的快乐值。

//小红想知道，在总花费时间不超过T且总花费精力不超过H的前提下，小红最多可以获得多少快乐值？
//第一行输入一个正整数n，代表事件的数量。

//第二行输入两个正整数T和H，代表时间限制和精力限制。

//接下来的n行，每行输入三个正整数ti,hi,ai，代表分享第i个事件需要花费ti的时间、hi的精力，收获ai的快乐值。

//最简单的背包问题
function getMaxHappiness(n, T, H, t, h, a) {
  const dp = Array.from({ length: H + 1 }, () => Array(T + 1).fill(0));

  for (let i = 1; i <= n; i++) {
    for (let j = H; j >= h[i]; j--) {
      for (let k = T; k >= t[i]; k--) {
        dp[j][k] = Math.max(dp[j][k], dp[j - h[i]][k - t[i]] + a[i]);
      }
    }
  }

  return dp[H][T];
}