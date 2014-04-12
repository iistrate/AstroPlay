#include "StringParser.h"

StringParser::StringParser(): m_POfunctionName(NULL), m_POmodule(NULL), m_POname(NULL), m_POvalues(NULL) {
	//start python c apy
	Py_Initialize();
	//init threads
	if (!PyEval_ThreadsInitialized()) {
		PyEval_InitThreads();
	}
}

void StringParser::init() {
	//on init lock gil state
	m_gstate = PyGILState_Ensure();
	//module name
	const char module[] = "Parser";

	//build c string to py object string
	m_POname = Py_BuildValue("s", module);
	//load module into py object
	m_POmodule = PyImport_Import(m_POname);
}

void StringParser::parseString(std::vector < int > &i_commands, std::string s_command) {
	//if python interpreter is initialized
	if (Py_IsInitialized) {
		//if module is loaded
		if (m_POmodule) {
			//load function
			m_POfunctionName = PyObject_GetAttrString(m_POmodule, "name");
		}
		//if function exists and is callable
		if (m_POfunctionName && PyCallable_Check(m_POfunctionName)) {
			m_POvalues = PyObject_CallFunctionObjArgs(m_POfunctionName, NULL);
		}
	}
}

void StringParser::close() {
//	Py_DECREF(m_POmodule);
//	Py_DECREF(m_POname);
//	Py_DECREF(m_POfunctionName);
//on close kill gill state
PyGILState_Release(m_gstate);
}
StringParser::~StringParser() {
	//close python c api
	Py_Finalize();
}