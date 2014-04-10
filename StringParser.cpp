#include "StringParser.h"

StringParser::StringParser(): m_POfunctionName(NULL), m_POmodule(NULL), m_POname(NULL), m_POvalues(NULL) {
	Py_Initialize();
}

void StringParser::init() {
	const char module[] = "parser";
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
		//if function exists call it
		if (PyCallable_Check(m_POfunctionName)) {
			std::cout << "DSAsdas";
			m_POvalues = PyObject_CallFunctionObjArgs(m_POfunctionName, "i");
		}
	}
}

void StringParser::close() {
//	Py_DECREF(m_POmodule);
//	Py_DECREF(m_POname);
//	Py_DECREF(m_POfunctionName);
}
StringParser::~StringParser() {
	Py_Finalize();
}