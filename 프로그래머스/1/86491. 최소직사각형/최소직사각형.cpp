#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int width=0, height=0;
    
    for (int i=0;i<sizes.size();i++) {
        int mymax = max(sizes[i][0],sizes[i][1]);
        int mymin = min(sizes[i][0],sizes[i][1]);
        if (width < mymax) {
            width = mymax;
        }
        if (height < mymin) {
            height = mymin;
        }
    }
    answer = width*height;
    
    return answer;
}