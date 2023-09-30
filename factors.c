#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(int argc, char **argv) {
	char line[4064];

	FILE *file = fopen(argv[1], "r");

	while (fgets(line, sizeof(line), file) != NULL) 
	{
		mpz_t num;
		mpz_init(num);
		mpz_set_str(num, line, 10);
		mpz_t i;
		mpz_init(i);
		mpz_set_ui(i,2);
		while (mpz_cmp(i, num) <= 0)
		{
			mpz_t r;
			mpz_init(r);
			mpz_mod(r, num, i);
			if ( mpz_cmp_ui(r, 0) == 0)
			{
				mpz_t d;
				mpz_init(d);
				mpz_div(d, num, i);
				gmp_printf("%Zd=%Zd*%Zd\n",num,d,i);
				mpz_clear(d);
				mpz_clear(r);
				break;
			}
			mpz_clear(r);
			mpz_add_ui(i, i, 1);
		}
		mpz_clear(i);
		mpz_clear(num);
	}
	fclose(file);
	return 0;
}
