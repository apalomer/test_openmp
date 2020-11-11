
#if defined(_WIN32) || defined(_WIN64) || defined(WINCE) || defined(__MINGW32__)
#ifdef EXEMPLE_LIB_EXPORT
#define EXEMPLE_LIB __declspec(dllexport)
#else
#define EXEMPLE_LIB __declspec(dllimport)
#endif
#else
#define EXEMPLE_LIB
#endif

EXEMPLE_LIB void example();
