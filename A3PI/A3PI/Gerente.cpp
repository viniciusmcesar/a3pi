#include "Gerente.h"
#include "Unidade.h"
#include <sys/timeb.h>

using namespace BWAPI;

#if _MODO_COMPETICAO_
	namespace BWAPI { Game* Broodwar; }
#endif

AgentePrincipal *agentePrincipal;
Gerente *gerente;
long long inicioFrameTime = 0;

long long getCurrentTime(){
       struct timeb tmb;
       ftime(&tmb);
       return (tmb.time)*1000LL + tmb.millitm;
} 

void Gerente::onStart(){
	for(int i = 0; i<3000;i++)
		unidades[i] = NULL;
	mapa.clear();
	qntUnidades = 0;
	int ent = 0;
	freopen("./conf.txt", "r", stdin); 
	if(scanf("%d", &ent) != 1) Broodwar->printf("(conf.txt nao encontrado ou com parametro invalido)\n");
	fclose(stdin);
	FOG_OF_WAR = ent;
	Broodwar->setLocalSpeed(DURACAO_TURNO);
	Broodwar->sendText("Iniciando o A3PI!");
  Broodwar->enableFlag(Flag::UserInput);
  if(!FOG_OF_WAR){
	  Broodwar->enableFlag(Flag::CompleteMapInformation);
	  Broodwar->sendText("black sheep wall");
  }
  BWTA::readMap();
	for(std::set<Unit*>::const_iterator it = Broodwar->getMinerals().begin(); it != Broodwar->getMinerals().end(); it++){
		Unidade *u = new Unidade(*it,qntUnidades, &mapa, FOG_OF_WAR);
		mapa[*it] = u;
		unidades[qntUnidades++] = u;
	}
   Evento *inicio = new Evento();
   
   /*for(std::set<Unit*>::const_iterator i=Broodwar->self()->getUnits().begin();i!=Broodwar->self()->getUnits().end();i++)
   {
	   Unidade *u = new Unidade( (*i),qntUnidades );
	   unidades[qntUnidades++] = u;
		inicio->unidades.push_back(u);
   }*/
  
   inicio->tipo = 0;
   inicio->agtPrinc = agentePrincipal;

   CreateThread(NULL,0,threadEvento,(void*)inicio,0,NULL);
}
void Gerente::onEnd(bool isWinner){
	agentePrincipal->onEnd(isWinner);
}
void Gerente::onFrame(){
	if(Broodwar->getFrameCount() <1)
		return;

		for(int i= 0; i<qntUnidades;i ++){
			if(unidades[i] != NULL && unidades[i]->unit->getPlayer() == Broodwar->self()){
				BWAPI::UnitCommand cm = unidades[i]->getComando();
				if(cm.getType() != BWAPI::UnitCommandTypes::None){
					bool x = unidades[i]->unit->issueCommand(cm);
				}
			}
		}

}
void Gerente::onSendText(std::string text){ Broodwar->sendText("%s", text.c_str());}
void Gerente::onReceiveText(BWAPI::Player* player, std::string text){}
void Gerente::onPlayerLeft(BWAPI::Player* player){}
void Gerente::onNukeDetect(BWAPI::Position target){}
void Gerente::onUnitDiscover(BWAPI::Unit* unit){}
void Gerente::onUnitEvade(BWAPI::Unit* unit){}
void Gerente::onUnitShow(BWAPI::Unit* unit){}
void Gerente::onUnitHide(BWAPI::Unit* unit){}
void Gerente::onUnitCreate(BWAPI::Unit* unit){
	Unidade *u = new Unidade(unit,qntUnidades, &mapa, FOG_OF_WAR);
	mapa[unit] = u;
	unidades[qntUnidades++] = u;
	//manter todas as unidades, mas apenas repassar as do jogador
	if(unit->getPlayer() == Broodwar->self()){
		Evento *criado = new Evento();
		criado->agtPrinc = agentePrincipal;
		criado->tipo = 1;
		criado->unidade = u;
		CreateThread(NULL,0,threadEvento,(void*)criado,0,NULL);
	}
}
void Gerente::onUnitDestroy(BWAPI::Unit* unit){}
void Gerente::onUnitMorph(BWAPI::Unit* unit){}
void Gerente::onUnitRenegade(BWAPI::Unit* unit){}
void Gerente::onSaveGame(std::string gameName){}

void Gerente::DormirAteFinalDoTurno(){
	//int tempo = (int)(getCurrentTime() - inicioFrameTime);
	//int temop2 = max(1, (int)(DURACAO_TURNO - tempo));
	//printf("%d\n", temop2);
	//Sleep(temop2);
}