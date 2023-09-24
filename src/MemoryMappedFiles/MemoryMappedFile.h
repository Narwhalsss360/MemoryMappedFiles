#pragma once
#include <Windows.h>
#include <string>

namespace MemoryMappedFiles
{
	class MemoryMappedFile
	{
	public:
		MemoryMappedFile(std::string filePath, std::string objectName, size_t size);

		void* view();

		~MemoryMappedFile();

		void close();

	private:
		HANDLE fileHandle;
		HANDLE mapHandle;
		std::string filePath;
		std::string objectName;
		size_t size;
		void* currentView;
	};
}