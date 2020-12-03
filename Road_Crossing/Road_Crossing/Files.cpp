#include"Files.h"

string getFileContents(ifstream& File)
{
	string Lines = "";

	if (File)
	{
		while (File.good())
		{
			string TempLine;
			getline(File, TempLine);
			TempLine += "\n";

			Lines += TempLine;
		}
		return Lines;
	}
	else
	{
		return "ERROR File does not exist.";
	}
}