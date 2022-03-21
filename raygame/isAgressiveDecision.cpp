#include "isAgressiveDecision.h"
#include "Enemy.h"

bool isAgressiveDecision::checkCondition(Agent* agent, float deltaTimer)
{
    Enemy* enemy = dynamic_cast<Enemy*>(agent);

    if (enemy)
        return enemy->getIsAgressive();
    return false;
}
