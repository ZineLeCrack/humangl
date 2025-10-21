#include "Human.hpp"

void	Human::set_color(float color[3]) {
	glColor3f(color[0], color[1], color[2]);
}

void	Human::draw_legs() {
	glBegin(GL_QUADS);
	
	this->set_color(_legs_color); glVertex3d(-0.25, 0.0, -0.1);
	this->set_color(_legs_color); glVertex3d(-0.25, 0.0, 0.1);
	this->set_color(_legs_color); glVertex3d(-0.25, -0.8, 0.1);
	this->set_color(_legs_color); glVertex3d(-0.25, -0.8, -0.1);

	this->set_color(_legs_color); glVertex3d(-0.05, 0.0, -0.1);
	this->set_color(_legs_color); glVertex3d(-0.05, 0.0, 0.1);
	this->set_color(_legs_color); glVertex3d(-0.05, -0.8, 0.1);
	this->set_color(_legs_color); glVertex3d(-0.05, -0.8, -0.1);
	
	this->set_color(_legs_color); glVertex3d(0.05, 0.0, -0.1);
	this->set_color(_legs_color); glVertex3d(0.05, 0.0, 0.1);
	this->set_color(_legs_color); glVertex3d(0.05, -0.8, 0.1);
	this->set_color(_legs_color); glVertex3d(0.05, -0.8, -0.1);
	
	this->set_color(_legs_color); glVertex3d(0.25, 0.0, -0.1);
	this->set_color(_legs_color); glVertex3d(0.25, 0.0, 0.1);
	this->set_color(_legs_color); glVertex3d(0.25, -0.8, 0.1);
	this->set_color(_legs_color); glVertex3d(0.25, -0.8, -0.1);
	
	this->set_color(_legs_color); glVertex3d(-0.25, 0.0, 0.1);
	this->set_color(_legs_color); glVertex3d(-0.25, -0.8, 0.1);
	this->set_color(_legs_color); glVertex3d(-0.05, -0.8, 0.1);
	this->set_color(_legs_color); glVertex3d(-0.05, 0.0, 0.1);

	this->set_color(_legs_color); glVertex3d(0.25, 0.0, 0.1);
	this->set_color(_legs_color); glVertex3d(0.25, -0.8, 0.1);
	this->set_color(_legs_color); glVertex3d(0.05, -0.8, 0.1);
	this->set_color(_legs_color); glVertex3d(0.05, 0.0, 0.1);
	
	this->set_color(_legs_color); glVertex3d(-0.25, 0.0, -0.1);
	this->set_color(_legs_color); glVertex3d(-0.25, -0.8, -0.1);
	this->set_color(_legs_color); glVertex3d(-0.05, -0.8, -0.1);
	this->set_color(_legs_color); glVertex3d(-0.05, 0.0, -0.1);
	
	this->set_color(_legs_color); glVertex3d(0.25, 0.0, -0.1);
	this->set_color(_legs_color); glVertex3d(0.25, -0.8, -0.1);
	this->set_color(_legs_color); glVertex3d(0.05, -0.8, -0.1);
	this->set_color(_legs_color); glVertex3d(0.05, 0.0, -0.1);

	this->set_color(_foots_color); glVertex3d(-0.25, -1.0, -0.1);
	this->set_color(_foots_color); glVertex3d(-0.25, -1.0, 0.1);
	this->set_color(_foots_color); glVertex3d(-0.05, -1.0, 0.1);
	this->set_color(_foots_color); glVertex3d(-0.05, -1.0, -0.1);

	this->set_color(_foots_color); glVertex3d(0.25, -1.0, -0.1);
	this->set_color(_foots_color); glVertex3d(0.25, -1.0, 0.1);
	this->set_color(_foots_color); glVertex3d(0.05, -1.0, 0.1);
	this->set_color(_foots_color); glVertex3d(0.05, -1.0, -0.1);
	
	this->set_color(_foots_color); glVertex3d(-0.25, -1.0, -0.1);
	this->set_color(_foots_color); glVertex3d(-0.25, -1.0, 0.1);
	this->set_color(_foots_color); glVertex3d(-0.25, -0.8, 0.1);
	this->set_color(_foots_color); glVertex3d(-0.25, -0.8, -0.1);

	this->set_color(_foots_color); glVertex3d(-0.05, -1.0, -0.1);
	this->set_color(_foots_color); glVertex3d(-0.05, -1.0, 0.1);
	this->set_color(_foots_color); glVertex3d(-0.05, -0.8, 0.1);
	this->set_color(_foots_color); glVertex3d(-0.05, -0.8, -0.1);

	this->set_color(_foots_color); glVertex3d(0.05, -1.0, -0.1);
	this->set_color(_foots_color); glVertex3d(0.05, -1.0, 0.1);
	this->set_color(_foots_color); glVertex3d(0.05, -0.8, 0.1);
	this->set_color(_foots_color); glVertex3d(0.05, -0.8, -0.1);

	this->set_color(_foots_color); glVertex3d(0.25, -1.0, -0.1);
	this->set_color(_foots_color); glVertex3d(0.25, -1.0, 0.1);
	this->set_color(_foots_color); glVertex3d(0.25, -0.8, 0.1);
	this->set_color(_foots_color); glVertex3d(0.25, -0.8, -0.1);

	this->set_color(_foots_color); glVertex3d(-0.25, -1.0, 0.1);
	this->set_color(_foots_color); glVertex3d(-0.25, -0.8, 0.1);
	this->set_color(_foots_color); glVertex3d(-0.05, -0.8, 0.1);
	this->set_color(_foots_color); glVertex3d(-0.05, -1.0, 0.1);

	this->set_color(_foots_color); glVertex3d(0.25, -1.0, 0.1);
	this->set_color(_foots_color); glVertex3d(0.25, -0.8, 0.1);
	this->set_color(_foots_color); glVertex3d(0.05, -0.8, 0.1);
	this->set_color(_foots_color); glVertex3d(0.05, -1.0, 0.1);

	this->set_color(_foots_color); glVertex3d(-0.25, -1.0, -0.1);
	this->set_color(_foots_color); glVertex3d(-0.25, -0.8, -0.1);
	this->set_color(_foots_color); glVertex3d(-0.05, -0.8, -0.1);
	this->set_color(_foots_color); glVertex3d(-0.05, -1.0, -0.1);

	this->set_color(_foots_color); glVertex3d(0.25, -1.0, -0.1);
	this->set_color(_foots_color); glVertex3d(0.25, -0.8, -0.1);
	this->set_color(_foots_color); glVertex3d(0.05, -0.8, -0.1);
	this->set_color(_foots_color); glVertex3d(0.05, -1.0, -0.1);

	glEnd();
}
