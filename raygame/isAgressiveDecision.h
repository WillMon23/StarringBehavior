#pragma once
#include "BooleanDecisions.h"
class isAgressiveDecision :
    public BooleanDecisions
{
public:
    isAgressiveDecision(Decision* left = nullptr, Decision* right = nullptr) : BooleanDecisions(left, right) {};
    bool checkCondition(Agent* agent, float deltaTimer) override;
};

