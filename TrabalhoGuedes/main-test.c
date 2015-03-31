#include <stdio.h>
#include <stdbool.h>

#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)

int tests_run = 0;
int main() {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}
int all_tests() {
	_verify(first_test);
	return 0;
}


//// My tests here

static int first_test() {
	_assert(false);
	return 0;
}

