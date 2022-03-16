#pragma once
#include "Agent.h"

class SeekComponent;
class SpriteComponent;
class MoveComponent;
class RotateComponent;
class FleeComponent;
class Enemy :
    public Agent
{
public :
    Enemy(float x, float y, const char* name, Actor* target);
    Enemy(float x, float y, const char* name, float maxForce, float maxSpeed, Actor* target);
    ~Enemy() {};

    void start() override;
    void update(float deltaTime);

    bool getTargetInRange();

    Actor* getTarget() { return m_target; };
    void setTarget(Actor* target) { m_target = target; };

    bool getIsAgressive() { return m_isAgressive; };
    void setIsAgressive(bool agressive) { m_isAgressive = agressive; };

private:
    SpriteComponent* m_spriteComp;
    MoveComponent* m_moveComp;
    RotateComponent* m_rotateComp;

    SeekComponent* m_seekComp;
    FleeComponent* m_fleeComp;

    bool m_isAgressive;

    Actor* m_target;

};

