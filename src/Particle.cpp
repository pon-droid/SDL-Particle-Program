/*
 * Particle.cpp
 *
 *  Created on: 2 Sept 2021
 *      Author: tp
 */

#include "Particle.h"

namespace tbg {

Particle::Particle() :
		par_x(0), par_y(0) {
	direction = (2 * M_PI * rand())/RAND_MAX;
	speed = (0.00025 * rand())/RAND_MAX;

}

void Particle::Update(int interval) {
	double xspeed = speed * cos(direction);
	double yspeed = speed * sin(direction);

	par_x += xspeed * interval;
	par_y += yspeed * interval;

}

} /* namespace tbg */
