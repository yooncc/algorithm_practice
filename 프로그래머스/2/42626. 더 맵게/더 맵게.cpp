#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define new_scov(a,b) (a+(b*2))

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(),scoville.end());
    
    int flag = 0;
    while(pq.size()!=1) {
        int top = pq.top();
        if (top >= K) {
            flag = 1;
            break;
        }
            
        pq.pop();
        int newScov = new_scov(top,pq.top());
        pq.pop();
        pq.push(newScov);
        answer++;
    }
    
    if (flag==0) {
        if (pq.top() < K) {
            return -1;
        }
    }
    
    return answer;
}