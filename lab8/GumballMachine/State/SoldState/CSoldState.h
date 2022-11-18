#pragma once

#include "../IGumballMachine.h"
#include "../IState.h"

class CSoldState : public IState
{
public:
	explicit CSoldState(IGumballMachine& gumballMachine);

	void InsertQuarter() override;
	void EjectQuarters() override;
	void TurnCrank() override;
	void Dispense() override;
	void Refill(unsigned int count) override;

	std::string ToString() const override;

private:
	IGumballMachine& m_gumballMachine;
};
