#pragma once
#include "Component.h"
#include "Transform2D.h"


class SeekComponent :
    public Component
{
public:
    SeekComponent(Actor* target) : Component::Component() { m_target = target; };
    ~SeekComponent() { delete m_target; };

    void start() override;
    void update(float deltaTime) override;
    Actor* getTarget() { return m_target; }
    void setTarget(Actor* target) { m_target = target; }
    MathLibrary::Vector2 getVelocity() { return m_velocity; }

    float getMaxSpeed() { return m_maxSpeed; }
    void setMaxVelocity(MathLibrary::Vector2 maxVelocity) { m_maxVelocity = maxVelocity; };
    void setMaxSpeed(float speed) { m_maxSpeed = speed; }

private:
    MathLibrary::Vector2 m_desiredVelocity;
    MathLibrary::Vector2 m_velocity;
    MathLibrary::Vector2 m_maxVelocity;

    Actor* m_target;

    

    float m_maxSpeed;
};

