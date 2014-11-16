//  Copyright 2008-2014 Idan Katalan
//  Example.h: interface for the CExample class.
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

#if !defined(AFX_EXAMPLE_H__36499396_2698_4B45_AE34_BC5BFDA2AE81__INCLUDED_)
#define AFX_EXAMPLE_H__36499396_2698_4B45_AE34_BC5BFDA2AE81__INCLUDED_


#include "SuperAllocator.hpp"


class CExample
{
public:
	CExample();
	virtual ~CExample();

	void* operator new (unsigned int _size);
	void operator delete(void* _itemToDelete);

	int items;

};

typedef CSuperAllocator<CExample,500010> MemoryExample;



#endif // !defined(AFX_EXAMPLE_H__36499396_2698_4B45_AE34_BC5BFDA2AE81__INCLUDED_)
