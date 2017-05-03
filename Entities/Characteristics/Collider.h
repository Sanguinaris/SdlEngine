#pragma once
#include "../BaseEntity.h"

enum ColliderType {
	BoxCollider,
	CircleCollider,
	EllipseCollider
};

class Collider {	//Will Collide with things and trigger triggers
public:
	Collider(BaseEntity Parent, ColliderType ColType) : _parent(Parent), _type(ColType) {};	//Tries to autogenerate a collider from the entity sprite
	Collider(BaseEntity Parent, float Radius) : _parent(Parent), _size{ Radius, -1 }, _type(CircleCollider) {};	//I dont think we need to know what collidertype we need when we set the radius | Circle is base from the middle of the sprite
	Collider(BaseEntity Parent, float Width, float Height, ColliderType ColType) : _parent(Parent), _size{ Width, Height }, _type(ColType) {};
	Collider(BaseEntity Parent, float Width, float Height, int xOffset, int yOffset) : _parent(Parent), _size{ Width, Height }, _offsets{ xOffset, yOffset }, _type(BoxCollider) {};	//Only used for boxcolliders

public:		//Virtuals
	virtual void OnCollide(BaseEntity& Collider) {}

public:
	ColliderType getColType();
	float getWidth();
	float getRadius();
	float getHeight();

	int getXOffset();
	int getYOffset();
private:
	BaseEntity _parent;
	float _size[2];	// 0 = Width = radius with circle coll; 1 = Height
	int _offsets[2]; // to make it more precise with boxes
	ColliderType _type;
};
