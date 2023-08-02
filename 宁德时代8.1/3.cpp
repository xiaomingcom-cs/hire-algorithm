//������n��﮵�أ����Ϊ0-(n-1),n-1���߹���һ����������n�ͽ�����n-1������i,j��ʾi,j֮����һ���ߣ��������Ϊn������answer,����answer[i]Ϊ���Ϊi��﮵�ص���������﮵�صıߺͣ�����ÿ���߳���Ϊ1
//������6 0 1 0 2 2 3 2 4 2 5        output:8 12 6 10 10 10

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[100000];
int distances[100000];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    distances[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < graph[current].size(); i++) {
            int neighbor = graph[current][i];
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[current] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        distances[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        bfs(i);

        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += distances[j];
            distances[j] = -1;
        }
        cout << sum << " ";
    }

    return 0;
}