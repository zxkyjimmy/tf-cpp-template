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
      std::err << "INTERNAL ERROR: " << msg << std::endl;
      break;
    case Severity::kERROR:
      std::err << "ERROR: " << msg << std::endl;
      break;
    case Severity::kWARNING:
      std::err << "WARNING ERROR: " << msg << std::endl;
      break;
    case Severity::kINFO:
      std::err << "INFO ERROR: " << msg << std::endl;
      break;
    }
  }
} g_logger;

int main()
{
  cudaSetDevice(2);
  nvinfer1::IRuntime *m_runtime = nvinfer1::createInferRuntime(g_logger);
  return 0;
}

#endif // GOOGLE_TENSORRT
#endif // GOOGLE_CUDA