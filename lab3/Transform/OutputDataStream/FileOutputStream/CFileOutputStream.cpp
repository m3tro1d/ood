#include "CFileOutputStream.h"

CFileOutputStream::CFileOutputStream(std::string const& filename)
	: m_file(filename, std::ios::out | std::ios::binary)
{
	if (!m_file.is_open())
	{
		throw std::runtime_error("failed to open file for writing");
	}
}

void CFileOutputStream::WriteByte(std::uint8_t data)
{
	if (!m_file.write(reinterpret_cast<char const*>(&data), 1))
	{
		throw std::ios_base::failure("failed to write to file");
	}
}

void CFileOutputStream::WriteBlock(void const* srcData, std::streamsize size)
{
	if (!m_file.write(static_cast<char const*>(srcData), size))
	{
		throw std::ios_base::failure("failed to write to file");
	}
}
