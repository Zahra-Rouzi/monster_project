#include "player.h"
#include "QString"

Player::Player(QString n, int cnt = 0): name(n), countAgent(cnt) {}

void Player::addAgent(Agent *a){
    playerAgents.push_back(a);
}

Player player1(""), player2(""), currentPlayer("");
