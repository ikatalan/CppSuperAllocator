//  Copyright 2008-2014 Idan Katalan
//  main.cpp: main file
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
//   contact: ikatalan at gmail dot com
//
//////////////////////////////////////////////////////////////////////

#include "Example.h"
#include "SuperAllocator.hpp"

#include <time.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>

int		TestAllocator ();

int main()
{
	TestAllocator();
	return 0;
}

int TestAllocator ()
{
	SYSTEMTIME x, y;
	DWORD x1,y1;

	CExample* temps[100000];

	GetSystemTime(&x);
	x1 = GetTickCount ();

	for ( int d = 0; d < 20; ++d )
	{

	for (int i = 0; i < 100000; i++)
	{
		temps[i]  = new CExample();
	}

	for (int i = 0; i < 100000; i++)
	{
		delete temps[i];
	}
	}
	GetSystemTime(&y);
	y1 = GetTickCount ();

	printf("Before :");
	printf("%d/%d/%d %d:%d:%d:%d\n",x.wDay, x.wMonth, x.wYear, x.wHour, x.wMinute, x.wSecond, x.wMilliseconds);
	printf("After :");
	printf("%d/%d/%d %d:%d:%d:%d\n",y.wDay, y.wMonth, y.wYear, y.wHour, y.wMinute, y.wSecond, x.wMilliseconds);
	
	printf ("Diffrence: %d\n",y1-x1);
	
	printf ("");
	return (0);
}

void  operator delete(void *p)
{
    std::cout << "Here is delete\n";
    free(p);
}
 
void *operator new(size_t size)
{
    std::cout << "Here is new:\n";
 
    void * p = malloc(size);
    if (p == 0) {
        throw std::bad_alloc();
    }
    return p;
}