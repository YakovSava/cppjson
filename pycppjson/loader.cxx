# include <regex>
# include <string>
# include "types.hpp"
using namespace std;

string load(string toPythonDictionary) {
	toPythonDictionary = regex_replace(toPythonDictionary, regex(JSONObjects::null), PythonObjects::null);
	toPythonDictionary = regex_replace(toPythonDictionary, regex(JSONObjects::apostrof), PythonObjects::apostrof);
	toPythonDictionary = regex_replace(toPythonDictionary, regex(JSONObjects::true_true), PythonObjects::true_true);
	toPythonDictionary = regex_replace(toPythonDictionary, regex(JSONObjects::false_false), PythonObjects::false_false);
	return toPythonDictionary;
}