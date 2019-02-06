#include "particle.h"

Particle::Particle(ParticleEmitter *emitter, int size, int lifeTime, int fadeDuration):
    size_(size),
    lifeTime_(lifeTime),
    fadeDuration_(fadeDuration)
{
    setParentItem(emitter);
}

Particle::~Particle() {}

void Particle::fly(bool outOfBounds)
{

}
