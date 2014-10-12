#include <iostream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

int main()
{
	// Convert string to double
	string s1 = "3.14";
	double d = lexical_cast<double>(s1);

	// Convert string to int
	string s2 = "100";
	int i = lexical_cast<int>(s2);

	cout << d << " " << i << endl;

	try
	{
		// This will throw bad_lexical_cast, much better than atoi() etc
		cout << lexical_cast<int>("abc") << endl;
	}
	catch (const bad_lexical_cast& e)
	{
		cout << e.what() << endl;
	}

	try
	{
		cout << "short = " << lexical_cast<short>("32767") << endl;

		// lexical_cast also check bounds. This should throw for 2 bytes short
		cout << "short = " << lexical_cast<short>("32768") << endl;
	}
	catch (const bad_lexical_cast& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}