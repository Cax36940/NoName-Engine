#pragma once
#include "System/UpdatesComponentRegistry.hpp"

// Abstract class for Component that can be updated
class UpdatesComponent {

public:
	UpdatesComponent() { UpdatesComponentRegistry::add(this); };
	UpdatesComponent(const UpdatesComponent&) { UpdatesComponentRegistry::add(this);};
	~UpdatesComponent() { UpdatesComponentRegistry::remove(this); };

	virtual void update(float delta) = 0;

};