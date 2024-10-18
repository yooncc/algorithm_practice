#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int cur_max=0;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> myque;
    for (int i=0;i<progresses.size();i++) {
        if (((100-progresses[i])%speeds[i]) == 0) {
            myque.push((100-progresses[i])/speeds[i]);
        }
        else {
            myque.push((100-progresses[i])/speeds[i]+1);
        }
    }
    int i=-1;
    while(!myque.empty()) {
        int myfront = myque.front();
        if (cur_max < myfront) {
            cur_max = myfront;
            i++;
            answer.push_back(1);
        }
        else {
            answer[i]++;
        }
        myque.pop();
    }
    
    
    return answer;
}