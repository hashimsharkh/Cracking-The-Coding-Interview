//Hashim Abu Sharkh
//Q1.5

#include <iostream>
#include<map>
#include <string>
#include <iterator>
#include<cmath>
#include <cstdlib>
using namespace std;
//Answer time complexity (O(N_))
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
	string first = "Alyss",second = "Alyssa";

	cout<<"Are the strings one edit away: "<<isOneEditAway(first,second)<<endl;
}

 bool isOneEditAway(string first,string second)
{
	int length1= first.length();
	int length2= second.length();
	if(abs(length1-length2)>1)
		return false;

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

	int index1=0,index2=0, count=0;

	while(index1<first.length()&&index2<second.length())
	{
		if(first[index1]!=second[index2])
		{
			
			if(index1!=index2)
				return false;
			index2++;

			if(first.length()==second.length())
			{
				count++;
				index1++;	
			}
		}
		else
		{
			index1++;
			index2++;
		}
	}
	return count<=1;


}

bool isOneEditAwayInsert(string first,string second)
{
	return isOneEditAwayRemove(second,first);
}
