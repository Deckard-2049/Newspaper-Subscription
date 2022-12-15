#include <bits/stdc++.h>
using namespace std;

typedef pair<string, string> pairs;

void display(const set<pairs>& s)
{
	bool found = false;
	for (auto const &x : s) {
		found = true;
		cout << "(" << x.first << ", "
			<< x.second << ")"
			<< " ";
	}

	if (not found) {
		cout << "No valid pair\n";
	}
}
int main()
{
	vector<pair<string, float>> v{{"toi", 26}, {"hindu", 20.5}, {"et", 34} ,{"bm", 10.5} ,{"ht",18}};
	set<pairs> s;
    int input = 40;
	
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i].second + v[j].second <=input ) {
				pairs x = make_pair(v[i].first, v[j].first);
				s.insert(x);
			}
		}
	}

	display(s);
	s.clear();
}