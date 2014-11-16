//  Copyright 2008-2014 Idan Katalan
//  MemoryAllocator.h: interface for the CSuperAllocator class. 
//  This file is part of CppSuperAllocator.

//   CppSuperAllocator is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.

//   CppSuperAllocator is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.

//   You should have received a copy of the GNU General Public License
//   along with CppSuperAllocator.  If not, see <http://www.gnu.org/licenses/>.
//
//   Developed By: Idan Katalan ikatalan at gmail dot com
//
//////////////////////////////////////////////////////////////////////
#include <Windows.h>

BOOL WINAPI DllMain(
  __in  HINSTANCE hinstDLL,
  __in  DWORD fdwReason,
  __in  LPVOID lpvReserved
)
{
	switch (fdwReason )
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:	
		break;
	};
}
