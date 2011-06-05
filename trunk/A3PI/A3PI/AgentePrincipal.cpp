#define WIN32_LEAN_AND_MEAN	

#include "AgentePrincipal.h"

#include <BWAPI.h>
#include "Gerente.h"
#include <Windows.h>


DWORD WINAPI threadEvento(LPVOID ev){
	Evento *evento = (Evento*) ev;
	if(evento->tipo == 0){
		evento->agtPrinc->InicioDePartida();
	}else{
		evento->agtPrinc->UnidadeCriada(evento->unidade);
	}
	delete evento;
	return 0;
}

BOOL AgentePrincipal::DllMain(DWORD  ul_reason_for_call){
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
    BWAPI::BWAPI_init();
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

void *AgentePrincipal::NewAiModule(void * game){

	BWAPI::Broodwar = (BWAPI::Game* )game;
	return new Gerente();
}



void AgentePrincipal::IniciarEmModoTeste(){
#if _MODO_TESTE_
	Gerente::IniciarEmModoTeste();
#endif
}

void AgentePrincipal::onEnd(bool isWinner)
{

}

void AgentePrincipal::InicioDePartida()
{

}

void AgentePrincipal::UnidadeCriada(Unidade* unidade){
}

void AgentePrincipal::DormirAteFinalDoTurno(){
	Gerente::DormirAteFinalDoTurno();
}