#include <vector>
using namespace std;

int myarr[200001] = {0};

int solution(vector<int> nums)
{
    int answer = 0;
    
    for (int i=0;i<nums.size();i++) {
        if (myarr[nums[i]] == 0) {
            myarr[nums[i]] = 1;
            answer++;
        }
    }
    
    if (answer > nums.size()/2)
        answer = nums.size()/2;
    
    return answer;
}