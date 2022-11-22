#           if FREEGLUT_LIB_PRAGMAS
#               ifdef NDEBUG
#                   pragma comment (lib, "freeglut.lib")
#               else
#                   pragma comment (lib, "freeglutd.lib")
#               endif
#           endif

#pragma once
#pragma warning(disable : 4996)

// OpenGL
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>


#include <iostream>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

#define _USE_MATH_DEFINES
#include <math.h>