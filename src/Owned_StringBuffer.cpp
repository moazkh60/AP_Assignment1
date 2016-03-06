
#include <iostream>
#include "Owned_StringBuffer.h"

Owned_StringBuffer::Owned_StringBuffer()
{
	_strbuf=nullptr;
	_length = 0;
}

Owned_StringBuffer::~Owned_StringBuffer()
{
	delete[] _strbuf;
}

Owned_StringBuffer::Owned_StringBuffer(const Owned_StringBuffer& obj){

	_length = obj.length();  
	_strbuf= new char[_length];

	for (int i = 0;i<_length;i++)
	{
		_strbuf[i]=obj.charAt(i);
	}
}

Owned_StringBuffer::Owned_StringBuffer(char* &ptr ,int length)
{

	_strbuf= ptr;
	ptr = NULL;
	_length= length;
	
}

char Owned_StringBuffer::charAt (int index) const
{
		return *(_strbuf+index);
}

int Owned_StringBuffer::length() const{
	return _length;
}

void Owned_StringBuffer::reserve(int length)
{
	_strbuf= new char[length];
}

void Owned_StringBuffer::append(char c)
{
	char* temp= _strbuf;
	_length++;
	_strbuf=new char [_length];

	for (int i = 0; i < _length - 1; i++)
	{
		_strbuf[i]=temp[i];
	}

	_strbuf[_length - 1 ]=c ;
	delete[] temp;
}
