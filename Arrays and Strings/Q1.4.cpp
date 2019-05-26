#include <iostream>
#include <map>
#include <iterator>
#include <bitset>
#include <string>
using namespace std;

//Palindrome permutation
//After a quick observation i observed that if the number of letters in a word determines a Palindrome
//If you have an even number of characters in a word then each character must be repeated twice for each time it appears
//With odd words, one character will be repeated an even number of times except for one character
//Time complexity: O(n) with auxilliary space of O(n) as well to store hashtable
//First Solution:
bool isPermutationFromPalindrome(string str)
{

    //used to count length of string without spaces
    int length=0;

  map<char,int> myMap;
  map<char,int>::iterator it;

  //map string without spaces to map
  for(char c:str)   
    if(c!=' ')
    {
        if(myMap.count(tolower(c))>0)
            myMap[tolower(c)]++;
        else 
            myMap.insert(pair<char,int>(tolower(c),1));
        length++;
    }

    //If it is even
    if(length%2==0)
    {
         for(it=myMap.begin();it!=myMap.end();it++)
            if(it->second%2!=0)
                return false;
    }
    else
    {
        //count how many times an odd number of characters are present
        int count=0;
         for(it=myMap.begin();it!=myMap.end();it++)
            if(it->second%2!=0)
                count++;
        if(count>1)
            return false;
    }
    return true;
}

//Second Solution: by counting how many odd characters there are on the go we will have a nicer looking code, Same time complexity though
bool isPermutationFromPalindrome1(string str)
{
  int countOdd =0;
  map<char,int> myMap;

  //map string without spaces to map
  for(char c:str)   
    if(c!=' ')
    {
        if(myMap.count(tolower(c))>0)
            myMap[tolower(c)]++;
        else 
            myMap.insert(pair<char,int>(tolower(c),1));
        if(myMap[tolower(c)]%2==1)
            countOdd++;
        else
            countOdd--;

    }

    return countOdd<=1;
}

//After realizing how and what bit vectors are(basic knowledge still lots to learn), I go on to implement the solution using bit vectors to save space

bool isPermutationFromPalindrome2(string str)
{

    //Assuming only English alphabet is used(26 characters)
    bitset<26> bset;//All bits initialized to zero

    //flip bit 
    for(char c:str)
        if(c!=' ')
        bset.flip((int)tolower(c)-97);

    //check that only one bit is set no more
    return bset.count()<=1;

}
int main()
{
	string palindrome[3] = {"Tact Coa","Sten po on pets ","raeccar "};//taco cat,step on no pets,racecar
    cout<<"Is "<<palindrome[0]<< "a permutation of a palindrome: "<<isPermutationFromPalindrome(palindrome[0])<<endl;
    
    //Testing second Function
    cout<<"Is "<<palindrome[1]<< "a permutation of a palindrome: "<<isPermutationFromPalindrome1(palindrome[1])<<endl;

    //Testing third function
    cout<<"Is "<<palindrome[2]<< "a permutation of a palindrome: "<<isPermutationFromPalindrome2(palindrome[2])<<endl;

    return 0;
}