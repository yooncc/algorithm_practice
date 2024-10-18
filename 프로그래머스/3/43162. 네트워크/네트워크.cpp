#include <string>
#include <vector>

using namespace std;

int visited[201] = {0};

void dfs(int n, int start,vector<vector<int>> computers) {
    
    for (int i=0;i<n;i++) {
        if (visited[i]==1) {
            continue;
        }
        if (i==start) {
            continue;
        }
        if (computers[start][i] == 0) {
            continue;
        }
        visited[i] = 1;
        dfs(n,i,computers);
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i=0;i<n;i++) {
        if (visited[i] == 1) {
            continue;
        } 
        answer++;
        visited[i] = 1;
        dfs(n,i,computers);
    }
    
    return answer;
}