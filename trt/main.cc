#if GOOGLE_CUDA
#if GOOGLE_TENSORRT

#include "trt/engine.h"

int main()
{
  Engine engine(2);
  engine.Init();
  return 0;
}

#endif // GOOGLE_TENSORRT
#endif // GOOGLE_CUDA
