
#ifdef EXEMPLE_LIB_EXPORT
#define EXEMPLE_LIB __declspec(dllexport)
#else
#define EXEMPLE_LIB __declspec(dllimport)
#endif

EXEMPLE_LIB void example();