#include <iostream>
#include <string>
#include <unordered_map>
#include <boost/locale.hpp>
//#include <Windows.h>

std::wstring translit(const std::wstring& input) {
    const std::unordered_map<wchar_t, std::wstring> translit = { // had to change to wstring because of error
        { L'À', L"A" }, { L'Á', L"B" }, { L'Â', L"V" }, { L'Ã', L"G" }, //for example
    };

    std::wstring result; //used algorythm from habr
    for (wchar_t ch : input) {
        if (translit.count(ch)) {
            result += translit.at(ch);
        }
        else {
            result += ch;
        }
    }

    return result;
}
std::string convert_locale_to_utf(const std::string& string) //copied from seminar code
{
    boost::locale::generator generator;
    generator.locale_cache_enabled(true);

    std::locale locale =
        generator(boost::locale::util::get_system_locale());

    return boost::locale::conv::to_utf <char>(string, locale);
}

std::string convert_utf_to_locale(const std::string& string) //copies from seminar code
{
    boost::locale::generator generator;
    generator.locale_cache_enabled(true);

    std::locale locale =
        generator(boost::locale::util::get_system_locale());

    return boost::locale::conv::from_utf <char>(string, locale);
}
int main() {
    std::string str = "ÀÁÂÃ";

    std::string utf8 = convert_locale_to_utf(str);//from windows-1251 to utf-8
    std::cout << utf8 << std::endl;
    std::wstring utf32 = boost::locale::conv::utf_to_utf<wchar_t>(utf8);//from utf_8 to utf-32

    std::wstring transliterate = translit(utf32);//transliterate

    std::string utf8_transliterate = boost::locale::conv::utf_to_utf<char>(transliterate);//to utf-8
    std::string result = convert_utf_to_locale(utf8_transliterate);//urf to windows-1251
    std::cout << result << std::endl;
    return 0;
}
