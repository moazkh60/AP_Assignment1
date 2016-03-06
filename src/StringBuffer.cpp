
#include "StringBuffer.h"
#include <iostream>

using namespace std;
StringBuffer::StringBuffer() //default constructor
{
	_strbuf=nullptr;	//    sets string buffer = null
	_length = 0;		//    initializes length to zero
}

StringBuffer::~StringBuffer() // destructor
{
	delete[] _strbuf;	//    simple deleting the allocated buffer
}

StringBuffer::StringBuffer(const StringBuffer& obj){
	_length = obj.length();
	_strbuf= new char[_length];

	for (int i = 0;i<_length;i++)
	{
		_strbuf[i]=obj.charAt(i);
	}
}


StringBuffer::StringBuffer(char* ptr ,int length)
{
	_strbuf= new char[length];
	_length= length;

	for (int i = 0; i < _length - 1; i++)
	{
		_strbuf[i]=ptr[i];
	}
}

char StringBuffer::charAt (int bufferindex) const
{
		return *(_strbuf+bufferindex);
}

int StringBuffer::length() const{
	return _length;
}

void StringBuffer::reserve(int length)
{
	_strbuf= new char[length];
}

void StringBuffer::append(char c)
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


