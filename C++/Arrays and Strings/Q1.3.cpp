#include <iostream>
#include <string>
#include<map>

using namespace std;

//Question 1.3, add a %20 in each space, Common approach is to have use the buffer at the end of a string
//to manipulate a string from the end

void URLify(char* str,int trueLength)
{
	int spaceCount = 0;
	int i = 0, j = 0;
	for (int i=0;i<trueLength;i++)
		if (str[i] == ' ')
			spaceCount++;
		
	int index = spaceCount * 2 + trueLength;
	i = index - 1;
	
	for (j= trueLength - 1; j >= 0; j--)
	{
		if (str[j] == ' ')
		{
			str[i--] = '0';
			str[i--] = '2';
			str[i--] = '%'; 
		}
		else
			str[i--] = str[j];
	}

}

//Very easy way of urlifying a string but i dont think that is what was meant in the book
void URLify(string &str)
{
	string r;

	for (char c : str)
		if (c == ' ')
			r.append("%20");
		else
			r.push_back(c);

	str = r;
}


int main()
{
	//Test first function
	char str[] = "Mr John Smith    ";
	cout << "Function #1:" << endl;
	cout << "Actual String is:" << str << endl;
	URLify(str, 13);
	cout << "URLified String is:" << str << endl;

	//Test second function
	string str1 = "Hashim Abu Sharkh";
	cout << "Function #2:"<<endl;
	cout << "Actual String is:" << str1 << endl;
	URLify(str1);
	cout << "URLified String is:" << str1 << endl;
	char c;
	cin >> c;
}