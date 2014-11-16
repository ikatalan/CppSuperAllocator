// MemoryAllocator.h: interface for the CSuperAllocator class. 
//
// Developed By: Idan Katalan
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SUPERALLOCATOR_H__6FDECF4B_88AD_4BCD_8A13_2EA7219BF1F3__INCLUDED_)
#define AFX_SUPERALLOCATOR_H__6FDECF4B_88AD_4BCD_8A13_2EA7219BF1F3__INCLUDED_

#include <string.h>

template <class T, int BufferSize>
class CSuperAllocator  
{
public:

	////Constructs / Destructors.
	CSuperAllocator();
	virtual ~CSuperAllocator();

	////Public Methods.
	int		InsertItem	(T*		_itemToInsert	);
	bool	RemoveItem	(int	_place			);
	bool	RemoveItem	(T*	_itemToDelete		);
	T*		GetFreeItem	(						);

	////Operator Overloading.
	const T&	operator []		(const int		&_place);
	T&			operator []		(int			&_place);		
private:
	
	////Private Properties
	T				memory  [BufferSize];
	unsigned short	indices [BufferSize];

	int mBufferSize;
};



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//							CSuperAllocator
//							----------------
//
//	Description: Initializes the memory with designated pointers.
//
//	Parameters:
//			None.
//
//////////////////////////////////////////////////////////////////////////////
template <class T, int BufferSize>
CSuperAllocator<T, BufferSize >::CSuperAllocator()
{
	for (int i = 0; i < BufferSize - 1; i++)
	{
		this->indices[i] = i+1;
	}

	this->indices[BufferSize - 1] = -1;
	
}

template <class T, int BufferSize>
CSuperAllocator<T, BufferSize>::~CSuperAllocator()
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
int CSuperAllocator<T, BufferSize>::InsertItem (T* _itemToInsert)
{
	int returnValue = this->indices[0];
	if (returnValue != -1)
	{
		this->indices[0] = this->indices[returnValue];
		if (_itemToInsert != NULL)
		{
			memcpy(&this->memory[returnValue], _itemToInsert, sizeof (T) );
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
bool CSuperAllocator<T, BufferSize>::RemoveItem(int _place)
{
	if (_place < BufferSize && _place > 0)
	{
		//memcpy(&this->memory[_place], &this->memory[0], sizeof (T) );
		this->memory[_place] =  this->memory[0];
		this->indices[_place] = this->indices[0];

		this->indices[0] = _place;
		return (true);
	}
	return (false);
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
bool 	CSuperAllocator<T, BufferSize>::RemoveItem	(T*	_itemToDelete)
{
	int position = (_itemToDelete - this->memory) ;

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
T*	CSuperAllocator<T, BufferSize>::GetFreeItem	()
{
	T* dummy = NULL;

	int pos = this->InsertItem(dummy);

	return (&this->memory[pos]);
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
const T& CSuperAllocator<T, BufferSize>::operator[](const int &_place)
{
	return ( this->memory[_place]);
}


template <class T, int BufferSize>
T& CSuperAllocator<T, BufferSize>::operator[](int &_place)
{
	return ( this->memory[_place]);
}


#endif // !defined(AFX_MEMORYALLOCATOR_H__6FDECF4B_88AD_4BCD_8A13_2EA7219BF1F3__INCLUDED_)