#pragma once
#include "Component.h"
#include "Transform2D.h"


class SeekComponent :
    public Component
{
public:
    SeekComponent() {};
    ~SeekComponent() { delete m_target; };

    void update(float deltaTime) override;
    Actor* getTarget() { return m_target; }
    void setTarget(Actor* target) { m_target = target; }
    MathLibrary::Vector2 getVolocity() { return m_volocity; }

private:
    MathLibrary::Vector2 m_direction;
    MathLibrary::Vector2 m_volocity;
    Actor* m_target;
};

