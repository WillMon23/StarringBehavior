#pragma once
#include "Actor.h"

class SeekComponent;
class SpriteComponent;
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
    SeekComponent* m_seekComp;

    Actor* m_target;

};
