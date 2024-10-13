#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0,b=0,c=0;
    
    for (int i =0;i<number.size()-2;i++) {
        b = i+1;
        for (int j=b;j<number.size()-1;j++) {
            c = j+1;
            for (int l=c;l<number.size();l++) {
                if (number[i]+number[j]+number[l]==0) {
                    answer++;
                }
            }
        }
    }
    
    return answer;
}