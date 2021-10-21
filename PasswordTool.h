#pragma once
#include<fstream>

class PasswordTool {
public:
	PasswordTool() {}
	virtual ~PasswordTool() {}

	virtual void Execute() = 0;

protected:
	template<typename T>
	void WriteToFile(const std::string& fileName, std::ios_base::openmode mode, T writeLambda)
	{
		std::fstream file(fileName, mode);
		writeLambda(file);
		file.close();
	}
};

