#include <algorithm>
#include <memory>
#include <vector>
#include <iostream>

#if GOOGLE_CUDA
#if GOOGLE_TENSORRT

#include "cuda/include/cuda_runtime_api.h"
#include "tensorrt/include/NvInfer.h"

class Logger : public nvinfer1::ILogger
{
  void log(Severity severity, const char *msg) override
  {
    switch (severity)
    {
    case Severity::kINTERNAL_ERROR:
      std::cerr << "INTERNAL ERROR: " << msg << std::endl;
      break;
    case Severity::kERROR:
      std::cerr << "ERROR: " << msg << std::endl;
      break;
    case Severity::kWARNING:
      std::cerr << "WARNING ERROR: " << msg << std::endl;
      break;
    case Severity::kINFO:
      std::cerr << "INFO ERROR: " << msg << std::endl;
      break;
    }
  }
} g_logger;

int main()
{
  cudaSetDevice(2);
  nvinfer1::IRuntime *m_runtime = nvinfer1::createInferRuntime(g_logger);
  int x;
  std::cin >> x;
  std::cout << "hi, " << x << std::endl;
  return 0;
}

#endif // GOOGLE_TENSORRT
#endif // GOOGLE_CUDA
