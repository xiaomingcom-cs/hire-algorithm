//小红在刷小红书的时候看到了一颗挂着小红薯的小红树，所以小红也想种一颗小红树挂一些小红薯发小红书。

//小红有一颗树，每个结点有一个权值，初始时每个节点都是白色。小红每次操作可以选择两个相邻的结点，如果它们都是白色且权值的和是质数，小红就可以选择其中一个节点染红。

//小红想知道最多可以染红多少个节点？

//第一行输入一个正整数n，代表节点的数量。

//第二行输入n个正整数ai，代表每个节点的权值。

//接下来的n-1行，每行输入两个正整数u,v，代表节点u和节点v有一条边连接
function isPrime(num) {
    if (num <= 1) {
        return false;
    }
    for (let i = 2; i <= Math.sqrt(num); i++) {
        if (num % i === 0) {
            return false;
        }
    }
    return true;
}

function dfs(node, graph, visited, colors) {
    visited[node] = true;
    let count = 0;
    for (let i = 0; i < graph[node].length; i++) {
        const next = graph[node][i];
        if (!visited[next] && isPrime(colors[node] + colors[next])) {
            colors[next] = 1;
            count++;
        }
    }
    for (let i = 0; i < graph[node].length; i++) {
        const next = graph[node][i];
        if (!visited[next]) {
            count += dfs(next, graph, visited, colors);
        }
    }
    return count;
}

function getMaxRedNodes(n, a, edges) {
    const graph = Array.from({ length: n + 1 }, () => []);
    for (let i = 0; i < edges.length; i++) {
        const [u, v] = edges[i];
        graph[u].push(v);
        graph[v].push(u);
    }
    const visited = Array(n + 1).fill(false);
    const colors = Array(n + 1).fill(0);
    let count = 0;
    for (let i = 1; i <= n; i++) {
        if (!visited[i]) {
            colors[i] = 1;
            count += dfs(i, graph, visited, colors);
        }
    }
    return count;
}