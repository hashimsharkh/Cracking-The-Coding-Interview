//Hashim Abu Sharkh
//Q1.6- String Compression
#include <iostream>
#include <map>
#include <string>
using namespace std;

//After reading the question, the first thing that comes to my mind is a hash table,as the characters can be used as keys and the number of times a character appears
//will be the value
//However, after re reading the question carefully a hash map cannot be used as they want each substring of similar characters to be grouped together not all 
//the similar characters
//I will start by compressing the string using two runnning pointers then i will optimize

//assume only lower case letters and upper case letters
//This solution has time complexity of O(n) but uses O(n) extra space n is the number of characters in the original string
//If this was in java then string concatenation would take O(n^2) and runtime would be O(n+m^2) where m is the sequence of characters
string stringCompression(string str)
{	
	string tmpStr;
	int count=0;
	for(int i=0,j=1;i<str.length();i++,j++)
	{	
		count++;

		if(str[i]!=str[j])
		{
			string countStr=to_string(count);
			tmpStr.append(str[i]+countStr);
			count=0;
		}
		
	}


	return tmpStr>str?str:tmpStr;




}

//Another approach to make it optimal in cases where there are not many repeating characters
int compressedLength(string str)
{
	int countConsecutive=0;
	int compressedLength=0;
	for(int i=0,j=1;j<str.length();i++,j++)
	{
		countConsecutive++;
		
		if(str[i]!=str[j]||j>=str.length())
		{	compressedLength+=to_string(countConsecutive).length()+1;
			countConsecutive=0;
		}

	}
	return compressedLength;
}

string compress(string str)
{ 
	//This is where it makes it optimal
	if(compressedLength(str)>str.length()) return str;

		string tmpStr;
	int count=0;
	for(int i=0,j=1;i<str.length();i++,j++)
	{	

		count++;

		if(str[i]!=str[j]||j>=str.length())
		{		
			string countStr=to_string(count);
			tmpStr.append(str[i]+countStr);
			count=0;
		}

	}


	return tmpStr;


}

//driver function to test method
int main()
{
	string str="aabccccaaabbbfff";
	cout<<stringCompression(str)<<endl;

	//Test solution #2
	string alyssa= "Alyssaaaa";

	cout<<compress(alyssa)<<endl;

}