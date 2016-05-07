#ifndef GEO_POLYGON_H
#define GEO_POLYGON_H

#include <array>
#include <vector>

#include "gfx.h"

class Polygon {
public:
	using vec4 = glm::vec4;
	Polygon(std::vector<vec4> vertices, GLfloat x = 0, GLfloat y = 0);
	~Polygon();
	void rotate(float ang, const vec4 &axis); //apparently glm has its own rotate but whatev
	void translate(const vec4 &xy);
	GLfloat* get_vertices();
	GLuint* get_indices();
	int get_vertices_size();
	int get_indices_size();
	int get_num_elements();
	vec4 get_pos();
private:
	void gen_gl_data();

	GLfloat x;
	GLfloat y;
	std::vector<vec4> vertices;
	// Cache data
	bool cache_cur = false; // True if the cache is current
	GLfloat* gl_vertices;
	GLuint* gl_indices;
	int vertices_size;
	int indices_size;
	int num_elements;
};

std::string to_string(const std::vector<glm::vec4> &vertices);

#endif // GEO_POLYGON_H
