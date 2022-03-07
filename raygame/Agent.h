#pragma once
#include "Actor.h"

class Agent :
    public Actor
{
public:
    Agent() {};
    ~Agent() {};

    void start() override;
    void update(float deltaTime) override;

    virtual void onAddComponent(Component* componet);
    
    float getMaxForce();
    void setMatForce(float vslue);

    

};

