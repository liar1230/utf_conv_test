#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <codecvt>

using namespace std;

std::wstring utf8_to_utf16(std::string utf8_string)
{
	return std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t>{}.from_bytes(utf8_string);
}

std::string utf16_to_utf8(std::wstring utf16_string)
{
	return std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t>{}.to_bytes(utf16_string);
}

int main(int argc, char** argv)
{
	if (argc != 2) {
		cout << "\nUsage: docsample filename\n";
		return 0;
	}
	const char* test_file_path = argv[1];
	std::ifstream in(test_file_path, ios::in | ios::binary);
	std::string inputStr;

	if (in.is_open()) {
		// 위치 지정자를 파일 끝으로 옮긴다.
		in.seekg(0, std::ios::end);

		// 그리고 그 위치를 읽는다. (파일의 크기)
		int size = in.tellg();

		// 그 크기의 문자열을 할당한다.
		inputStr.resize(size);

		// 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
		in.seekg(0, std::ios::beg);

		// 파일 전체 내용을 읽어서 문자열에 저장한다.
		in.read(&inputStr[0], size);
		std::cout << inputStr << std::endl;
	}
	else {
		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
	}

	std::string strA(rawData, rawData + sizeof(rawData));
	std::wstring utf16;

	utf16 = utf8_to_utf16(inputStr);
	unsigned int len = 0;
	len = (unsigned int)utf16.length();


	string filePath = "test.txt";

	// write File
	ofstream writeFile(filePath.data(), ios::out | ios::binary);
	if (writeFile.is_open()) {
		writeFile.write((char*)utf16.data(), utf16.length() * 2);
		writeFile.close();
	}

	return 0;
}

