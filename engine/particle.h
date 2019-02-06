#ifndef PARTICLE_H
#define PARTICLE_H

#include "particleemitter.h"

#include <QObject>
#include <QGraphicsEllipseItem>

class Particle: public QObject, public QGraphicsEllipseItem
{
Q_OBJECT
public:
    explicit Particle(ParticleEmitter *emitter = nullptr, int size = 0, int lifeTime = 0 , int fadeDuration = 0);
    virtual ~Particle() override;

    int getSize() const { return size_; }
    int getLifeTime() const { return lifeTime_; }
    int getFadeDuration() const { return fadeDuration_; }

public slots:
    void fly(bool outOfBounds);

private:
    int size_;
    int lifeTime_;
    int fadeDuration_;
};

#endif // PARTICLE_H
