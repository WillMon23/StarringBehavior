#pragma once
#include "Actor.h"

class SeekComponent;
class SpriteComponent;
class MoveComponent;
class RotateComponent;
class FleeComponent;
class Enemy :
    public Actor
{
public :
    Enemy(float x, float y, const char* name, Actor* target);
    ~Enemy() {};

    void start() override;
    void update(float deltaTime);
    Actor* getTarget() { return m_target; }

private:
    SpriteComponent* m_spriteComp;
    MoveComponent* m_moveComp;
    RotateComponent* m_rotateComp;

    SeekComponent* m_seekComp;
    FleeComponent* m_fleeComp;

    Actor* m_target;

};

