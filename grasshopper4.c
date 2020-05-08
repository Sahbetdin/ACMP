#include <iostream>
using namespace std;
#include <vector> 



//не осилил
long max_n(long n, long *s)
{
	long i;
	long max_;

	max_ = s[0];
	i = 1;
	while (i < n)
	{
		if (s[i] > max_)
			max_ = s[i];
		i++;
	}
	return (max_);
}

long max1(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}



int main()
{
    long n, i, j, jj, k;
    long tmp;
    string a;
    
    cin >> n >> k >> a;
    vector<long> s;
    s.assign(n, 0);

 
//если последний символ 1, то пишем 0
	if (a[n - 1] == '1')
	{
		cout << 0;
		return (0);
	}

//если n == 1, то выводим кол-во добраться до него есть 1
	if (n == 1 && a[0] == '0')
    {
		cout << 1;
		return (0);
	}


	s[0] = 1 - a[0];

	//	cout << "H";

	i = 1;
	while (i < n)
	{
		j = i - 1;
		jj = k;
		tmp = 0;
		while (j >= 0 && jj > 0)
		{
			tmp = (tmp + s[j]) % 1000000007;
			j--;
			jj--;
		}
		s[i] = (a[i] == '0') ? tmp : 0;
		cout << "s[i] ";
		cout << s[i];
		cout << "\n";
		i++;
	}
    cout << s[n - 1];
    return 0;
}