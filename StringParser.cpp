#include "StringParser.h"

StringParser::StringParser() {

}

void StringParser::init() {
	const char m_ccpluginName[] = "parser";

	Py_Initialize();
	//build c string to py object string
	m_pName = Py_BuildValue("s", m_ccpluginName);
	//load module into py object
	m_pModule = PyImport_Import(m_pName);
}

void StringParser::parseString(std::vector < int > &i_commands, std::string s_command) {

}

void StringParser::close() {
	Py_Finalize();
	Py_DECREF(m_pModule);
	Py_DECREF(m_pName);
}
StringParser::~StringParser() {
}