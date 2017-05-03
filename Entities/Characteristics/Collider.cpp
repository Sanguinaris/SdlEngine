#include "Collider.h"

ColliderType Collider::getColType()
{
	return _type;
}

float Collider::getWidth()
{
	return _size[0];
}

float Collider::getRadius()
{
	return _size[0];
}

float Collider::getHeight()
{
	return _size[0];
}

int Collider::getXOffset()
{
	return _offsets[0];
}

int Collider::getYOffset()
{
	return _offsets[1];
}
