/*-------- INCLUDES -------*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <array>
#include <unistd.h>
#include <sys/time.h>
#include <GL/glew.h>
#include <GL/gl.h>
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
class Vec3;
class Human;
class Matrix;
class Shaders;

#include "Human.hpp"
#include "Shaders.hpp"
#include "Vec3.hpp"
#include "Matrix.hpp"
#include "ModelStack.hpp"

/*--- GLOBALS VARIABLES ---*/
extern Human human;

/*------- FUNCTIONS ------ */
bool	load_image(const char *path);
void	draw_cube(Shaders &shader, const Matrix &model);
void	set_color(float color[3]);
void	draw_rect(const Vec3 &a, const Vec3 &b, const float color[3], const float u, const float v, const float uscale, const float vscale, bool swap, Shaders &shader, ModelStack &modelStack);
void    draw_paving_shape(const Vec3 &a, const Vec3 &b, const float color[3], const float _size, Shaders &shader, ModelStack &modelStack);

/*----- DEFINE COLORS -----*/
#define RESET	"\033[0m"
#define RED		"\033[31;1m"
#define GREEN	"\033[32;1m"
#define YELLOW	"\033[33;1m"
#define BLUE	"\033[34;1m"
#define MAGENTA	"\033[35;1m"
#define CYAN	"\033[36;1m"

/*--------- DEFINES --------*/

#define STAY		0
#define WALK		1
#define JUMP		2
#define SPRINT		3
#define DISCO_DANCE	4
