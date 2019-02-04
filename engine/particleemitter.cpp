#include "particleemitter.h"

ParticleEmitter::ParticleEmitter(QObject *parent,
                                 int x,
                                 int y,
                                 int particleAmount,
                                 int emitDuration,
                                 int lifeTime):
    pos_(x, y),
    particleAmount_(particleAmount),
    emitDuration_(emitDuration),
    lifeTime_(lifeTime)
{
    if(parent != nullptr) setParent(parent);

    emitDuration_ = 0;

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
        QGraphicsEllipseItem particle(this);
        int w = 5;
        int h = 5;
        particle.setRect(pos().x()/2-w/2, pos().y()/2-h/2, h, w);
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
