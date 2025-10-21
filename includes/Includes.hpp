/*-------- INCLUDES -------*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <unistd.h>
#include <sys/time.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GLFW/glfw3.h>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imconfig.h"
#include "imgui/imgui_internal.h"
#include "imgui/imstb_rectpack.h"
#include "imgui/imstb_textedit.h"
#include "imgui/imstb_truetype.h"

/*-------- NAMESPACE -------*/
using namespace std;
using namespace ImGui;

/*-------- CLASSES --------*/
#include "Human.hpp"

class Human;

/*------- FUNCTIONS ------ */
void	set_color(float [3]);
void	draw_rect(double, double, double, double, double, double, float [3]);

/*----- DEFINE COLORS -----*/
#define RESET	"\033[0m"
#define RED		"\033[31;1m"
#define GREEN	"\033[32;1m"
#define YELLOW	"\033[33;1m"
#define BLUE	"\033[34;1m"
#define MAGENTA	"\033[35;1m"
#define CYAN	"\033[36;1m"

/*--------- DEFINES --------*/

#define KEY_ESC	27
