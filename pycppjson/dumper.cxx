# include <string>
# include <regex>
# include "types.hpp"
using namespace std;

string dumps(string pythonDictionary) {
	pythonDictionary = regex_replace(pythonDictionary, regex(PythonObjects::null), JSONObjects::null);
	pythonDictionary = regex_replace(pythonDictionary, regex(PythonObjects::apostrof), JSONObjects::apostrof);
	pythonDictionary = regex_replace(pythonDictionary, regex(PythonObjects::true_true), JSONObjects::true_true);
	pythonDictionary = regex_replace(pythonDictionary, regex(PythonObjects::false_false), JSONObjects::false_false);
	return pythonDictionary;
}