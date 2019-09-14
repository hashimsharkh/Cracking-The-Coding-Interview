#include <iostream>
#include <string>
#include <iterator>
#include <map>
using namespace std;

//Q1.1- first attempt with a brute force solution, time complexity: O(N^2), Space complexity: O(1)
bool isUnique(string str)
{

	for (int i = 0; i < str.length(); i++)
		for (int j = i + 1; j < str.length(); j++)
			if (str[i] == str[j])
				return false;
	return true;
}

//Attempt to reduce runtime, implementing a hash table improves runtime to best conceivable runtime which is O(n)
bool isUnique1(string str)
{
	map<char, int> hashim ;
	
	for (char s : str)
	{
		if (hashim.count(s)>0)
			return false;
		else
			hashim.insert(pair<char,int>(s, 1));
	}
	return true;

}

// A very smart way of approaching this problem 
//Ascii(not extended) has 128 characters, that means if there are more than 128 characters, string wont be unique
//(pigeon hole principle) at least 2 pigeons will be in one pigeonhole
//Time Complexity:O(n) where n is the length of the string, also can be argued that time complexity is O(1) as the for loop
// will never iterate more than 128 times
bool isUnique2(string str)
{
	if (str.length() > 128) return false;

	bool *visitedArr = new bool[128];
	for (int i = 0; i < 128; i++)
		visitedArr[i] = false;

	for (char s : str)
	{
		if (visitedArr[(int)s])
			return false;
		else
			visitedArr[(int)s] = true;
	}

	delete[] visitedArr;
	visitedArr = NULL;
	return true;
}



//Attempt to reduce runtime without using additional data structures
//To do so, you can sort the string using an O(logn) sorting algorithm then linearly search neighboring characters for
//identical characters, However sorting algorithms take up space



//driver function to test functions
int main()
{
	string hashim= "Hashim";

	cout<<"The string "<<hashim<<" is unique: "<< isUnique(hashim)<<"\n";
	cout << "The string " << hashim << " is unique: " << isUnique1(hashim) << "\n";
	cout << "The string " << hashim << " is unique: " << isUnique2(hashim) << "\n";

	char c;
	cin >> c;

}