# include <Python.h>
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

static PyObject* dump(PyObject *self, PyObject *args) {
    PyObject* str_dict_obj;

    if (!PyArg_ParseTuple(args, "U", &filename_obj)) {
        return NULL;
    }

    string py_dict = str(1, PyUnicode_AsUTF8(str_dict_obj));
    string load_result = c_load(py_dict);

    return PyUnicode_FromString(load_result.c_str());
}

static PyMethodDef methods[] = {
    {"dump", dump, METH_VARARGS, "Load JSON object from C"},
    {NULL, NULL, 0, NULL} 
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "dumper",
    "Dumper",
    -1,
    methods
};

PyMODINIT_FUNC PyInit_dumper(void) {
    return PyModule_Create(&module);
}