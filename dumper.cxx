# include <string>
# include <regex>
# include "types.hpp"
using namespace std;

string dumps(string pythonDictionary) {
	pythonDictionary = regex_replace(pythonDictionary, regex(PythonObjects::null), JSONObjects::null);
	pythonDictionary = regex_replace(pythonDictionary, regex(PythonObjects::apostrof), JSONObjects::apostrof);
	return pythonDictionary;
}