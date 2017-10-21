// LISTING 21.3 - Usage of the find Member Function in a Multimap
#include <map>
#include <iostream>
#include <string>

using namespace std;

// Typedef the multimap definition for easy readability
typedef multimap <int, string> MMAP_INT_STRING;

int main()
{
	MMAP_INT_STRING mmapIntToString;

	// The insert function works the same way for multimap too
	mmapIntToString.insert(MMAP_INT_STRING::value_type(3, "Three"));
	mmapIntToString.insert(MMAP_INT_STRING::value_type(45, "Forty Five"));
	mmapIntToString.insert(MMAP_INT_STRING::value_type(-1, "Minus One"));
	mmapIntToString.insert(MMAP_INT_STRING::value_type(1000, "Thousand"));

	// A multimap can store duplicates - insert one
	mmapIntToString.insert(MMAP_INT_STRING::value_type
	(1000, "Thousand (duplicate)"));

	cout << "The multimap contains " << mmapIntToString.size();
	cout << " key-value pairs." << endl;
	cout << "The elements in the multimap are: " << endl;

	// Print the contents of the map to the screen
	MMAP_INT_STRING::const_iterator iMultiMapPairLocator;

	for (iMultiMapPairLocator = mmapIntToString.begin()
		; iMultiMapPairLocator != mmapIntToString.end()
		; ++iMultiMapPairLocator)
	{
		cout << "Key: " << iMultiMapPairLocator->first;
		cout << ", Value: " << iMultiMapPairLocator->second << endl;
	}

	cout << endl;

	cout << "Finding all key-value pairs with 1000 as their key: " << endl;

	// Find an element in the multimap using the 'find' function
	MMAP_INT_STRING::const_iterator iElementFound;

	iElementFound = mmapIntToString.find(1000);

	// Check if "find" succeeded
	if (iElementFound != mmapIntToString.end())
	{
		// Find the number of pairs that have the same supplied key
		size_t nNumPairsInMap = mmapIntToString.count(1000);
		cout << "The number of pairs in the multimap with 1000 as key: ";
		cout << nNumPairsInMap << endl;

		// Output those values to the screen
		cout << "The values corresponding to the key 1000 are: " << endl;
		for (size_t nValuesCounter = 0
			; nValuesCounter < nNumPairsInMap
			; ++nValuesCounter)
		{
			cout << "Key: " << iElementFound->first;
			cout << ", Value [" << nValuesCounter << "] = ";
			cout << iElementFound->second << endl;

			++iElementFound;
		}
	}
	else
		cout << "Element not found in the multimap";

	return 0;
}