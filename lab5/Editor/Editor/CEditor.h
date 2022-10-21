#pragma once

#include "../Document/IDocument.h"
#include "../History/CHistory.h"
#include "../Saver/ISaver.h"
#include <functional>
#include <iostream>

class CEditor
{
public:
	CEditor(std::istream& input, std::ostream& output, ISaver& saver);

	void Start();

private:
	using CommandHandler = std::function<void(std::istream&)>;

	CommandHandler GetCommandHandler(std::string const& commandName);

	void InsertParagraph(std::istream& input);
	void InsertImage(std::istream& input);

	void SetTitle(std::istream& input);

	void List();

	void ReplaceText(std::istream& input);
	void ResizeImage(std::istream& input);

	void DeleteItem(std::istream& input);

	void Help();

	void Undo();
	void Redo();

	void Save(std::istream& input);

	static std::optional<std::size_t> GetOptionalIndex(std::string const& value);
	static void TrimString(std::string& str);

	std::istream& m_input;
	std::ostream& m_output;

	CHistory m_history;
	std::unique_ptr<ISaver> m_saver;
	std::unique_ptr<IDocument> m_document;
};
