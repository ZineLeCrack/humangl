#include "Includes.hpp"

void	set_color(float color[3])
{
	glColor3f(color[0], color[1], color[2]);
}

void	draw_rect(const Vec3 &a, const Vec3 &b, const float color[3], Shaders &shader, ModelStack &modelStack)
{
	// (void)modelStack;
	std::vector<float> vertices;

	if (a.z == b.z) {
		vertices = {
			a.x, a.y, a.z,
			a.x, b.y, a.z,
			b.x, b.y, a.z,

			a.x, a.y, a.z,
			b.x, a.y, a.z,
			b.x, b.y, a.z,
		};
	}
	else if (a.y == b.y) {
		vertices = {
			a.x, a.y, a.z,
			b.x, a.y, a.z,
			b.x, a.y, b.z,

			a.x, a.y, a.z,
			a.x, a.y, b.z,
			b.x, a.y, b.z,
		};
	}
	else if (a.x == b.x) {
		vertices = {
			a.x, a.y, a.z,
			a.x, b.y, a.z,
			a.x, b.y, b.z,

			a.x, a.y, a.z,
			a.x, a.y, b.z,
			a.x, b.y, b.z,
		};
	} else return;

	GLuint VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	glUseProgram(shader.shaderProgram);
	GLint colorLoc = glGetUniformLocation(shader.shaderProgram, "uColor");
	glUniform3fv(colorLoc, 1, color);

	GLint modelLoc = glGetUniformLocation(shader.shaderProgram, "uModel");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, modelStack.current().data());

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glBindVertexArray(0);
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}
