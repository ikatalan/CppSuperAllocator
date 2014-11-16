//  Copyright 2008-2014 Idan Katalan
//  Example.cpp: implementation of the CExample class.
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

#include "Example.h"


MemoryExample gExampleMemory;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

static int item = 0;

CExample::CExample()
{
	this->items = item++;
}

CExample::~CExample()
{
}

void* CExample::operator new (unsigned int _size)
{
	return gExampleMemory.GetFreeItem();
}

void CExample::operator delete(void* _itemToDelete)
{
	CExample* item = (CExample*)_itemToDelete;

	gExampleMemory.RemoveItem(item);
}
