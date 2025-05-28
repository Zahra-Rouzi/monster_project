#ifndef PLAYER_H
#define PLAYER_H
#include <Qstring>
#include <agent.h>
#include <mainpage.h>
#include <startpage.h>
using namespace std;

class Player
{
    friend class MainPage;
    friend class startPage;
    friend class SelectButton;
public:
    Player(QString n, int c);
    void addAgent(Agent *a);
private:
    QString name;
    int countAgent;
    vector<Agent *> playerAgents;
};

extern Player player1, player2, currentPlayer;
#endif // PLAYER_H
