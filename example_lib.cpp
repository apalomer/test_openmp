#include "example_lib.h"
#include <omp.h>
#include <iostream>

void example()
{
  std::exception ex ;
  bool cancelled = false;
  int N = 500;
  int n_done = 0;
#pragma omp parallel
  {
#pragma omp for
    for (int i = 0; i < N; i++) 
    {
#if _OPENMP > 200205
      if(cancelled)
      {
        std::cout << "Cancelling" << std::endl;
#pragma omp cancel for
      }
#pragma omp cancellation point for
#endif
      try
      {
#pragma omp critical
	    {
                  std::cout << "Thread " << omp_get_thread_num() << " iteration " << i << std::endl;
		  ++n_done;
	    }
        if (i == 25)
          throw std::runtime_error("runtime error");
      }
      catch (std::exception &e)
      {
#pragma omp critical
        std::cout << "thread " << omp_get_thread_num() << " caught exception:" << i << std::endl;
		
        // still must remember exception for later handling

        ex = e;
        cancelled=true;

      }
    }
  }
  std::cout << "Total done: " << n_done << std::endl;
}
