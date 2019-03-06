#include "engine.h"

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

Engine::Engine(int gpu) : m_runtime(nullptr), m_gpu(gpu) {}

Engine::~Engine()
{
  if (m_runtime)
  {
    m_runtime->destroy();
  }
}

int Engine::Init()
{
  cudaSetDevice(m_gpu);
  m_runtime = nvinfer1::createInferRuntime(g_logger);
  std::cout << "hi, DLA Core = " << m_runtime->getDLACore() << std::endl;
  return 0;
}

#endif // GOOGLE_TENSORRT
#endif // GOOGLE_CUDA
