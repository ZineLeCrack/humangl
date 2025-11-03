#include "ModelStack.hpp"

ModelStack::ModelStack() { mstack.push_back(Matrix::identity()); }

ModelStack::~ModelStack() {}

void	ModelStack::push() { mstack.push_back(mstack.back()); }

void	ModelStack::pop() { if (mstack.size() > 1) mstack.pop_back(); }

void	ModelStack::loadIdentity() { mstack.back() = Matrix::identity(); }

void	ModelStack::translate(float tx, float ty, float tz)
{
	mstack.back() = mstack.back() * Matrix::translate(tx, ty, tz);
}

void	ModelStack::rotate(float angle_deg, char axis)
{
	float rad = angle_deg * (M_PIf / 180.0f);
	if (axis == 'X') mstack.back() = mstack.back() * Matrix::rotateX(rad);
	else if (axis == 'Y') mstack.back() = mstack.back() * Matrix::rotateY(rad);
	else if (axis == 'Z') mstack.back() = mstack.back() * Matrix::rotateZ(rad);
}

void	ModelStack::scale(float sx, float sy, float sz)
{
    mstack.back() = mstack.back() * Matrix::scale(sx, sy, sz);
}

Matrix &ModelStack::current() { return mstack.back(); }
