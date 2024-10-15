#include <string>
#include <vector>
#define myplus(a,b) a+b
#define mysub(a,b) a-b

using namespace std;

int myTarget = 0;
int myAnswer = 0;

void myfunc(int num,vector<int> numbers,int order) {
    if (order==numbers.size()) {
        if (num == myTarget) {
            myAnswer++;
        }
        return;
    }
    myfunc(myplus(num,numbers[order]),numbers,order+1);
    myfunc(mysub(num,numbers[order]),numbers,order+1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    myTarget = target;
    
    myfunc(0,numbers,0);
    
    answer = myAnswer;
    
    return answer;
}