#pragma once
#include <BWAPI.h>
#include <BWAPI\Client.h>
#include <BWTA.h>
#include <windows.h>
#include <map>

#include "AgentePrincipal.h"

#define DURACAO_TURNO 20

class Gerente;

extern AgentePrincipal *agentePrincipal; 
extern Gerente *gerente; //usado para Modo teste

using namespace BWAPI;


long long getCurrentTime();


extern long long inicioFrameTime;

class Gerente : public BWAPI::AIModule{

public:

	int qntUnidades;
	bool FOG_OF_WAR;
	Unidade *unidades[3000];
	std::map<BWAPI::Unit*, Unidade*> mapa;
	//AgentePrincipal *agentePrincipal;

	
	virtual void onStart();
	virtual void onEnd(bool isWinner);
	virtual void onFrame();
	virtual void onSendText(std::string text);
	virtual void onReceiveText(BWAPI::Player* player, std::string text);
	virtual void onPlayerLeft(BWAPI::Player* player);
	virtual void onNukeDetect(BWAPI::Position target);
	virtual void onUnitDiscover(BWAPI::Unit* unit);
	virtual void onUnitEvade(BWAPI::Unit* unit);
	virtual void onUnitShow(BWAPI::Unit* unit);
	virtual void onUnitHide(BWAPI::Unit* unit);
	virtual void onUnitCreate(BWAPI::Unit* unit);
	virtual void onUnitDestroy(BWAPI::Unit* unit);
	virtual void onUnitMorph(BWAPI::Unit* unit);
	virtual void onUnitRenegade(BWAPI::Unit* unit);
	virtual void onSaveGame(std::string gameName);

	static void DormirAteFinalDoTurno();

#if _MODO_TESTE_
	static void reconnect()
	{
		while(!BWAPI::BWAPIClient.connect())
		{
			Sleep(1000);
		}
	}

	static void IniciarEmModoTeste(){
		gerente = new Gerente();
		
		BWAPI::BWAPI_init();
		printf("Connecting...\n");
		reconnect();
		while(true)
		{
			printf("waiting to enter match\n");

			while (!BWAPI::Broodwar->isInGame())
			{
				BWAPI::BWAPIClient.update();
				if (!BWAPI::BWAPIClient.isConnected())
				{
					printf("Reconnecting...\n");
					reconnect();
				}
			}
			printf("starting match!\n");

			gerente->onStart();

			while(BWAPI::Broodwar->isInGame())
			{
				gameLoop();

				BWAPI::BWAPIClient.update();
				if (!BWAPI::BWAPIClient.isConnected())
				{
					printf("Reconnecting...\n");
					reconnect();
				}
			}
			printf("Game ended\n");
		}
		system("pause");
	
	}

static void gameLoop(){

	for(std::list<Event>::iterator e=Broodwar->getEvents().begin();e!=BWAPI::Broodwar->getEvents().end();e++)
	{
		switch(e->getType())
		{
		case EventType::MatchEnd:
			gerente->onEnd(e->isWinner());
			if (e->isWinner())
				printf("I won the game\n");
			else
				printf("I didn't win the game\n");
			break;
		case EventType::SendText:
			gerente->onSendText(e->getText());
			break;
		case EventType::ReceiveText:
			break;
		case EventType::PlayerLeft:
			break;
		case EventType::NukeDetect:
			break;
		case EventType::UnitDiscover:
			gerente->onUnitDiscover(e->getUnit());
			break;
		case EventType::UnitEvade:
			break;
		case EventType::UnitShow:
			break;
		case EventType::UnitHide:
			break;
		case EventType::UnitCreate:
			break;
		case EventType::UnitDestroy:
			break;
		case EventType::UnitMorph:
			break;
		case EventType::UnitRenegade:
			break;
		case EventType::SaveGame:
			break;
		}
	}
	
	gerente->onFrame();

}
#endif
};