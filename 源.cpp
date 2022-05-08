#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1005;
int i, j;
int tot = 0;
string Un[N] = { "NULL" };
string Pw[N] = { "NULL" };
string com[4] = { "add","delete","find","list"};
int cheak(string in)
{
	for (i = 0; i <= 3; i++)
	{
		if (in == com[i])
		{
			return i;
		}
	}
	return -1;
}
void del(int q)
{
	if (q == tot)
	{
		Un[tot] = "NULL";
		Pw[tot] = "NULL";
		return;
	}
	for (i = q; i <= tot; i++)
	{
		Un[i] = Un[i + 1];
		Pw[i] = Pw[i + 1];
	}
}
bool Mul(string in)
{
	for (i = 1; i <= tot; i++)
	{
		if (in == Un[i])
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	string input;
	cin >> input;
	if (cheak(input) == 0)
	{
		tot++;
		cout << "Username:" << endl;
		cin >> input;
		if (Mul(input) == 1)
		{
			tot--;
			cout << "The name is already taken" << endl << endl;
			main();
		}
		Un[tot] = input;
		cout << "Password:" << endl;
		cin >> input;
		Pw[tot] = input;
		cout << endl << "Complete" << endl << endl;
		main();
	}
	else
	{
		if (cheak(input) == 1)
		{
			cout << "Delete Username:" << endl;
			cin >> input;
			for (i = 1; i <= tot; i++)
			{
				if (input == Un[i])
				{
					del(i);
					tot--;
					cout << endl << "Complete" << endl << endl;
					main();
				}
			}
			cout << "Can't find" << endl;
			main();
		}
		else
		{
			if (cheak(input) == 2)
			{
				cout << "The Username or The Password:" << endl;
				cin >> input;
				for (i = 1; i <= tot; i++)
				{
					if (input == Un[i] || input == Pw[i])
					{
						cout << "Username: " << Un[i] << endl;
						cout << "Password: " << Pw[i] << endl;
						cout << endl << "Complete" << endl << endl;
						main();
					}
				}
				cout << "Can't find" << endl;
				main();
			}
			else
			{
				if (cheak(input) == 3)
				{
					for (i = 1; i <= tot; i++)
					{
						cout << "The Username: " << Un[i] << "     The Password: " << Pw[i] << endl;
					}
					main();
				}
				else
				{
					cout << "Unknow command" << endl << endl;
					main();
				}
			}
		}
	}
}