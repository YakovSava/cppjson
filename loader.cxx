# include <regex>
# include <string>
# include "types.hpp"
using namespace std;

string load(string toPythonDictionary) {
	toPythonDictionary = regex_replace(toPythonDictionary, regex(JSONObjects::null), PythonObjects::null);
	toPythonDictionary = regex_replace(toPythonDictionary, regex(JSONObjects::apostrof), PythonObjects::apostrof);
	return toPythonDictionary;
}