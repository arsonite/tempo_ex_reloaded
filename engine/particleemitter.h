#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QPoint>
#include <QTimer>2

class ParticleEmitter: public QObject, public QGraphicsRectItem
{
Q_OBJECT
public:
    explicit ParticleEmitter(int x = 0,
                             int y = 0,
                             int particleAmount = 0,
                             int emitDuration = 0);

    virtual ~ParticleEmitter() override;

public slots:
    /* Emit functions */
    void emitParticles();
    void singleShot();
    void startEmitting();
    void stopEmitting();

//signals:

private:
    QTimer *timer_;
    QPoint pos_;

    bool distortLifeTime_;

    int particleAmount_;
    int emitDuration_;
    int bezier_;

    double angle_;
    double lifeTimeNoiseFactor_;
};

#endif // PARTICLEEMITTER_H
