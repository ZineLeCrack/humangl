#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Includes.hpp"

bool	load_image(const char *path) {
	int width, height, channels;
	unsigned char* data = stbi_load(path, &width, &height, &channels, 0);

	if (!data) {
		std::cerr << RED "Error: cannot load image" RESET << std::endl;
		return false;
	}

	GLenum format = (channels == 4) ? GL_RGBA : GL_RGB;

	GLuint	tex;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	human.set_texture(tex);
	stbi_image_free(data);
	return true;
}
