#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Q1.9
//What is a rotation? Rotation at a particular point is when a string is cut at a specific character and the left side of the cut is placed at the end of the 
//string
bool isSubstring(string str1,string str2)
{
	return true;
}

//Runtime depends on isSubstring
bool isRotation(string str1,string str2)
{
	//If they are not of the same size
	str2.append(str1);

	return isSubstring(str2,str1);
}

int main()
{
	cout<<isRotation("waterbottle","erbottlewat");
}
