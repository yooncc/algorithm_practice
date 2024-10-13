#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int sum[501] = {0,};
int maxSum=0;
queue< pair<int,int> > q;

int solution(vector<vector<int>> land);
void bfs(int x,int y,vector<vector<int>> &land);


int solution(vector<vector<int>> land) {
    int answer = 0;
    
    for (int i=0;i<land.size();i++) {
        for (int j=0;j<land[i].size();j++) {
            if (land[i][j] == 1) {
                bfs(i,j,land);
            }
        }
    }

    answer = maxSum;
    
    
    return answer;
}

void bfs(int x,int y,vector< vector<int> > &land) {
     int oilCount =0;
     int minY;
     int maxY;
    
     q.push(make_pair(x,y));

     land[x][y] = 2;
     oilCount++;
     minY=y,maxY=y;

     while(!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int k=0;k<4;k++) {
            int nx = i+dy[k]; 
            int ny = j+dx[k];
            if (nx < 0 || ny < 0 || nx >= land.size() || ny >= land[0].size() ) {
                continue;
            }
            if (land[nx][ny] == 0 || land[nx][ny] == 2) {
                continue;
            }

            if (ny > maxY) {
                maxY = ny;
            }
            if (ny < minY) {
                minY = ny;
            }

            land[nx][ny] = 2;
            q.push(make_pair(nx,ny));
            oilCount++;
        }
     }

     for (int i=minY;i<=maxY;i++) {
        sum[i] += oilCount;
        if (sum[i] > maxSum) {
            maxSum = sum[i];
        }
     }

}