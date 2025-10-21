#include "Includes.hpp"

void	set_color(float color[3]) {
	glColor3f(color[0], color[1], color[2]);
}

void	draw_rect(double x1, double y1, double z1, double x2, double y2, double z2, float color[3]) {
	if (x1 == x2) {
		set_color(color); glVertex3d(x1, y1, z1);
		set_color(color); glVertex3d(x1, y1, z2);
		set_color(color); glVertex3d(x1, y2, z2);
		set_color(color); glVertex3d(x1, y2, z1);
	} else if (y1 == y2) {
		set_color(color); glVertex3d(x1, y1, z1);
		set_color(color); glVertex3d(x1, y1, z2);
		set_color(color); glVertex3d(x2, y1, z2);
		set_color(color); glVertex3d(x2, y1, z1);
	} else if (z1 == z2) {
		set_color(color); glVertex3d(x1, y1, z1);
		set_color(color); glVertex3d(x1, y2, z1);
		set_color(color); glVertex3d(x2, y2, z1);
		set_color(color); glVertex3d(x2, y1, z1);
	}
}
