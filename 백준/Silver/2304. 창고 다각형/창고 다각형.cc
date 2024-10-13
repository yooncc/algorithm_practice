#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, result, maxHeight;
vector< pair<int, int> > v;
pair<int,int> maxStart = make_pair(0,-1), maxEnd;

int main()
{

    cin >> K;

    maxHeight = 0;
    for (int i = 0; i < K; i++) {
        int l, h;
        cin >> l >> h;
        if (h >= maxHeight) {
            maxHeight = h;
        }
        v.push_back(make_pair(l, h));
    }

    sort(v.begin(), v.end());

    for (auto it = v.begin(); it != v.end(); it++) {
        if ((*it).second == maxHeight) {
            if (maxStart.second == -1) {
                maxStart.first = (*it).first;
                maxStart.second = maxHeight;
            }
            maxEnd.first = (*it).first;
        }
    }


    int currentL = v[0].first, currentH = v[0].second, currentI;
    result = 0;

    if (currentL != maxStart.first) {
        for (int i = 1; i < v.size(); i++) {
            if (v[i].second > currentH) {
                result += (v[i].first - currentL) * currentH;
                currentL = v[i].first;
                currentH = v[i].second;
            }
            if (currentH == maxHeight) {
                break;
            }
        }
    }

    result += ((maxEnd.first + 1) - maxStart.first) * maxHeight;


    if (maxEnd.first != v[v.size() - 1].first) {
        currentL = v[v.size() - 1].first;
        currentH = v[v.size() - 1].second;
        for (int i = 1; i < v.size(); i++) {
            if (v[v.size() - 1 - i].second > currentH) {
                result += (currentL - v[v.size() - 1 - i].first) * currentH;
                currentL = v[v.size() - 1 - i].first;
                currentH = v[v.size() - 1 - i].second;
            }
            if (currentH == maxHeight) {
                break;
            }
        }
    }

    cout << result << endl;

    return 0;
}