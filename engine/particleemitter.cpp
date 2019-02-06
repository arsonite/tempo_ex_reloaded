#include "particleemitter.h"
#include "particle.h"

#include <QPen>
#include <QBrush>

#include <QDebug>

ParticleEmitter::ParticleEmitter(int x, int y, int particleAmount, int emitDuration):
    pos_(x, y),
    particleAmount_(particleAmount),
    emitDuration_(emitDuration)
{
    emitDuration_ = 0;

    setRect(0, 0, 10, 10);
    setPos(x, y);

    timer_ = new QTimer();
    connect(timer_, &QTimer::timeout, this, &ParticleEmitter::emitParticles);
}

ParticleEmitter::~ParticleEmitter()
{
    delete timer_;
}

void ParticleEmitter::emitParticles()
{
    for(int i = 0, n = particleAmount_; i < n; i++) {
        Particle *p = new Particle(this);
        int size = p->getSize()/2;
        p->setRect(0, 0, size, size);
        p->setPen(QPen(Qt::NoPen));
        p->setBrush(QBrush(QColor(255, 0, 0)));
        p->fly(false);
    }
}

void ParticleEmitter::singleShot()
{
    timer_->start();
    timer_->stop();
}

void ParticleEmitter::startEmitting()
{
    timer_->start();
}

void ParticleEmitter::stopEmitting()
{
    timer_->stop();
}
