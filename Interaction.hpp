#pragma once

#include <memory>

#include "PhysicalObject.hpp"

class Interaction {
public:
	Interaction(std::shared_ptr<PhysicalObject> _object1, std::shared_ptr<PhysicalObject> _object2) :
		object1{_object1}, object2{_object2} {}

	void calc_force();
	void do_collision();

private:
	std::shared_ptr<PhysicalObject> object1, object2;
};
