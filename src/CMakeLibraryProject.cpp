#include "framework.h"
#include "_CMakeLibraryProject.h"

int test_func(int a, int b) {
	return test_func_impl(a, b);
}

int test_func_impl(int a, int b) {
	return a + b;
}
