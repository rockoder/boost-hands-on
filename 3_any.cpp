#include <iostream>
#include <boost/any.hpp>

using namespace std;
using namespace boost;

int main()
{
	// any stores a double
	any ob {3.14};

	// any stores a string
	any str = string("test");

	// any within a collection
	vector<any> v {100, "mystring"};

	if (!ob.empty()) // true if any does not contain value
	{
		// Give name of the type stored.
		// Output is compiler dependent.
		cout << ob.type().name() << endl;
	}

	for (any a : v)
	{
		// Using reference to get the value stored inside any.
		// This will throw exception if casting is not possible.
		try
		{
			int value = any_cast<int>(a);
			cout << value << endl;
		}
		catch (const bad_any_cast& e)
		{
			cout << "Could not convert to int." << endl;
		}
	}

	for (any a : v)
	{
		// Using pointer to get the value stored inside any.
		// This will return nullptr if casting is not possible.
		int* value = any_cast<int>(&a);

		if (value != nullptr)
		{
			cout << *value << endl;
		}
		else
		{
			cout << "Could not convert to int." << endl;
		}
	}

	return 0;
}