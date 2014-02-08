#pragma once
class Behaviour
{
public:
	Behaviour(void);
	virtual ~Behaviour(void);
	virtual void execute() = 0;
};

