#include"Files.h"

string getFileContents(std::ifstream& File)
{
	std::string Lines = "";

	if (File)
	{
		while (File.good())
		{
			std::string TempLine;
			std::getline(File, TempLine);
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