//Hashim Abu Sharkh
//Q1.5

#include <iostream>
#include<map>
#include <string>
#include <iterator>
using namespace std;

//Observed the follwing:
//Base Case: if first string is the same as second string 0 edits were made
//If insert edit is used, 2nd string will have one more character than first string
//If replace edit is used, both will have the same size (2 cases where first and second string are the same size)
//If remove edit is used, second string will have one less string than the first one
bool isOneEditAway(string,string);
bool isOneEditAwayReplace(string,string);
bool isOneEditAwayRemove(string,string);
bool isOneEditAwayInsert(string,string);


int main()
{
	string first = "pale",second = "bale";

	cout<<"Are the strings one edit away: "<<isOneEditAway(first,second)<<endl;
}

 bool isOneEditAway(string first,string second)
{
	if(first.length()==second.length())
	{	if(first==second)
			return true;
		return isOneEditAwayReplace(first,second);
	}
	if(first.length()<second.length())
		return isOneEditAwayInsert(first,second);

	return isOneEditAwayRemove(first,second);
}

//Realized mid way through that all of them can be done in one pass 
bool isOneEditAwayReplace(string first,string second)
{
	/*int count =0;
	for(int i=0;i<first.length();i++)
		if(first[i]!=second[i])
			count++;

	return count<=1;*/
	return isOneEditAwayRemove(first,second);
}

//Use of hash table
bool isOneEditAwayRemove(string first,string second)
{

	//Assume ascii characters are 128
	int charFrequency[128]={0};
	int count=0;
	for(char c:first)
		charFrequency[(int)c]++;

	for(char c: second)
		if(!charFrequency[c])
			count++;

		//used for replace
		if(first.length()==second.length())
			return count<=1;

		return !count;//can be merged with replace


}

bool isOneEditAwayInsert(string first,string second)
{
	return isOneEditAwayRemove(second,first);
}
