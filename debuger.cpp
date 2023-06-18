
#include <glfw3.h>
#include <sstream>

#include "log.hpp"
#include "debuger.hpp"


namespace DI{

DebugData* eg_debugData;
extern LogData*  eg_logData;

  void DebugHandler::Init(){
    DI_LOG_TRACE("DebugHandler say: Init Debug");
    eg_debugData = new DebugData();
  }
  void DebugHandler::Kill(){
    DI_LOG_TRACE("DebugHandler say: Kill Debug");
    delete eg_debugData;
  }
}
// Error handling
void ErrorCallback( unsigned int source, unsigned int type, unsigned int id, unsigned int severity, int length, const char* message, const void* userParam ){
    std::stringstream ss;
    ss << "GL CALLBACK: " << ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ) << " type = 0x" << type << ", severity = 0x" << severity << ", message = " << message;
    if (type == GL_DEBUG_TYPE_ERROR){
      DI_LOG_ERROR(ss.str());
    }
    else{
      DI_LOG_INFO(ss.str());
    }

}
void GLClearError(){
    // Clear error vbo of OpenGL
    while(glGetError() != GL_NO_ERROR);
}
void GLCheckError(const char* file, const char* function, int line){
    // Get all acure errors
    uint err;
    while(err = glGetError()){
      std::stringstream ss;
      ss << "GL ERROR: 0x0" << std::hex << err << ", LINE " << std::dec << line << ", FUNCTION " << function << ", FILE " << file;
      DI_LOG_ERROR(ss.str());
    }
}
