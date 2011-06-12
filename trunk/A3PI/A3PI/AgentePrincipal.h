#pragma once

#include <Windows.h>
#include "Unidade.h"
#include <vector>

class AgentePrincipal;

struct Evento{
	int tipo;
	Unidade *unidade;
	AgentePrincipal *agtPrinc;
};


DWORD WINAPI threadEvento(LPVOID ev);


class AgentePrincipal{
public:
	
	static BOOL DllMain(DWORD  ul_reason_for_call);

	static void *NewAiModule(void* game);

	static void IniciarEmModoTeste();

	static void DormirAteFinalDoTurno();

	static int mapHeight();
	
	static int mapWidth();

	static bool isWalkable(int x, int y);

	virtual void onEnd(bool isWinner) = 0;

	virtual void InicioDePartida() = 0;

	virtual void UnidadeCriada(Unidade* unidade) = 0;

};