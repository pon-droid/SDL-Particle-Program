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

}

} /* namespace tbg */
