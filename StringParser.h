#ifndef STRING_PARSER_H
#define STRING_PARSER_H

#include <string>
#include <Python.h>
#include <vector>

#include <iostream>


class StringParser {
private:
	std::string m_scommand;
	std::vector < int > m_icommands;

	//Py Objects
	PyObject *m_POname, *m_POmodule, *m_POfunctionName, *m_POvalues;
	//gil state
	PyGILState_STATE m_gstate;

public:
	StringParser();
	~StringParser();

	void init();
	void close();
	void parseString(std::vector < int > &i_commands, std::string s_command);
};

#endif