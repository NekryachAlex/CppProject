#include "PhysicalObject.hpp"


void PhysicalObject::update(float dt) {
	prev_position = position;
	
	velocity += acceleration * dt;
	position += velocity * dt;

	acceleration = algebra::zero_vector;
	collised = false;
}

void PhysicalObject::draw() {
	figures::easy_circle(position, radius, *window, color);
}