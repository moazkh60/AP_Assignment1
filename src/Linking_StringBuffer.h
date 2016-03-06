
#include <iostream>



class reflink;
class str;
class Linking_StringBuffer;

class reflink
{
public:
	Linking_StringBuffer* _address;
	reflink* next;
};

class strLink
{
public:
	char* _strbuf;    //buffer to store the original string
	int _length;      //length of the string
	int _refcount;		//no of references
	reflink* _reflink;	// this is head to link this with references
	strLink();	//constructor
};

class Linking_StringBuffer{
	//string buffer class

public :
	Linking_StringBuffer();  //default constructor
	~Linking_StringBuffer();                //destructor; would delete the allocated buffer
	Linking_StringBuffer(const Linking_StringBuffer&); //constructor for shallow copying
	Linking_StringBuffer(char*,int);   //constructor to convert a char* to Linking_StringBuffer
	char charAt(int) const;   //returns the character at the passed index
	int length() const;      //returns the length of the buffer
	void reserve(int);       //allocates memory for the string, according to the passed character length
	void append(char);       //appends a single character at the end
	reflink* get_link();	// -> returns linked list head
	Linking_StringBuffer& operator = (const Linking_StringBuffer&);

private:
	strLink*  _str;
};

