#pragma once

#include <BWAPI.h>
#include <set>
//#include "Gerente.h"


class Unidade{
public:

	BWAPI::Unit *unit;
	BWAPI::UnitCommand comando;
	std::map<BWAPI::Unit*, Unidade*> *mapa;
	int index;
	bool fow;

	Unidade(BWAPI::Unit *unit, int index, std::map<BWAPI::Unit*, Unidade*> *m, bool fog);

	BWAPI::UnitCommand getComando();

	std::set<Unidade*> getMinerals(); 

	std::set<Unidade*> getGeysers();

	std::set<Unidade*> getEnemyUnits();

	std::set<Unidade*> getAllyUnits();

	bool isEnemy(Unidade* target);

	bool isAlly(Unidade* target);

	int minerals();

	int gas();

	int supplyTotal();

	int supplyUsed();

	std::set<Unidade*> filtrar(std::set<Unidade*> conjunto);

	bool checar(BWAPI::UnitCommand comando);

	bool attack(BWAPI::Position target);

    bool attack(Unidade* target);

    bool build(BWAPI::TilePosition target, BWAPI::UnitType type);

    bool buildAddon(BWAPI::UnitType type); 

	bool train(BWAPI::UnitType type); 

	bool morph(BWAPI::UnitType type);

	bool research(BWAPI::TechType tech);

	bool upgrade(BWAPI::UpgradeType upgrade);

	bool setRallyPoint(BWAPI::Position target);

	bool setRallyPoint(Unidade* target); 

	bool move(BWAPI::Position P);

	bool patrol(BWAPI::Position target);

	bool holdPosition();

	bool stop();

	bool follow(Unidade* target);

	bool gather(Unidade* target);

	bool returnCargo();

	bool repair(Unidade* target); 

	bool burrow();

	bool unburrow();
	
	bool cloak();
	
	bool decloak();
	
	bool siege();
	
	bool unsiege();
	
	bool lift();
	
	bool land(BWAPI::TilePosition target);
	
	bool load(Unidade* target);
	
	bool unload(Unidade* target);
	
	bool unloadAll();
	
	bool unloadAll(BWAPI::Position target); 
	
	bool rightClick(Unidade *target);

	bool rightClick(BWAPI::Position target);

	bool haltConstruction();
	
	bool cancelConstruction();
	
	bool cancelAddon();
	
	bool cancelTrain(int slot = -2);
	
	bool cancelMorph();
	
	bool cancelResearch();
	
	bool cancelUpgrade();
	
	bool useTech(BWAPI::TechType tech);
	
	bool useTech(BWAPI::TechType tech, BWAPI::Position target);
	
	bool useTech(BWAPI::TechType tech, Unidade* target);

	bool checkNovoTurno();

	bool isInGame();

	bool isUnderAttack();

	//BWAPI::Player* getPlayer();
	
	BWAPI::UnitType getType();

	BWAPI::Position getPosition();

	BWAPI::TilePosition getTilePosition();

	double getAngle();

	double getVelocityX();

	double getVelocityY();

	int getHitPoints();

	int getShields();

	int getEnergy();

	int getResources();

	int getResourceGroup();

	int getDistance(Unidade* target);

	int getDistance(BWAPI::Position target);

	bool hasPath(Unidade* target);

	bool hasPath(BWAPI::Position target);

	int getLastCommandFrame();

	//BWAPI::UnitCommand getLastCommand();

	int getUpgradeLevel(BWAPI::UpgradeType upgrade);

	BWAPI::UnitType getInitialType();

	BWAPI::Position getInitialPosition();

	BWAPI::TilePosition getInitialTilePosition();

	int getInitialHitPoints();

	int getInitialResources();

	int getKillCount();

	int getAcidSporeCount();

	int getInterceptorCount();

	int getScarabCount();

	int getSpiderMineCount();

	int getGroundWeaponCooldown();

	int getAirWeaponCooldown();

	int getSpellCooldown();

	int getDefenseMatrixPoints();

	int getDefenseMatrixTimer();

	int getEnsnareTimer();

	int getIrradiateTimer();

	int getLockdownTimer();

	int getMaelstromTimer();

	int getOrderTimer();

	int getPlagueTimer();

	int getRemoveTimer();

	int getStasisTimer();

	int getStimTimer();

	BWAPI::UnitType getBuildType();

	std::list<BWAPI::UnitType> getTrainingQueue();

	BWAPI::TechType getTech();

	BWAPI::UpgradeType getUpgrade();

	int getRemainingBuildTime();

	int getRemainingTrainTime();

	int getRemainingResearchTime();

	int getRemainingUpgradeTime();

	Unidade* getBuildUnit();

	std::set<Unidade*> getUnitsInRadius(int radius);

	std::set<Unidade*> getUnitsInWeaponRange(BWAPI::WeaponType weapon);

	Unidade* getTarget();

	BWAPI::Position getTargetPosition();

	BWAPI::Order getOrder();

	Unidade* getOrderTarget();

	BWAPI::Order getSecondaryOrder();

	BWAPI::Position getRallyPosition();

	Unidade* getRallyUnit();

	Unidade* getAddon();

	Unidade* getNydusExit();

	Unidade* getPowerUp();

	Unidade* getTransport();

	std::set<Unidade*> getLoadedUnits();

	Unidade* getCarrier();

	std::set<Unidade*> getInterceptors();

	Unidade* getHatchery();

	std::set<Unidade*> getLarva();

	bool exists();

	bool hasNuke();

	bool isAccelerating();

	bool isAttacking();

	bool isAttackFrame();

	bool isBeingConstructed();

	bool isBeingGathered();

	bool isBeingHealed();

	bool isBlind();

	bool isBraking();

	bool isBurrowed();

	bool isCarryingGas();

	bool isCarryingMinerals();

	bool isCloaked();

	bool isCompleted();

	bool isConstructing();

	bool isDefenseMatrixed();

	bool isDetected();

	bool isEnsnared();

	bool isFollowing();

	bool isGatheringGas();

	bool isGatheringMinerals();

	bool isHallucination();

	bool isHoldingPosition();

	bool isIdle();

	bool isInterruptible();

	bool isInvincible();

	bool isInWeaponRange(Unidade *target);

	bool isIrradiated();

	bool isLifted();

	bool isLoaded();

	bool isLockedDown();

	bool isMaelstrommed();

	bool isMorphing();

	bool isMoving();

	bool isParasited();

	bool isPatrolling();

	bool isPlagued();

	bool isRepairing();

	bool isResearching();

	bool isSelected();

	bool isSieged();

	bool isStartingAttack();

	bool isStasised();

	bool isStimmed();

	bool isStuck();

	bool isTraining();

	bool isUnderStorm();

	bool isUnderDarkSwarm();

	bool isUnderDisruptionWeb();

	bool isUnpowered();

	bool isUpgrading();

	bool isVisible();

};