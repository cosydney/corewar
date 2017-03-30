#include "minunit.h"
#include "corewar.h"

MU_TEST(sample) {
	int i, j;
	i = 9;
	j = 8;
	mu_check(i==j);
}

MU_TEST_SUITE(suite){
	MU_RUN_TEST(sample);
}

int main(int argc, const char *argv[])
{
	MU_RUN_SUITE(suite);
	MU_REPORT();
	return 0;
}
