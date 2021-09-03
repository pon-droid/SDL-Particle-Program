/*
 * Swarm.cpp
 *
 *  Created on: 2 Sept 2021
 *      Author: tp
 */

#include "Swarm.h"

namespace tbg {

Swarm::Swarm() {
	m_Particle = new Particle[NPARTICLES];

}

Swarm::~Swarm() {
	delete[] m_Particle;
}

void Swarm::Update(){
	for(int i=0;i<Swarm::NPARTICLES;i++){
		m_Particle[i].Update();
	}
}

} /* namespace tbg */
