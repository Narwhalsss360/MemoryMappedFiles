#include "MemoryMappedFileException.h"

namespace MemoryMappedFiles
{
	MemoryMappedFileException::MemoryMappedFileException(std::string message)
		: std::exception(message.c_str())
	{
	}
}