#include <string>
#include <vector>

using namespace std;

int myarr[3] = {0}; 

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int a=0,b[5]={3,1,2,4,5},c=0;
    for (int i=0;i<answers.size();i++) {
        if (answers[i] ==(i%5)+1) {
            myarr[0]++;
        } 
        
        if (i%2 == 0) {
            if (answers[i] == 2) {
                myarr[1]++;
            }
        }
        else {
            a++;
            if (a==2) {
                a++;
            }
            else if (a==6) {
                a=1;
            }
            if (answers[i] == a) {
                myarr[1]++;
            } 
        }
        
        
        if (answers[i] == b[c]) {
            myarr[2]++;
        }
        if ((i+1)%2 == 0) {
            c++;
            if (c==5) {
                c=0;
            }
        }
    }
    
    int max_value =0;
    for(int i=0;i<3;i++) {
        if (max_value < myarr[i]) {
            max_value = myarr[i];
        }
    }
     for(int i=0;i<3;i++) {
        if (myarr[i] == max_value) {
            answer.push_back(i+1);
        }
    }
    
    
    return answer;
}