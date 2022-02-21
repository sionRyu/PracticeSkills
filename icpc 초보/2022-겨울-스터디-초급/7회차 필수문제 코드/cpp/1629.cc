#include<stdio.h>
using lint = long long;

lint mod;
lint mul (lint base, lint exp)
{
	if (exp == 0) return 1;
    
	if (exp % 2 == 1) return mul(base, exp-1) * base % mod;
    lint half = mul (base, exp / 2);
	return half * half % mod;
}

int main ()
{
    lint a, b;
	scanf ("%lld %lld %lld", &a, &b, &mod);

	printf ("%lld\n", mul (a, b));
	return 0;
}