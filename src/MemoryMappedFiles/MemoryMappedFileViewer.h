#pragma once
#include <Windows.h>
#include <string>

namespace MemoryMappedFiles
{
	class MemoryMappedFileViewer
	{
	public:
		MemoryMappedFileViewer(std::string objectName, size_t size);

		void* view();

		void close();

		~MemoryMappedFileViewer();

	private:
		HANDLE mapHandle;
		std::string objectName;
		size_t size;
		void* currentView;
	};
}