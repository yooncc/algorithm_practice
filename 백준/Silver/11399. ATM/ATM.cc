#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n,x=0,minSum=0;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		v.push_back(m);
	}

	sort(v.begin(), v.end());
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end();it++) {
		//cout << *it << endl;
		x += *it;
		minSum += x;
	}
	cout << minSum;

	return 0;
}