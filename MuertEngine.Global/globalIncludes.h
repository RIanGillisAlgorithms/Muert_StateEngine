


//by ian.gillis
#pragma once
#ifndef GLOBAL_INCLUDES_H
#define GLOBAL_INCLUDES_H	

#ifdef MUERTDRAW_EXPORTS
#define GLOBAL_INCLUDES_H_API __declspec(dllexport)
#else
#define GLOBAL_INCLUDES_H_API __declspec(dllimport)
#endif


// Include GLEW
#include <GL/glew.h>

#define GLFW_INCLUDE_GLU
// Include GLFW
#include "glfw3.h"
//#include "../MuertGlobal/texture.hpp"

// Include GLM
#include <glm/glm.hpp>
using namespace glm;



#endif
