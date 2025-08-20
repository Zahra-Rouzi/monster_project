#ifndef PLAYER_H
#define PLAYER_H
#include <Qstring>
#include <agent.h>
#include <tile.h>
#include <mainpage.h>
#include <startpage.h>
using namespace std;

class Player
{
    friend class MainPage;
    friend class Agent;
    friend class startPage;
    friend class SelectButton;
    friend class tile;
public:
    Player(QString n, int c);
    void addAgent(Agent *a);
    QVector<Agent *> getPlayerAgents(){return playerAgents;}
    void removeAgent(Agent* a) {
        playerAgents.removeOne(a);
        countAgent--;
    }
    void setCount(int m){ countAgent-=m;}
    int  getCountAgent(){return countAgent;}
    QString getName(){return name;}

private:
    QString name;
    int countAgent;
    QVector<Agent *> playerAgents;
};

extern Player player1, player2, *currentPlayer;
#endif // PLAYER_H
