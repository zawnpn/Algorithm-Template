#include <cstdio>
#include <cstring>
const int MAXN = 100000000;
bool flag[MAXN];
int primes[MAXN / 3], pi;
int main()
{
	int i, j;
	pi = 0;
	memset(flag, false, sizeof(flag));
	for (i = 2; i < MAXN; i++)
	{
		if (!flag[i])
			primes[pi++] = i;
		for (j = 0; (j < pi)  && (i * primes[j] < MAXN); j++)
		{
			flag[i * primes[j]] = true;
			if (i % primes[j] == 0)
				break;
		}
    }
    for (i = 0; i < pi; i++)
        printf("%d\n", primes[i]);
    return 0;
}