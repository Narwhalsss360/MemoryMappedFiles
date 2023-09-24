#pragma once
#include <exception>
#include <string>

namespace MemoryMappedFiles
{
	class MemoryMappedFileException : public std::exception
	{
	public:
		MemoryMappedFileException(std::string message = "");
	};
}