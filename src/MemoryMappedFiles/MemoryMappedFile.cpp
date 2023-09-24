#include "MemoryMappedFile.h"

namespace MemoryMappedFiles
{
	using std::string;

	MemoryMappedFile::MemoryMappedFile(string filePath, string objectName, size_t size)
		: fileHandle(nullptr), mapHandle(nullptr), filePath(filePath), objectName(objectName), size(size), currentView(nullptr)
	{
		fileHandle = CreateFileA(filePath.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		mapHandle = CreateFileMappingA(fileHandle, NULL, PAGE_READWRITE, 0, size, objectName.c_str());
	}

	void* MemoryMappedFile::view()
	{
		if (!currentView)
			currentView = MapViewOfFile(mapHandle, FILE_MAP_ALL_ACCESS, 0, 0, size);
		return currentView;
	}

	void MemoryMappedFile::close()
	{
		if (fileHandle == INVALID_HANDLE_VALUE || fileHandle == NULL)
			return;
		UnmapViewOfFile(currentView);
		CloseHandle(fileHandle);

		if (mapHandle == INVALID_HANDLE_VALUE || mapHandle == NULL)
			return;
		CloseHandle(mapHandle);

		DeleteFileA(filePath.c_str());
	}

	MemoryMappedFile::~MemoryMappedFile()
	{
		close();
	}
}