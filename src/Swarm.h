/*
 * Swarm.h
 *
 *  Created on: 2 Sept 2021
 *      Author: tp
 */

#ifndef SWARM_H_
#define SWARM_H_

#include"Particle.h"

namespace tbg {

class Swarm {
public:
	const static int NPARTICLES = 5000;
private:
	Particle *m_Particle;
public:
	Swarm();
	virtual ~Swarm();

	const Particle* const Get_Particles() {
		return m_Particle;
	}
	;
};

} /* namespace tbg */

#endif /* SWARM_H_ */
