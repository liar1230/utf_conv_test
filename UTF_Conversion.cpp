#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

std::wstring utf8_to_utf16(std::string utf8_string)
{
	return std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t>{}.from_bytes(utf8_string);
}

std::string utf16_to_utf8(std::wstring utf16_string)
{
	return std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t>{}.to_bytes(utf16_string);
}

int main()
{
	// UTF-8 data. The character U+1d10b, musical sign segno, does not fit in UCS2
	unsigned char rawData[13] = {
		0xEF, 0xBB, 0xBF, 0x74, 0x65, 0x73, 0x74, 0xEC, 0x95, 0x88, 0xEB, 0x85,
		0x95
	}; //test안녕

	std::string strA(rawData, rawData + sizeof(rawData));
	std::wstring utf16;

	utf16 = utf8_to_utf16(strA);

	return 0;
}
