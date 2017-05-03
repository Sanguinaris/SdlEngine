#pragma once
#include <iostream>

class BaseEntity {
	//inclass funcs

public:
	virtual void OnRender() {}
	virtual void OnDestroy() {}

public:	//getters / setters
	std::string getName();	//Get Class Name e.g. for finding it or an instance in the entitymanager

private:	//Vars
	std::string _Name;	//Class Name
	int xPos, yPos;		//Position of the Entity
};