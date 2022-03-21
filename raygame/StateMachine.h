#pragma once
#include "Component.h"


enum State {
    IDLE,
    WANDER,
    SEEK
};
class SeekComponent;
class WanderComponent;

class StateMachineComponent :
    public Component
{
public: 
    State getCurretnState() { return m_currentState; };
    void setCurrentState(State value) { m_currentState = value; };

    void start() override;
    void update(float deltaTime) override;

private:
    State m_currentState;
    SeekComponent* m_seekComp;
    WanderComponent* m_wanderComp;

    float m_seekForce;
    float m_wanderForce;
    float m_seekRange = 0;
};

