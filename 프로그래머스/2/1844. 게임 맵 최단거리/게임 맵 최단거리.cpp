#include<vector>
#include<queue>
using namespace std;

int dx[4] = {1,-1,0,0} , dy[4] = {0,0,1,-1};
int visited[101][101] = {0};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int maxX = maps.size();
    int maxY = maps[0].size();
    
    queue<pair<int,int>> myque;
    
    myque.push(make_pair(0,0));
    
    int curValue=0;
    
    while(!myque.empty()) {
        pair<int,int> front = myque.front();
        myque.pop();
        int x = front.first;
        int y = front.second;
    
        visited[x][y]++;
        
        if (x==maxX-1 && y==maxY-1) {
            return visited[x][y];
        }
        
        for (int i=0;i<4;i++) {
            int nextX = x+ dx[i];
            int nextY = y+ dy[i];
            
            if (nextX < 0 || nextY < 0 || nextX >= maxX || nextY >= maxY) {
                continue;
            }
            if (maps[nextX][nextY]==0 || visited[nextX][nextY] != 0) {
                continue;
            }
            visited[nextX][nextY] = visited[x][y];
            myque.push(make_pair(nextX,nextY));
            
        }
    }
    
    return -1;
    
    return answer;
}