#pragma once

#include "Matrix.hpp"
#include <vector>

class ModelStack
{
	private:
		vector<Matrix> mstack;
	public:
		ModelStack();
		~ModelStack();

		void	push();
		void	pop();
		void	loadIdentity();

		void	translate(float tx, float ty, float tz);
		void	rotate(float angle_deg, char axis);

		Matrix	&current();
};
