/*
 * Particle.cpp
 *
 *  Created on: 2 Sept 2021
 *      Author: tp
 */

#include "Particle.h"

namespace tbg {

Particle::Particle() {

	par_x = ((2.0 * rand()) / RAND_MAX) - 1;
	par_y = ((2.0 * rand()) / RAND_MAX) - 1;

	speed = 0.0025 * (((2.0 * rand()) / RAND_MAX) - 1);

}

void Particle::Update() {
	par_x += speed;
	par_y += speed;

	if (par_x <= -1.0 || par_x >= 1.0) {
		speed = -speed;
	}
	if (par_y <= -1.0 || par_y >= 1.0) {
		speed = -speed;
	}
}

} /* namespace tbg */
