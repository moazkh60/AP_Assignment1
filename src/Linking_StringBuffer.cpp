
#include "Linking_StringBuffer.h"
#include <iostream>

Linking_StringBuffer::Linking_StringBuffer()
{
	_str = nullptr;
}

Linking_StringBuffer::~Linking_StringBuffer()
{
	if(_str->_refcount==1)
	{
		delete[] _str->_strbuf;
		delete _str->_reflink;
		delete _str;
	}
	else
	{
		_str->_refcount--;
		Linking_StringBuffer* add = this;
			if(_str->_reflink->_address==this)
	{
		reflink* temp = _str->_reflink;
		_str->_reflink= _str->_reflink->next;
		delete temp;
	}

	else{

		reflink* ptr =_str->_reflink;
		reflink* prev = NULL;

		while(ptr)
		{
			if(ptr->_address==this)
			{
				prev->next=ptr->next;
				delete ptr;
				break;
			}
			prev= ptr;
			ptr= ptr->next;
		}

	}
	}

}

Linking_StringBuffer::Linking_StringBuffer(const Linking_StringBuffer& obj){
	
	// -> shallow copying constructor 
	_str->_length = obj.length();
	_str->_strbuf= new char[_str->_length];
	for (int i = 0;i<_str->_length;i++)
	{
		_str->_strbuf[i]=obj.charAt(i);
	}
	reflink* rlinking= new reflink;
	rlinking->_address=this;
	rlinking->next=NULL;
	if(_str->_reflink==NULL)
	{
		_str->_reflink=rlinking;
	}
	else
	{
		reflink* ptr = _str->_reflink;
		reflink*  prev = NULL;
		while(ptr)
		{
			prev= ptr;
			ptr= ptr->next;
		}
		prev->next=rlinking;
	}
}

Linking_StringBuffer::Linking_StringBuffer(char* ptr ,int length)
{
	// ->constructor to convert a char* to Linking_StringBuffer
	_str = new strLink;
	_str->_strbuf= new char[length];
	_str->_length= length;
	for (int i = 0; i < length - 1; i++)
	{
		_str->_strbuf[i]=ptr[i];
	}
	reflink* rlinking= new reflink;
	rlinking->_address=this;
	rlinking->next=NULL;

	if(_str->_reflink==NULL)
	{
		_str->_reflink=rlinking;
	}
	else
	{
		reflink* ptr = _str->_reflink;
		reflink*  prev =NULL;
		while(ptr)
		{
			prev= ptr;
			ptr= ptr->next;
		}
		prev->next=rlinking;
	}	
}

strLink::strLink()
{
	_strbuf=nullptr;
	_length=0;
	_refcount=1;
	_reflink = NULL;
}


reflink* Linking_StringBuffer::get_link(){

	return _str -> _reflink;

}

char Linking_StringBuffer::charAt (int bufferindex) const
{
	// -> returns the character at the passed index
		return *(_str->_strbuf+bufferindex);	
}

int Linking_StringBuffer::length() const{
	// -> returns the length of the buffer
	return _str->_length;
}

void Linking_StringBuffer::reserve(int length)
{
	// -> allocates memory of character length size
	_str= new strLink;
	_str->_strbuf= new char[length];
	reflink* rlinking= new reflink;
	rlinking->_address=this;
	rlinking->next=NULL;
	if(_str->_reflink==NULL)
	{
		_str->_reflink= rlinking;
	}
	else
	{
		reflink* ptr = _str->_reflink;
		reflink*  prev=NULL;
		while(ptr)
		{
			prev= ptr;
			ptr= ptr->next;
		}
		prev->next=rlinking;
	}
}

void Linking_StringBuffer::append(char c)
{
	// -> appendingcharacter at end of string

	if(_str->_refcount>1)
	{
		strLink* str1 = new strLink;
		str1->_length =_str->_length + 1;
		str1->_strbuf= new char[str1->_length];
		for (int i = 0; i < _str->_length; i++)
		{
			str1->_strbuf[i]=_str->_strbuf[i];
		}
		str1->_strbuf[_str->_length]=c;
		_str->_refcount--;
			if(_str->_reflink->_address==this)
	{
		reflink* str1 = _str->_reflink;
		_str->_reflink= _str->_reflink->next;
		delete str1;
	}
	else{
		reflink* ptr =_str->_reflink;
		reflink* prev = NULL;
		while(ptr)
		{
			if(ptr->_address==this)
			{
				prev->next = ptr->next;
				delete ptr;
				break;
			}
			prev = ptr;
			ptr= ptr->next;
		}

	}
		_str=str1;
		reflink* rlinking= new reflink;
		rlinking->_address=this;
		rlinking->next=NULL;
	if(_str->_reflink==NULL)
	{
		_str->_reflink=rlinking;
	}
	else
	{
		reflink* ptr = _str->_reflink;
		reflink*  prev=NULL;
		while(ptr)
		{
			prev= ptr;
			ptr= ptr->next;
		}
		prev->next=rlinking;
	}

	}
	else
	{

		char* str1= _str->_strbuf;
		_str->_length++;
		_str->_strbuf=new char [_str->_length];
		for (int i = 0; i < _str->_length - 1; i++)
		{
			_str->_strbuf[i]=str1[i];
		}
		_str->_strbuf[_str->_length - 1 ]=c ;
		delete[] str1;

	}


}


//  -> operator overloading
Linking_StringBuffer& Linking_StringBuffer::operator = (const Linking_StringBuffer& obj)
{
	_str=obj._str;
	_str->_refcount++;
	reflink* rlinking= new reflink;
	rlinking->_address=this;
	rlinking->next=NULL;
	if(_str->_reflink==NULL)
	{
		_str->_reflink=rlinking;
	}
	else
	{
		reflink* ptr = _str->_reflink;
		reflink*  prev=NULL;
		while(ptr)
		{
			prev= ptr;
			ptr= ptr->next;
		}
		prev->next=rlinking;
	}
	return *this;
}


