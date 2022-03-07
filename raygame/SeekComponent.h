#pragma once
#include "SteeringComponent.h"
#include "Transform2D.h"


class SeekComponent :
    public SteeringComponent
{
public:
    SeekComponent() {};
    SeekComponent(Actor* target) : SteeringComponent::SteeringComponent() { m_target = target; };
    ~SeekComponent() { delete m_target; };

    //Happes at the start of the the oporation 
    void start() override;
    //Updates the current state of the componets 
    void update(float deltaTime) override;

    //Gets the sets the target of this component 
    Actor* getTarget() { return m_target; }   
    //Sets the value for the force being puished 
    float getForce() { return m_force; }
    //Displays the values of the values for the Velocity
    MathLibrary::Vector2 getVelocity() { return m_velocity; }

    MathLibrary::Vector2 calculateForce();

    //Sets the accosiated values to there private variables
    void setTarget(Actor* target) { m_target = target; }
    void setMaxVelocity(MathLibrary::Vector2 maxVelocity) { m_maxVelocity = maxVelocity; };
    void setForce(float speed) { m_force = speed; }

private:
    MathLibrary::Vector2 m_desiredVelocity;
    MathLibrary::Vector2 m_velocity;
    MathLibrary::Vector2 m_maxVelocity;

    Actor* m_target;

    

    float m_force;
};

