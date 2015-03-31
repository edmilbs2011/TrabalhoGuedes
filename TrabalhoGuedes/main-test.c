#include <stdio.h>
#include <stdbool.h>

int tests_run = 0;

void FAIL() { printf("\nfailure in %s() line %d\n", __FUNCTION__, __LINE__); }
int _assert(test) { do { if (!(test)) { FAIL(); return 1; } } while (0); }
int _verify(int(*test)()) { do { int r = test(); tests_run++; if (r) return r; } while (0); }


//// My tests here

int firstTest() {
	_assert(false);
	return 0;
}

//// Finish my tests

int all_tests() {
	_verify(firstTest);
	return 0;
}

int main() {

		int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);
	
	return getchar(), result != 0;
}



