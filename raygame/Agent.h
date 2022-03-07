#pragma once
#include "Actor.h"
#include <Vector2.h>
#include "SteeringComponent.h"
#include "DynamicArray.h"

class MoveComponent;
class SteeringComponent;

class Agent :
    public Actor
{
public:
    Agent() {};
    ~Agent() {};

    void start() override;
    void update(float deltaTime) override;

    void onAddComponent(Component* componet) override;

    float getMaxForce() { return m_maxForce; };
    void setMatForce(float value) { m_maxForce = value; };

    MathLibrary::Vector2 getForce() { return m_force; };
    void setForce(MathLibrary::Vector2 value) { m_force = value; };

    MoveComponent* getMoveMoveComponent() { return m_moveComponent; };

private:
    DynamicArray<SteeringComponent*> m_steeringComponent;

    float m_maxForce;
    MoveComponent* m_moveComponent;
    MathLibrary::Vector2 m_force;
};

