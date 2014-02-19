#pragma once

#include "UnitBehaviour.h"
#include "Unit.h"
#include "Ressource.h"

#define UNIT_GATHERER_MESSAGE ">			[INFO] Unit is a gatherer."

class GathererBehaviour : public UnitBehaviour
{

private:
	RessourceType m_FocusedRessource;
public:
	GathererBehaviour(Unit * unit);
	~GathererBehaviour(void);
	virtual void execute();

	const RessourceType & getFocusedRessource() const;
	void setRessource(RessourceType ressourceType);
};

