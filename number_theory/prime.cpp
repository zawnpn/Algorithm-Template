const int maxn = 10000010;
bool is_prime[maxn];
int primes[maxn/3], pi;
long long tmp;
void GenPrime(int n){
	int i, j;
	pi = 0;
	for (i = 2; i <= n; i++)
		is_prime[i] = 1;
	for (i = 2; i <= n; i++){
		if (is_prime[i])
			primes[pi++] = i;
		for (j = 0; j < pi; j++){
			tmp = i * primes[j];
			if (tmp > n) break;
			is_prime[tmp] = 0;
			if (i % primes[j] == 0) break;
		}
	}
}