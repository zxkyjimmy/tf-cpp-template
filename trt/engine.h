#pragma once

#include <memory>

namespace nvinfer1
{
class ICudaEngine;
class IRuntime;
class IExecutionContext;
} // namespace nvinfer1

class Engine
{
public:
  Engine(int gpu);
  ~Engine();

  int init();

private:
  nvinfer1::IRuntime *m_runtime;
  int m_gpu;
};