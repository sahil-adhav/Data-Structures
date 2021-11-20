#include<iostream>
using namespace std;


int main()
{	
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("error.txt", "w", stderr);
		freopen("output.txt", "w", stdout);
	#endif


	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cout << i << " ";
	}
}
