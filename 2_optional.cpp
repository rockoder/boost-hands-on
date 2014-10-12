#include <iostream>
#include <boost/optional.hpp>

using namespace std;
using namespace boost;

struct Address
{
	Address(string st) :
		streetName(st)
	{	}

	string streetName;
};

struct Person
{
	Person(string fn, string ln) :
		firstName(fn), lastName(ln)
	{	}

	string firstName;
	string lastName;

	// Class creator explicity informs the class user that
	// middleName is optional and may not contain a value.
	optional<string> middleName;

	optional<Address> address;
};

// Function creator explicitly informs the function 
// caller that it may not alway return a value.
optional<int> tyr_parse_int(string s)
{
	optional<int> result;

	if (!s.empty())
	{
		// Parse the int from s and store in result
	}

	return result;
}

int main()
{
	Person p {"Sachin", "Tendulkar"};

	// Using optional without initization results in assertion
	// cout << *p.middleName << endl;

	p.middleName = "Ramesh";

	if (p.middleName) // Returns true if optional contains value
	{	
		// Ways to get the value stored inside optional

		cout << *p.middleName << endl;
		cout << p.middleName.get() << endl;
	}

	p.address = Address("FC Road");

	if (p.address)
	{
		// Ways to get the member within the optional

		cout << p.address->streetName << endl;
		cout << (*p.address).streetName << endl;
	}

	// Quick if-else
	cout << p.middleName.value_or("R") << endl;

	return 0;
}