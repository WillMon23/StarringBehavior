#pragma once
class Agent;

/// <summary>
/// Abtract Class for all decisions
/// </summary>
class Decision
{
public:
	virtual void makeDecision(Agent* agent, float deltaTime) = 0;
};

