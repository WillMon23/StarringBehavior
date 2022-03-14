#pragma once
#include "Decision.h"
/// <summary>
/// A decision that has two children attach
/// </summary>
class BooleanDecisions :
    public Decision
{
public:

    /// <param name="leftChild">The left child of this node</param>
    /// <param name="rightChild">The right child of this node</param>
    BooleanDecisions(Decision* leftChild = nullptr, Decision* rightChild = nullptr);
    /// <summary>
    /// Checks the condition and the transition to a diffrent based on the return  value
    /// </summary>
    /// <param name="agent">The agent that this decision tree is attached to</param>
    /// <param name="deltaTime">The amount of the between frames</param>
    virtual void makeDecision(Agent* agent, float deltaTime) override;

    /// <summary>
    /// Checks if a certin condition has been met and returns the result
    /// </summary>
    /// <param name="agent"></param>
    /// <param name="deltaTime"></param>
    /// <returns></returns>
    virtual bool checkCondition(Agent* agent, float deltaTime) { return false; };
    

private:
    Decision* m_no;
    Decision* m_yes;
};

