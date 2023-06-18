#pragma once 

#include "spdlog/spdlog.h"
#include "spdlog/fmt/bundled/format.h"
#include "spdlog/fmt/ostr.h"
#include "glm/vec4.hpp"
#include <memory>
#include <vector>
#include <string>

namespace DI{

struct LogData{
   std::vector<std::pair<std::string,glm::vec4>> buffer;
   spdlog::logger* console;
};
namespace LogHandler{
   void Init();
   void Kill();
}

extern LogData* eg_logData;
};
// HERE add logs in editor
// Macros for Engine side login system
#define DI_LOG_TRACE(...) DI::eg_logData->console->trace(__VA_ARGS__);\
                          DI::eg_logData->buffer.push_back(std::pair<std::string,glm::vec4>(fmt::format(__VA_ARGS__),glm::vec4(1.0)))

#define DI_LOG_INFO(...)  DI::eg_logData->console->info(__VA_ARGS__);\
                          DI::eg_logData->buffer.push_back(std::pair<std::string,glm::vec4>(fmt::format(__VA_ARGS__),glm::vec4(0.0,1.0,0.0,1.0)))

#define DI_LOG_WARN(...)  DI::eg_logData->console->warn(__VA_ARGS__);\
                          DI::eg_logData->buffer.push_back(std::pair<std::string,glm::vec4>(fmt::format(__VA_ARGS__),glm::vec4(1.0,1.0,0.0,1.0)))

#define DI_LOG_ERROR(...) DI::eg_logData->console->error (__VA_ARGS__);\
                          DI::eg_logData->buffer.push_back(std::pair<std::string,glm::vec4>(fmt::format(__VA_ARGS__),glm::vec4(1.0,0.0,0.0,1.0)))

#define DI_LOG_DEBUG(...) DI::eg_logData->console->debug (__VA_ARGS__);\
                          DI::eg_logData->buffer.push_back(std::pair<std::string,glm::vec4>(fmt::format(__VA_ARGS__),glm::vec4(0.0,0.0,1.0,1.0)))
