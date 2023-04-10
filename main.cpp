#include <iostream>
#include <regex>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

int global_iterator = 0;

std::regex pattern_link("<div class=\\\"r\\\">................(.+?\\.pl)");
std::regex phone_regex("(?:(?:(?:(?:\\+|00)\\d{2})?[ -]?(?:(?:\\(0?\\d{2}\\))|(?:0?\\d{2})))?[ -]?(?:\\d{3}[- ]?\\d{2}[- ]?\\d{2}|\\d{2}[- ]?\\d{2}[- ]?\\d{3}|\\d{7})|(?:(?:(?:\\+|00)\\d{2})?[ -]?\\d{3}[ -]?\\d{3}[ -]?\\d{3}))");//zgadza się, ukradłem, ale tylko frajer by nie skorzystał
std::regex trim("<div class=...><a href=.http...|/");

std::string href_trim(const std::smatch& href){
    std::string href_trimmed;
    href_trimmed = regex_replace(href.str(), trim, "");

    return href_trimmed;
}

auto save_to_csv(std::map<std::string, std::vector<std::string>> test_mapa){
    std::string filename = "scrapped_data_";
    filename.append(to_string(global_iterator));
    filename.append(".csv");

    std::ofstream outputfile(filename);

    for (const auto& row : test_mapa) {
        outputfile << row.first << ",";
        for (const auto& col : row.second) {
            outputfile << col << ",";
        }
        outputfile << endl;
    }

    outputfile.close();

    global_iterator++;

    return outputfile;
}


auto zadanie(std::string filename){

    std::map<std::string, std::vector<string>> map;

    std::ifstream input_file(filename);
    std::stringstream buffer;
    buffer << input_file.rdbuf();
    std::string file_contents = buffer.str();

    std::smatch match;

    std::sregex_iterator it(file_contents.begin(), file_contents.end(), pattern_link);
    std::sregex_iterator endIt;

    std::vector<std::smatch> matches;
    std::vector<std::string> phoneNums;

    while(it != endIt){
        std::smatch match = *it;
        matches.push_back(match);
        ++it;
    }

    for(const auto a : matches){
        std::cout << a.str() << std::endl;
    }

    for(int i = 0; i < matches.size() - 1; i++){
        std::sregex_iterator phoneIt(matches[i].suffix().first, matches[i+1].suffix().first, phone_regex);
        std::cout << matches[i].str() << std::endl;

        while(phoneIt != endIt){
            std::smatch match = *phoneIt;
            std::cout << match.str() << std::endl;

            phoneNums.emplace_back(match.str());

            ++phoneIt;
        }

        map.emplace(href_trim(matches[i]), phoneNums);

        phoneNums.clear();
    }

    std::cout << "\n" << "\n";

    for (const auto& pair : map) {
        std::cout << pair.first << " -> ";
        for (const auto &element: pair.second) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    save_to_csv(map);

    return map;
}

int main() {

    zadanie("plik01.html");
    zadanie("plik02.html");
    
    return 0;
}
