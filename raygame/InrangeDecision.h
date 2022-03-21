#pragma once
#include "BooleanDecisions.h"

class InrangeDecision :
    public BooleanDecisions
{
public:
    InrangeDecision(Decision* left = nullptr, Decision* right = nullptr) : BooleanDecisions(left, right) {};
    bool checkCondition(Agent* agent, float deltaTime) override;
};

