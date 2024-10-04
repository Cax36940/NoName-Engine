#pragma once

class PhysicsComponent {

protected:
	PhysicsComponent();
	~PhysicsComponent();

public:
	virtual void registerPhysics() = 0;

};