#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string>

using namespace std;

// Contributor: Arindam Mukherjee
// Example of how to specialize lexical_cast for 
// user defined types without making them streamable

struct Address
{
  string streetName;
  string city;
  string zipCode;

  Address(string street, string cy, string zip)
  	: streetName(street), city(cy), zipCode(zip)
  	{}
};

namespace boost {

template <>
inline Address lexical_cast<Address, string>(const string &arg)
{
	auto firstComma = arg.find_first_of(",");
	if (firstComma == string::npos) {
		//BOOST_LCAST_THROW_BAD_CAST(string, Address);
		throw "bad_lexical_cast";
	}

    auto secondComma = arg.find_first_of(",", firstComma + 1);
    if (secondComma == string::npos) {
    	//BOOST_LCAST_THROW_BAD_CAST(string, Address);
    	throw "bad_lexical_cast";
    }

	return Address{arg.substr(0, firstComma), 
	               arg.substr(firstComma + 1, secondComma - firstComma - 1),
	          	   arg.substr(secondComma + 1)};
}

}

int main()
{
	string address = "FC Road, Pune, 411001";

	// Return value optimization
	// Copy elision
	
	Address addr = boost::lexical_cast<Address>(address);

	cout << "Street: " << addr.streetName << "\n"
	     << "City: " << addr.city << "\n"
	     << "Zip: " << addr.zipCode << "\n";

	return 0;
}
