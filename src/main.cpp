/*
 * main.cpp
 *
 *  Created on: 06-Mar-2016
 *      Author: muhammadmoazkhan
 */
#include<iostream>
#include"StringBuffer.h"
#include"Owned_StringBuffer.h"
#include"RefCount_StringBuffer.h"
#include"Linking_StringBuffer.h"

using namespace std;


int main(){
	cout<<endl<<"*************  FOR COPIED POINTERS  **************"<<endl;
    StringBuffer* sb = new StringBuffer("Moaz",4);
    cout << "Length is = " << sb->length() <<endl;
    cout<<"Char at 2 = " <<sb->charAt(1)<<endl<<endl;

	sb->append('K');
	sb->append('h');

	 cout << "Length after append is = " << sb->length() <<endl;
	 cout<<"Char at 1 after append is = " <<sb->charAt(1)<<endl;

	 cout<<endl<<"*************  NOW FOR OWNED POINTERS  **************"<<endl;
	 Owned_StringBuffer *osb = new Owned_StringBuffer();
	  cout << "Length is = " << osb->length() <<endl;
	 osb->append('a');
	 osb->append('z');

	  cout<<"Char at 1 after append is = " <<osb->charAt(1)<<endl;
	  cout << "Length after append is = " << osb->length() <<endl;

	  cout<<endl<<"*************  NOW FOR COW_LINKING  **************"<<endl;

	  char* nameTemp= "Moaz";
	  Linking_StringBuffer* nameTemp1 = new Linking_StringBuffer(nameTemp,4);
	  Linking_StringBuffer* nameTemp2 = new Linking_StringBuffer();

	  *nameTemp2 = *nameTemp1;


	  nameTemp1->append('M');
	  cout<<"Char at 4 after append is = " <<nameTemp1->charAt(4)<<endl;
	  cout << "Length after append is = " << nameTemp1->length() <<endl;

	  cout<<"Char at 0 after append is name temp2 = " <<nameTemp2->charAt(0)<<endl;
	  cout << "Length after append is name temp2 = " << nameTemp2->length() <<endl;


	  cout<<endl<<"*************  NOW FOR REF_COUNTING  **************"<<endl;

	  RefCount_StringBuffer* refcnt1 = new RefCount_StringBuffer(nameTemp,4);
	  RefCount_StringBuffer* refcnt2 = new RefCount_StringBuffer();
	  *refcnt2 = *refcnt1;
	  cout<<"Reference count is ="<<refcnt1->get_str()->_refcount<<endl;
	  refcnt2 -> append('h');
	  refcnt2 -> append('o');
	  refcnt2 -> append('l');
	  cout<<"1st  ref count = "<<refcnt1-> get_str()->_refcount<<endl;
	  cout<<"Char at 3 after append is name temp2 = " <<refcnt2->charAt(2)<<endl;
	//	getchar();
	return 0;
}

