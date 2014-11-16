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

#if !defined(AFX_MEMORYALLOCATOR_H__6FDECF4B_88AD_4BCD_8A13_2EA7219BF1F3__INCLUDED_)
#define AFX_MEMORYALLOCATOR_H__6FDECF4B_88AD_4BCD_8A13_2EA7219BF1F3__INCLUDED_

#include <string.h>

template <class T, int BufferSize>
class CMemoryAllocator  
{
public:

	////Item
	class Item
	{
		friend class CMemoryAllocator<T,BufferSize>;
		public:			
			T				mBuffer;
		private:
			unsigned short	mPointer;
	};
	

	////PublicConstructs / Destructors.
	CMemoryAllocator();
	virtual ~CMemoryAllocator();

	////Public Methods.
	int		InsertItem	(T*		_itemToInsert	);
	bool	RemoveItem	(int	_place			);
	bool	RemoveItem	(Item*	_itemToDelete	);
	Item*	GetItem		(int	_place			);
	Item*	GetFreeItem	(						);

	////Operator Overloading.
	const Item&	operator []		(const int		&_place);
	Item&		operator []		(int			&_place);		
private:
	
	////Private Properties
	Item	memory [BufferSize];

	int mBufferSize;

};



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//							CMemoryAllocator
//							----------------
//
//	Description: Initializes the memory with designated pointers.
//
//	Parameters:
//			None.
//
//////////////////////////////////////////////////////////////////////////////
template <class T, int BufferSize>
CMemoryAllocator<T, BufferSize >::CMemoryAllocator()
{
	for (int i = 0; i < BufferSize - 1; i++)
	{
		this->memory[i].mPointer = i+1;
	}
	this->memory[BufferSize - 1].mPointer = -1;
}

template <class T, int BufferSize>
CMemoryAllocator<T, BufferSize>::~CMemoryAllocator()
{

}


//////////////////////////////////////////////////////////////////////
// Public Methods
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//								InsertItem
//								----------
//
//	Description: This function inserts a pre-defined item to the memory.
//
//	Parameters:
//			_itemToInsert - the item to insert to memory. (In)
//
//	Return Value: The place where the item is stored.
//			
//////////////////////////////////////////////////////////////////////////////
template <class T, int BufferSize>
int CMemoryAllocator<T, BufferSize>::InsertItem (T* _itemToInsert)
{
	int returnValue = this->memory[0].mPointer;
	if (returnValue != -1)
	{
		this->memory[0].mPointer = this->memory[returnValue].mPointer;
		if (_itemToInsert != NULL)
		{
			memcpy(&this->memory[returnValue].mBuffer, _itemToInsert, sizeof (T) );
		}
	}	
	return (returnValue);
}


//////////////////////////////////////////////////////////////////////////////
//								RemoveItem
//								----------
//
//	Description: This function removes an item from the memory.
//
//	Parameters:
//			_place - the place of the item as it was given from the Insert function.
//
//	Return Value:	true if the item was removed.
//					false otherwise.
//			
//////////////////////////////////////////////////////////////////////////////
template <class T, int BufferSize>
bool CMemoryAllocator<T, BufferSize>::RemoveItem(int _place)
{
	if (_place < BufferSize && _place > 0)
	{
		this->memory[_place] = this->memory[0];
		this->memory[0].mPointer = _place;
		return (true);
	}
	return (false);
}


//////////////////////////////////////////////////////////////////////////////
//								GetItem
//								-------
//
//	Description: This function gets the value of an Item.
//
//	Parameters:
//			_place - the place of the item as it was given from the Insert function.
//
//	Return Value:	The item requested.
//			
//////////////////////////////////////////////////////////////////////////////
template <class T, int BufferSize>
typename CMemoryAllocator<T, BufferSize>::Item*		CMemoryAllocator<T, BufferSize>::GetItem		(int _place)
{
	if (_place < BufferSize && _place > 0)
	{
		return (&this->memory[_place]);
	}
	return (NULL);
	
}


//////////////////////////////////////////////////////////////////////////////
//								RemoveItem
//								----------
//
//	Description: This function removes an item from the memory.
//
//	Parameters:
//			_itemToDelete - A pointer to an Item.
//
//	Return Value:	true if the item was removed.
//					false otherwise.
//			
//////////////////////////////////////////////////////////////////////////////
template <class T, int BufferSize>
bool 	CMemoryAllocator<T, BufferSize>::RemoveItem	(Item*	_itemToDelete)
{
	int position = _itemToDelete - this->memory;

	return (this->RemoveItem (position));
}


/////////////////////////////////////////////////////////////////////
//								GetFreeItem
//								-----------
//
//	Description:	Returns a free item.
//
//	Parameters:	None.
//			
//
//	Return Value:	A pointer to place in the memory.
//			
/////////////////////////////////////////////////////////////////////
template <class T, int BufferSize>
typename CMemoryAllocator<T, BufferSize>::Item*	CMemoryAllocator<T, BufferSize>::GetFreeItem	()
{
	T* dummy = NULL;
	Item* returnValue = (&(this->memory[this->memory[0].mPointer]));

	this->InsertItem(dummy);
	
	return (returnValue);
}

//////////////////////////////////////////////////////////////////////////////
//								operator[]
//								----------
//
//	Description: This function gets the value of an Item.
//
//	Parameters:
//			_place - the place of the item as it was given from the Insert function.
//
//	Return Value:	The item requested.
//			
//////////////////////////////////////////////////////////////////////////////
template <class T, int BufferSize>
typename const CMemoryAllocator<T, BufferSize>::Item& CMemoryAllocator<T, BufferSize>::operator[](const int &_place)
{
	return ( this->memory[_place]);
}


template <class T, int BufferSize>
typename CMemoryAllocator<T, BufferSize>::Item& CMemoryAllocator<T, BufferSize>::operator[](int &_place)
{
	return ( this->memory[_place]);
}


#endif // !defined(AFX_MEMORYALLOCATOR_H__6FDECF4B_88AD_4BCD_8A13_2EA7219BF1F3__INCLUDED_)