#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool mycmp(int a, int b) {
    string a1 = to_string(a);
    string b1 = to_string(b);
    
    int i=0;
    char a2,b2;
    while(min(a1.size(),b1.size()) != i) {
        if (a1.size()>i) {
            a2 = a1[i];
        }
        if (b1.size()>i) {
            b2 = b1[i];
        }
        if (a2 == b2) {
            i++;
            continue;
        }
        else {
            return a2 > b2;
        }
    }  
    return stoi(a1+b1) > stoi(b1+a1);
    
    // return to_string(a)[0] > to_string(b)[0];
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(),numbers.end(),mycmp);
    
    for (int i=0;i<numbers.size();i++) {
        answer += to_string(numbers[i]);
    }
    
    if (answer[0] == '0') {
        answer = "0";
    }
    // if (stoi(answer) == 0) {
    //     answer = "0";
    // }
    
    return answer;
}