#pragma once

#define NOMINMAX //windows.h defines macros named min and max and to avoid a conflict with std::numeric_limits<double>::max() you have to define this macro

#include "UnitBehaviour.h"
#include "Unit.h"
#include "Ressource.h"
#include "MersenneTwister.h"

#define UNIT_GATHERER_MESSAGE ">			[INFO] Unit is a gatherer."

enum RessourceType;

class GathererBehaviour : public UnitBehaviour
{

private:
	RessourceType m_FocusedRessource;
	bool m_bRessourceFound;
	static const unsigned int m_strikesNumber;
	static MersenneTwister m_Generator;

	void findPathToRessource(void);
	void findRandomPath(void);

public:
	GathererBehaviour(Unit * unit, RessourceType focusedRessource);
	~GathererBehaviour(void);
	virtual void execute();

	const RessourceType & getFocusedRessource() const;
	void setFocusedRessource(RessourceType ressourceType);
};

