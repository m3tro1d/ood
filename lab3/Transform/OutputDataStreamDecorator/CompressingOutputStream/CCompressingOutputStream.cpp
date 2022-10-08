#include "CCompressingOutputStream.h"

CCompressingOutputStream::CCompressingOutputStream(IOutputDataStreamPtr&& stream)
	: m_stream(std::move(stream))
{
}

CCompressingOutputStream::~CCompressingOutputStream()
{
	Flush();
}

void CCompressingOutputStream::WriteByte(std::uint8_t data)
{
	if (m_currentBlock.size == 0)
	{
		m_currentBlock = {
			.byte = data,
			.size = 1,
		};
		return;
	}

	if (m_currentBlock.byte == data)
	{
		++m_currentBlock.size;
		return;
	}

	Flush();
	m_currentBlock = {
		.byte = data,
		.size = 1,
	};
}

void CCompressingOutputStream::WriteBlock(const void* srcData, std::streamsize size)
{
	auto bytes = static_cast<std::uint8_t const*>(srcData);

	for (std::streamsize i = 0; i < size; ++i)
	{
		WriteByte(*(bytes + i));
	}
}

void CCompressingOutputStream::Flush()
{
	m_stream->WriteByte(m_currentBlock.size);
	m_stream->WriteByte(m_currentBlock.byte);
}
