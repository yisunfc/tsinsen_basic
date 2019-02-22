#include<iostream> 

using namespace std; 

int pow(int b,int n) 
{ 
	int ret = 1; 
	for(int i = 0;i < n; ++i) 
		ret = (ret * b) % 9999; 
	return ret; 
}
int main() 
{ 
	int n, x0, ret = 0; 
	cin >> n >> x0;
	for (int i = 0; i <= n; ++i) 
	{ 
		int t;
		cin >> t;
		ret = (ret % 9999) + (pow(x0, i-1) * ((t * i) % 9999)) % 9999 + 9999; 
		ret %= 9999;
	}
	cout << ret << endl;
	return 0; 
} 
