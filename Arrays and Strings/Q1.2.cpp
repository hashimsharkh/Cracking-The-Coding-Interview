#include <iostream>
#include <string>
#include <map>
#include <algorithm> 

using namespace std;

#define CHAR_SET 128

//Q1.2 in Chapter 1: Array and strings
//Write a method to determine if one string is a permutation of another
//very similar question to q1.1
//ASSUME 128 ASCII CHARACTERS 

//Hash-maps is something that is kept in the back of my mind always(Note to self:keep writing it down so that it sticks
//to mind)


//Brute force method is to compare all characters in string to each other. Time complexity: O(n^2) where n is the size
//of the strings (strings have to be the same size for them to be a permutation of each other)

//time complexity of O(n),more temporary space is used in the first way i designed space complexity is O(1) if character
//set is determined to be fixed

bool isPermutation(string str1, string str2)
{
	if (str1.length() != str2.length())
		return false;

	bool *visitedArr= new bool[128];
	bool *visitedArr2 = new bool[128];
	
	for (int i = 0; i < 128; i++)
	{
		visitedArr[i] = 0;
		visitedArr2[i] = 0;
	}

	for (int i = 0; i < str1.length(); i++)
	{
		visitedArr[int(str1[i])] = 1;
		visitedArr2[int(str2[i])] = 1;

	}

	for (int i = 0; i < str1.length(); i++)
		if (visitedArr[int(str1[i])] != visitedArr2[int(str1[i])])
			return false;
	
	return true;

	delete[] visitedArr;

	visitedArr = visitedArr2 = NULL;
}

//Implementing it by using an array that acts like a hash map
//increment the array for each character in str1, and decrement it for each character in str2
//if you end up with non zero numbers in the array then the strings are not a permutation of each oher
bool isPermutationSolution(string str1, string str2)
{
	if (str1.length() != str2.length())
		return false;

	int *visitedArr = new int[128];


	for (int i = 0; i < 128; i++)
		visitedArr[i] = 0;

	for (int i = 0; i < str1.length(); i++)
	{
		visitedArr[str1[i]]++;
		visitedArr[str2[i]]--;
	}

	for (int i = 0; i < str1.length(); i++)
		if (visitedArr[str1[i]] != 0)
			return false;
	
	return true;

	delete[] visitedArr;

	visitedArr = NULL;
}

//Other way of doing this is by sorting then linearly comparing,this takes up more space and gives a time complexity of
//O(nlogn)
bool isPermutationSorting(string str1, string str2)
{
	if (str1.length() != str2.length())
		return false;

	// Sort both strings 
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	// Compare sorted strings 
	for (int i = 0; i < str1.length(); i++)
		if (str1[i] != str2[i])
			return false;
	return true;

}

//driver function to test functions
int main()
{
	string hashim = "Hashim", alyssa = "hasimH";
	
	//testing first function
	cout << "Is the string \"" << hashim << "\" a permutation of the string \"" << alyssa;
	cout << "\" : " << isPermutation(hashim, alyssa);
	cout << endl;

	//testing second function
	cout << "Is the string \"" << hashim << "\" a permutation of the string \"" << alyssa;
	cout << "\" : " << isPermutationSolution(hashim, alyssa);
	cout << endl;

	//testing third function
	cout << "Is the string \"" << hashim << "\" a permutation of the string \"" << alyssa;
	cout << "\" : " << isPermutationSorting(hashim, alyssa);
	cout << endl;
	char c;
	cin >> c;
}