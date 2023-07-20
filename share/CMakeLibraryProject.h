#ifdef CMAKELIBRARYPROJECT_EXPORT
#define SAMPLEAPI __declspec(dllexport)
#else
#define SAMPLEAPI __declspec(dllimport)
#endif

extern "C" SAMPLEAPI int test_func(int a, int b);
