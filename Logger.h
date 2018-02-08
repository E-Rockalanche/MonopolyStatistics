#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
using namespace std;

class Logger{
private:
	ofstream fout;

public:
	~Logger();
	void Open(const char* filename);
	bool Fail();
	void Close();
	void Log(const string message);
	Logger& operator<<(const string message);
	Logger& operator<<(const char c);
};

extern Logger log;

#endif