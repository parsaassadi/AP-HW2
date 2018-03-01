
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <streambuf>


//scan the string, break string into multiple strings
//cutpoints are "-" in strings
std::vector<std::string> split_1( const std::string& text);

/*scan the string,if it is normal, break string into multiple strings,
cutpoints are these characters "aeiouAEIOU" in strings*/
std::vector<std::string> split_2(const std::string& text);

//check if the word is normal (consist of alphabetic letters only)
bool is_normal(const std::string& word);

//check if a normal string contains 5 or more silenced letter in a row
bool check_normal_str(const std::string& word);

//check if a string contains 5 or more silenced letter in a row
bool check_str(const std::string& word);

//display a vector of strings (just for checking and debugging)
void show(const std::vector<std::string>& s);


int main()
{
    //read the whole file as a string
    std::ifstream t("Error_find.txt");
    std::string str{};

    t.seekg(0, std::ios::end);
    str.reserve(t.tellg());
    t.seekg(0, std::ios::beg);

    str.assign((std::istreambuf_iterator<char>(t)),
               std::istreambuf_iterator<char>());


    //scan the file and split the words
    std::string text{str};
    const std::string separators{ " *(),;:.\"!?'\n" };
    std::vector<std::string> words;
    size_t start { text.find_first_not_of(separators) };
    size_t end {};

    //this loop save words
    while (start != std::string::npos)
    {
        end = text.find_first_of(separators, start + 1);
        if (end == std::string::npos)
            end = text.length();

        words.push_back(text.substr(start, end - start));    // Store the word
        start = text.find_first_not_of(separators, end + 1); // Find 1st character of next word
    }
    t.close();

    std::cout << "All words:" << "\n" << "-------------------" << "\n";
    show(words);
    std::cout << "\n";

    //applying check_str to each word
    std::cout << "Corrupted words:" << "\n" << "-------------------" << "\n";
    for (size_t i = 0; i < words.size(); i++)
    {
        if(check_str(words[i]))
        {
            std::cout << words[i] << "\n";
        }

    }
    return 0;
}

std::vector<std::string> split_1( const std::string& text)
{
    //thing that must be ignored:
    const std::string separators{ " -_@/*(),;:.\"!?'\n" };
    std::vector<std::string> words{};
    size_t start { text.find_first_not_of(separators) };
    size_t end {};

    //this loop split the word and put pieces in a vector
    while (start != std::string::npos)
    {
        end = text.find_first_of(separators, start + 1);
        if (end == std::string::npos)
            end = text.length();

        words.push_back(text.substr(start, end - start));
        start = text.find_first_not_of(separators, end + 1);
    }
    return words;
}

std::vector<std::string> split_2(const std::string& text)
{
    //thing that must be ignored:
    const std::string separators{ " aeiouAEIOU" };
    std::vector<std::string> words{};
    size_t start { text.find_first_not_of(separators) };
    size_t end {};

    //this loop split the word and put pieces in a vector
    while (start != std::string::npos)
    {
        end = text.find_first_of(separators, start + 1);
        if (end == std::string::npos)
            end = text.length();

        words.push_back(text.substr(start, end - start));
        start = text.find_first_not_of(separators, end + 1);
    }
    return words;
}

bool is_normal(const std::string& word)
{
    for (size_t i{}; i < word.size(); i++)
    {
        if(!isalpha(word[i]))
        {
            return false;
        }
    }
    return true;
}

bool check_normal_str(const std::string& word)
{
    int cnt{};
    std::vector<std::string> canc{};
    canc=split_2(word);
    for (size_t i{}; i < canc.size(); i++)
    {

        //ignore words less than 5 characters
        if(canc[i].size() < 5)
        {
            continue;
        }

            //check if it consists of 5 or more silenced letter
        else
        {
            for (size_t j{}; j < canc[i].size(); j++)
            {
                if(islower(canc[i][j]))
                {
                    cnt++;
                }
                else
                {
                    cnt = 0;
                }

            }
        }

    }
    if(cnt > 4)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool check_str(const std::string& word)
{
    if(is_normal(word))
    {
        return check_normal_str(word);
    }
    else
    {
        std::vector <std::string> canc{};
        canc = split_1(word);
        for (size_t k = 0; k < canc.size(); k++)
        {
            if (check_normal_str(canc[k]))
            {
                return true;
            }
        }
        return false;
    }

}

void show(const std::vector<std::string>& s)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        std::cout << s[i] << "\n";
    }
}


