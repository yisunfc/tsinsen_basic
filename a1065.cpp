#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
struct Tracks
{
	void init(int n)
	{
		int t;
		double s;
		for (int i = 0; i < n; ++i)
		{
			cin >> t >> s;
			data.push_back(make_pair(t-1, s));
		}
	}
	vector<pair<int, double>> data;
};

struct Speed
{
	void init()
	{
		for (int i = 0; i < 4; ++i)
		{
			double t;
			cin >> t;
			data[i] = t;
		}
	}
	double data[4];
};

double simulate(Speed& speed, const Tracks& tracks, double T)
{
	double time = 0, coeff = 1, next_T = T;
	for (auto const &track : tracks.data)
	{
		int type = track.first;
		double left_dis = track.second;
		while (left_dis > 0)
		{
			double cur_speed = speed.data[type] * coeff;
			double need_time = left_dis / cur_speed;
			double left = next_T - time;
			if (need_time < left)
			{
				time += need_time;
				left_dis = 0;
			}
			else
			{
				left_dis -= left * cur_speed;
				time += left;
				coeff = (coeff > 0.2 ? coeff - 0.1 : 0.1);
				next_T += T;
			}
		}
	}
	time = round(time * 100) / 100;
	return time;
}

int main()
{
	int n;
	double T;
	cin >> n >> T;
	Speed speed1, speed2;
	speed1.init();
	speed2.init();
	Tracks track;
	track.init(n);

	double time1 = simulate(speed1, track, T);
	double time2 = simulate(speed2, track, T);

	if (time1 == time2) cout << "D" << endl << time1 << endl;
	else if (time1 < time2) cout << "T" << endl << time1 << endl;
	else cout << "R" << endl << time2 << endl;
	return 0;
}
