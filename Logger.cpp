#include "Logger.h"
#include <iostream>
using namespace std;

Logger::~Logger(){
	Close();
}

void Logger::Open(const char* filename){
	fout.open(filename);
}

bool Logger::Fail(){
	return fout.fail();
}

void Logger::Close(){
	fout.close();
}

void Logger::Log(const string message){
	fout << message;
}

Logger& Logger::operator<<(const string message){
	Log(message);
	return (*this);
}

Logger& Logger::operator<<(const char c){
	fout << c;
	return (*this);
}

Logger log;