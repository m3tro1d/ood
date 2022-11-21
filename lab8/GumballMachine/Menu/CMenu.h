#pragma once

#include "../GumballMachine/CGumballMachine.h"
#include <functional>
#include <iostream>

class CMenu
{
public:
	CMenu(std::istream& input, std::ostream& output, CGumballMachine& gumballMachine);

	void Start();

private:
	using CommandHandler = std::function<void(std::istream&)>;

	CommandHandler GetCommandHandler(std::string const& commandName);

	void InsertQuarter();
	void EjectQuarter();
	void TurnCrank();
	void Refill(std::istream& args);

	void Status();
	void Exit();

	std::istream& m_input;
	std::ostream& m_output;

	bool m_running = true;
	CGumballMachine& m_gumballMachine;
};
