#pragma once

class PhysicsComponent {

protected:
	PhysicsComponent();
	~PhysicsComponent();

public:
	virtual void RegisterPhysics() = 0;

};