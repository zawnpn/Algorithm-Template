//if not support to_string() (C++11,<string>)
#include <sstream>
string my_to_string(int n)
{
	ostringstream stream;
	stream << n;
	return stream.str();
}

//qsort3
int a[100000];
int lt, rt, i, tmp;
void qsort3(int l, int r)
{
    if (l >= r) return;
    tmp = a[l];
    lt = l;
    rt = r;
    i = l + 1;
    while (i <= rt)
    {
        if (a[i] < tmp)
            swap(a[lt++], a[i++]);
        else if (a[i] > tmp)
            swap(a[i], a[rt--]);
        else
            i++;
    }
    qsort3(l, lt - 1);
    qsort3(rt + 1, r);
}

//heapsort
#include <cstdio>
using namespace std;
int n, a[100001], len;
int main()
{
	scanf("%d", &n);
	for (int b = 1; b <= n; ++b)
	{
		scanf("%d", &a[b]);
		len = b;
		while (len != 1)
		{
			if (a[len] < a[len / 2])
			{
				int t = a[len / 2];
				a[len / 2] = a[len];
				a[len] = t;
			}
			else break;
			len /= 2;
		}
	}
	for (int b = 1; b <= n; ++b)
	{
		printf("%d ", a[1]);
		a[1] = a[n - b + 1]; len = 1;
		while (len * 2 <= n - b)
		{
			int next = len * 2;
			if ((a[next] > a[next + 1] && next < n - b))next++;
			if (a[len] <= a[next])break;
			int t = a[len]; a[len] = a[next]; a[next] = t;
			len = next;
		}
	}
	return 0;
}