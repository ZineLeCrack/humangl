#include "Includes.hpp"

void	set_color(float color[3])
{
	glColor3f(color[0], color[1], color[2]);
}

void	draw_rect(const Vec3 &a, const Vec3 &b, const float color[3], const float u, const float v, const float uscale, const float vscale, bool swap, Shaders &shader, ModelStack &modelStack)
{
	std::vector<float> vertices;
	float	du = u + uscale;
	float	dv = v + vscale;

	float	u0, u1, v0, v1;

	if (swap) {
		u0 = du;
		u1 = u;
		v0 = v;
		v1 = dv;
	} else {
		u0 = u;
		u1 = du;
		v0 = v;
		v1 = dv;
	}

	if (a.z == b.z) {
		vertices = {
			a.x, a.y, a.z, u1, v1,
			a.x, b.y, a.z, u1, v0,
			b.x, b.y, a.z, u0, v0,

			a.x, a.y, a.z, u1, v1,
			b.x, a.y, a.z, u0, v1,
			b.x, b.y, a.z, u0, v0,
		};
	}
	else if (a.y == b.y) {
		vertices = {
			a.x, a.y, a.z, u1, v1,
			b.x, a.y, a.z, u0, v1,
			b.x, a.y, b.z, u0, v0,

			a.x, a.y, a.z, u1, v1,
			a.x, a.y, b.z, u1, v0,
			b.x, a.y, b.z, u0, v0,
		};
	}
	else if (a.x == b.x) {
		vertices = {
			a.x, a.y, a.z, u1, v1,
			a.x, b.y, a.z, u1, v0,
			a.x, b.y, b.z, u0, v0,

			a.x, a.y, a.z, u1, v1,
			a.x, a.y, b.z, u0, v1,
			a.x, b.y, b.z, u0, v0,
		};
	} else return;

	GLuint VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), NULL);

	// glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
	// glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(2);

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

void draw_paving_shape(const Vec3 &a, const Vec3 &b, const float color[3], const float _size, Shaders &shader, ModelStack &modelStack)
{
	draw_rect({a.x, a.y * _size, a.z}, {b.x, b.y * _size, a.z}, color, 0, 0, 0, 0, false, shader, modelStack);
	draw_rect({a.x, a.y * _size, b.z}, {b.x, b.y * _size, b.z}, color, 0, 0, 0, 0, false, shader, modelStack);

	draw_rect({a.x, a.y * _size, a.z}, {a.x, b.y * _size, b.z}, color, 0, 0, 0, 0, false, shader, modelStack);
	draw_rect({b.x, a.y * _size, a.z}, {b.x, b.y * _size, b.z}, color, 0, 0, 0, 0, false, shader, modelStack);

	draw_rect({a.x, a.y * _size, a.z}, {b.x, a.y * _size, b.z}, color, 0, 0, 0, 0, false, shader, modelStack);
	draw_rect({a.x, b.y * _size, a.z}, {b.x, b.y * _size, b.z}, color, 0, 0, 0, 0, false, shader, modelStack);
}
