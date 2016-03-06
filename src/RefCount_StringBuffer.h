
#include <iostream>

class str
{
public:
	char* _strbuf;
	int _length;
	int _refcount;
	str();
};
class RefCount_StringBuffer{

public :
	RefCount_StringBuffer();  //default constructor
	~RefCount_StringBuffer();				 //destructor; would delete the allocated buffer
	RefCount_StringBuffer(const RefCount_StringBuffer&); //constructor for shallow copying
	RefCount_StringBuffer(char*,int);   //constructor to convert a char* to RefCount_StringBuffer
	char charAt(int) const;   //returns the character at the passed index
	int length() const;       //returns the length of the buffer
	void reserve(int);        //allocates memory for the string, according to the passed character length
	void append(char);        //appends a single character at the end
	str* get_str();
	RefCount_StringBuffer& operator = (const RefCount_StringBuffer&);

private:
	str*  _str;
};
