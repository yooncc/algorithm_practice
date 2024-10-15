#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i=0;i<commands.size();i++) {
        vector<int> myvec;
        for (int j=0;j<=commands[i][1]-commands[i][0];j++) {
            myvec.push_back(array[commands[i][0]+j-1]);
        }
        sort(myvec.begin(),myvec.end());
        answer.push_back(myvec[commands[i][2]-1]);
    }
    
    return answer;
}