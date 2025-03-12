#ifndef AICONTROLLER_H
#define AICONTROLLER_H

class Enemy;
class Player;

class AIController {
public:
    AIController();
    void makeMove(Enemy& enemy, Player& player);
};

#endif
