#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QPoint>
#include <QTimer>

class ParticleEmitter: public QObject, public QGraphicsItem
{
Q_OBJECT
public:
    explicit ParticleEmitter(QObject *parent = nullptr,
                             int x = 0,
                             int y = 0,
                             int particleAmount = 0,
                             int emitDuration = 0,
                             int lifeTime = 0);

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
    int lifeTime_;
    int bezier_;
    int fadeDuration_;

    double angle_;
    double lifeTimeNoiseFactor_;
};

#endif // PARTICLEEMITTER_H
