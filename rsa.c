#include <stdio.h>
#include <stdlib.h>

int isprime(int n);

int main(int argc, char **argv) {
	char line[100];
	unsigned long long int num;
	long long int i;
	FILE *file = fopen(argv[1], "r");

	while (fgets(line, sizeof(line), file) != NULL) 
	{
		num = atoll(line);
		for (i = 2LL; i < num; i++)
		{
			if (num % i == 0 && isprime(i) && isprime(num/i))
			{
				printf("%lld=%lld*%lld\n", num, num/i, i);
				break;
			}
		}
	}
	fclose(file);
	return 0;
}

int isprime(int n)
{
	int m = 1;
	int i;

	if (n == 2)
		return (1);
	if (n % 2 == 0  || n == 1)
		return (0);

	for(i == 0; i <= n/2; i++)
	{
		if (n % i == 0)
			m = 0;
	}
            return (m);
}
