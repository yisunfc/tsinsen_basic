#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Team
{
	string name;
	int score;
	int abs;
	int goal;

	bool operator < (const Team& r) const
	{
		if (score != r.score) return score > r.score;
		if (abs != r.abs) return abs > r.abs;
		if (goal != r.goal) return goal > r.goal;
		return name < r.name; 
	}
};

int main()
{
	vector<Team> teams;
	int n;
	cin >> n;
	while (n--)
	{
		Team rank;
		cin >> rank.name >> rank.score >> rank.abs >> rank.goal;
		teams.push_back(rank);
	}
	sort(teams.begin(), teams.end());

	for (auto const &team : teams)
		cout << team.name << endl;
	return 0;
}
