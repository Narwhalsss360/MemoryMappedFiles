#include <iostream>
#include "MemoryMappedFiles.h"

#define OBJ_NAME "MyMapping"

using namespace MemoryMappedFiles;

int main()
{
	MemoryMappedFile mapping = MemoryMappedFile("D:\\Users\\sandr\\mapping.dat", OBJ_NAME, sizeof(int));
	void* mapperView = mapping.view();
	int& mapperInt = *(int*)mapperView;

	MemoryMappedFileViewer viewer = MemoryMappedFileViewer(OBJ_NAME, sizeof(int));
	void* viewerView = viewer.view();
	int& viewerInt = *(int*)viewerView;

	mapperInt = 0xDEADBEEF;
	if (mapperInt != viewerInt)
	{
		std::cout << "Values were not the same!\n";
		return 1;
	}

	std::cout << "Exiting";
}