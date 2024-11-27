#include <iostream>
#include <queue>
#include <cstring> // memset을 위해 추가
#define max_value 100001 // max_value 수정

using namespace std;

int N, M;
int visited[max_value];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    memset(visited, 0, sizeof(visited)); // visited 배열 초기화

    queue<pair<int, int>> que;
    que.push(make_pair(N, 0));
    visited[N] = 1; // 시작 위치 방문 표시

    while (!que.empty()) {
        pair<int, int> top = que.front();
        que.pop();

        if (top.first == M) {
            cout << top.second;
            break;
        }

        // 범위 검사 (top.first > max_value 조건 제거)
        if (top.first < 0 || top.first >= max_value) { 
            continue;
        }

        // 다음 위치들을 큐에 넣기 전에 visited 확인
        if (top.first + 1 < max_value && !visited[top.first + 1]) {
            que.push(make_pair(top.first + 1, top.second + 1));
            visited[top.first + 1] = 1;
        }
        if (top.first - 1 >= 0 && !visited[top.first - 1]) {
            que.push(make_pair(top.first - 1, top.second + 1));
            visited[top.first - 1] = 1;
        }
        if (top.first * 2 < max_value && !visited[top.first * 2]) {
            que.push(make_pair(top.first * 2, top.second + 1));
            visited[top.first * 2] = 1;
        }
    }

    return 0;
}