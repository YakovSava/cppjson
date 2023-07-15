# include <Python.h>
# include <regex>
# include <string>
# include "types.hpp"
using namespace std;

string c_load(string toPythonDictionary) {
	toPythonDictionary = regex_replace(toPythonDictionary, regex(JSONObjects::null), PythonObjects::null);
	toPythonDictionary = regex_replace(toPythonDictionary, regex(JSONObjects::apostrof), PythonObjects::apostrof);
	toPythonDictionary = regex_replace(toPythonDictionary, regex(JSONObjects::true_true), PythonObjects::true_true);
	toPythonDictionary = regex_replace(toPythonDictionary, regex(JSONObjects::false_false), PythonObjects::false_false);
	return toPythonDictionary;
}

static PyObject* load(PyObject *self, PyObject *args) {
    PyObject* str_dict_obj;

    if (!PyArg_ParseTuple(args, "U", &filename_obj)) {
        return NULL;
    }

    string py_dict = str(1, PyUnicode_AsUTF8(str_dict_obj));
    string load_result = c_load(py_dict);

    return PyUnicode_FromString(load_result.c_str());
}

static PyMethodDef methods[] = {
    {"load", load, METH_VARARGS, "Load JSON object from C"},
    {NULL, NULL, 0, NULL} 
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "loader",
    "Loader",
    -1,
    methods
};

PyMODINIT_FUNC PyInit_loader(void) {
    return PyModule_Create(&module);
}