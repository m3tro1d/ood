#pragma once

#include "../../OutputDataStreamDecorator/CompressingOutputStream/CCompressingOutputStream.h"
#include "../CInputDataStreamDecorator.h"

class CDecompressingInputStream : public CInputDataStreamDecorator
{
public:
	explicit CDecompressingInputStream(IInputDataStreamPtr&& stream);

	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;

private:
	Block m_currentBlock;
};
