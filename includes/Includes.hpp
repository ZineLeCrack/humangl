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

/*-------- NAMESPACE -------*/
using namespace std;

/*-------- CLASSES --------*/
#include "Human.hpp"

class Human;

/*------- FUNCTIONS ------ */

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
