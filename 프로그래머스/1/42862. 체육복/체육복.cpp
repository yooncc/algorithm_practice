#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int myarr[32] = {0};

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n;
    
    sort(lost.begin(),lost.end());
    
    for (int i=0;i<reserve.size();i++) {
        myarr[reserve[i]] = 1;
    }
    
    for (int i=0;i<lost.size();i++) {
       if (myarr[lost[i]] == 1) {
           myarr[lost[i]] = 2;
       }
    }
    
    for (int i=0;i<lost.size();i++) {
       if (myarr[lost[i]] == 0) {
            if (myarr[lost[i]-1] == 1) {
                myarr[lost[i]-1] = 0;
            }
            else if (myarr[lost[i]+1] == 1) {
                myarr[lost[i]+1] = 0;
            }
            else {
                answer--;
            }
       }
    }
    
    return answer;
}