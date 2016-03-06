#include <iostream>

// -> Header file for owned pointer's string buffer


class Owned_StringBuffer{

public :

	//
    Owned_StringBuffer();			//default constructor
	~Owned_StringBuffer();        //destructor; would delete the allocated buffer

    Owned_StringBuffer(const Owned_StringBuffer&);  //constructor for shallow copying
    Owned_StringBuffer(char*&,int);			//constructor to convert a char* to Owned_StringBuffer
   
	char charAt(int) const;		//returns the character at the passed index
	int length() const;			 //returns the length of the buffer
	void reserve(int);     //allocates memory for the string, according to the passed character length
	void append(char);      //appends a single character at the end

private:
    char* _strbuf;          //buffer to store the original string
    int _length;            //length of the string
};
