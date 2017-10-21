// Listing 21.5 - Using a map with a custom sort predicate to program a telephone directory
#include "stdafx.h"
#include <map>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

/*
This is the binary predicate that helps the map sort
string-keys irrespective of their case
*/
struct CCaseInsensitive
{
	bool operator () (const string& str1, const string& str2) const
	{
		string str1NoCase(str1), str2NoCase(str2);
		transform(str1.begin(), str1.end(), str1NoCase.begin(), tolower);
		transform(str2.begin(), str2.end(), str2NoCase.begin(), tolower);

		return (str1NoCase < str2NoCase);
	};
};


// Typedef map definitions for easy readability...
// A directory that sorts keys using string::operator < (case sensitive)
typedef map <string, string> DIRECTORY_WITHCASE;

// A case-insensitive directory definition 
typedef map <string, string, CCaseInsensitive> DIRECTORY_NOCASE;

int main()
{
	// Case-insensitive directory: case of the string-key plays no role
	DIRECTORY_NOCASE dirNoCase;

	dirNoCase.insert(DIRECTORY_NOCASE::value_type("John", "2345764"));
	dirNoCase.insert(DIRECTORY_NOCASE::value_type("JOHN", "2345764"));
	dirNoCase.insert(DIRECTORY_NOCASE::value_type("Sara", "42367236"));
	dirNoCase.insert(DIRECTORY_NOCASE::value_type("Jack", "32435348"));

	cout << "Displaying contents of the case-insensitive map:" << endl;

	// Print the contents of the map to the screen
	DIRECTORY_NOCASE::const_iterator iPairLocator1;
	for (iPairLocator1 = dirNoCase.begin()
		; iPairLocator1 != dirNoCase.end()
		; ++iPairLocator1)
	{
		cout << "Name: " << iPairLocator1->first;
		cout << ", Phone number: " << iPairLocator1->second << endl;
	}

	cout << endl;

	// Case-sensitive directory: case of the string-key affects
	// insertion & search
	DIRECTORY_WITHCASE dirWithCase;

	// Take sample values from previous map...
	dirWithCase.insert(dirNoCase.begin(), dirNoCase.end());

	cout << "Displaying contents of the case-sensitive map:" << endl;

	// Print the contents of the map to the screen
	DIRECTORY_WITHCASE::const_iterator iPairLocator2;
	for (iPairLocator2 = dirWithCase.begin()
		; iPairLocator2 != dirWithCase.end()
		; ++iPairLocator2)
	{
		cout << "Name: " << iPairLocator2->first;
		cout << ", Phone number: " << iPairLocator2->second << endl;
	}

	cout << endl;

	// Search for a name in the two maps and display result
	cout << "Please enter a name to search: " << endl << "> ";
	string strNameInput;
	cin >> strNameInput;

	DIRECTORY_NOCASE::const_iterator iSearchResult1;

	// find in the map...
	iSearchResult1 = dirNoCase.find(strNameInput);
	if (iSearchResult1 != dirNoCase.end())
	{
		cout << iSearchResult1->first << "'s number in the case-insensitive";
		cout << " directory is: " << iSearchResult1->second << endl;
	}
	else
	{
		cout << strNameInput << "'s number not found ";
		cout << "in the case-insensitive directory" << endl;
	}

	DIRECTORY_WITHCASE::const_iterator iSearchResult2;

	// find in the case-sensitive map...
	iSearchResult2 = dirWithCase.find(strNameInput);
	if (iSearchResult2 != dirWithCase.end())
	{
		cout << iSearchResult2->first << "'s number in the case-sensitive";
		cout << " directory is: " << iSearchResult2->second << endl;
	}
	else
	{
		cout << strNameInput << "'s number was not found ";
		cout << "in the case-sensitive directory" << endl;
	}

	return 0;
}