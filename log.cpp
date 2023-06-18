#include "log.hpp"
#include "spdlog/sinks/stdout_sinks.h"


namespace DI{
   LogData* eg_logData;


   void LogHandler::Init(){
      eg_logData = new LogData(); 
      spdlog::set_pattern("%^%n-> %v %$");
      eg_logData->console =  spdlog::stdout_color_mt("DI").get(); 
      eg_logData->console->set_level(spdlog::level::trace);
      DI_LOG_TRACE("LogHandler say: Init Log");
   }
   void LogHandler::Kill(){
     eg_logData->buffer.clear();
     DI_LOG_TRACE("LogHandler say: Kill Log");
     delete eg_logData;
   }
}
