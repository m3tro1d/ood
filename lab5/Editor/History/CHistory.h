#pragma once

#include "../Command/ICommand.h"
#include "../Document/IHistory.h"
#include <vector>

class CHistory : public IHistory
{
public:
	bool CanUndo() const override;
	void Undo() override;

	bool CanRedo() const override;
	void Redo() override;

	void AddAndExecuteCommand(ICommandPtr&& command) override;

private:
	std::vector<ICommandPtr> m_commands;
	std::size_t m_currentCommandIndex = 0;
};
