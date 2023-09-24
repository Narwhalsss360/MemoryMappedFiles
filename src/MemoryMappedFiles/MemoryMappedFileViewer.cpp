#include "MemoryMappedFileViewer.h"

namespace MemoryMappedFiles
{
	using std::string;


	MemoryMappedFileViewer::MemoryMappedFileViewer(string objectName, size_t size)
		: mapHandle(nullptr), objectName(objectName), size(size), currentView(nullptr)
	{
		mapHandle = OpenFileMappingA(FILE_MAP_ALL_ACCESS, FALSE, objectName.c_str());
	}

	void* MemoryMappedFileViewer::view()
	{
		if (!currentView)
			currentView = MapViewOfFile(mapHandle, FILE_MAP_ALL_ACCESS, 0, 0, size);
		return currentView;
	}

	void MemoryMappedFileViewer::close()
	{
		UnmapViewOfFile(currentView);

		if (mapHandle == INVALID_HANDLE_VALUE || mapHandle == NULL)
			return;
		CloseHandle(mapHandle);
	}

	MemoryMappedFileViewer::~MemoryMappedFileViewer()
	{
		close();
	}
}