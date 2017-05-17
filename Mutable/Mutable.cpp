// Mutable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string> 

class Scrollbar
{
	int size;			// related to constness
	mutable std::string owner; // not related to constness
public:
	Scrollbar(int sz, std::string own) : size(sz), owner(own)
	{}
	void setSize(int sz)		//  changes size
	{
		size = sz;
	}
	void setOwner(std::string own) const // changes owner
	{
		owner = own;
	}
	int getSize() const			// return size
	{
		return size;
	}
	std::string getOwner() const // return owner
	{
		return owner;
	}
};


int main()
{
	const Scrollbar scrollBar(60, "Windows1");

	//scrollBar.setSize(100); //can#t do this as this is const object!!

	scrollBar.setOwner("Window2"); // this is OK

	std::cout << scrollBar.getSize() << ", " << scrollBar.getOwner() << std::endl;

	system("pause");
    return 0;
}

