#include "stdafx.h"
#include "oUnmanaged_Reader.h"

namespace oNativeLib
{
	//Constructor 
	oUnmanaged_Reader::oUnmanaged_Reader(char * filePtr)
	{
		fileName = filePtr;	//Set the file name
	}

	oUnmanaged_Reader::~oUnmanaged_Reader()
	{
		delete fileName;	//delete file name
	}

	string oUnmanaged_Reader::oReadAllLines()
	{
		string line = "";						//The lines we read will be set here
		stringstream stringBuilder;				//This is our string builder where values will be append to
		ifstream file = ifstream(fileName);		//initialize a new stream
		if (file)
		{
			while (getline( file, line ))
				stringBuilder << line+"\r\n";
			file.close();
		}
		return stringBuilder.str();
	}

	string oUnmanaged_Reader::oReadLine(int line)
	{
		string lineString = "";
		ifstream file = ifstream(fileName);
		if (file)
		{
			int current = 0;					//The current line
			while (getline( file, lineString ))
			{
				if(line == current)break;		//Break from the loop if we reach what we want
				else current++;
			}
			file.close();
		}
		return lineString;
	}
}

