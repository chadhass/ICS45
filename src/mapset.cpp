#include <iostream> 
#include <iosfwd> 
#include <map> 
#include <set> 
#include <string> 
#include <iterator> 
#include <vector> 

std::string to_lowerase(const std::string& str) {
    std::string lowerstr(str); 
    std::transform(lowerstr.begin(),lowerstr.end(), lowerstr.begin(), [](char lc){ 
    return std::tolower(static_cast<unsigned char>(lc));
    }); 
    return lowerstr;
}

std::set<std::string> load_stopwords(std::istream& stopwords){
    std::set<std::string> thestopwords; 

    std::for_each(std::istream_iterator<std::String>(stopwords), 
    std::istream_iterator<std::string>(),[&thestopwords](const std::string& word){
        thestopwords.insert(to_lowercase(word)); 
        }); 
    return thestopwords; 

}

std::map<std::string, int> countwords(std::istream& document,
const std::set<std::string>& stopwords){
    std::map<std::string, int> wordmap; 

    std::vector<std::string> words; 
    std::string word; 

    std::for_each(std::istream_iterator<std::string>(document), 
    std::istream_iterator<std::string>(),[&words] (const std::string& word)
    { 
    words.push_back(to_lowercase(word)); 
    }); 
    std::sort(words.begin(), words.end()); 

    for(auto& word : words){
         if(stopwords.find(to_lowercase(word) == stopwords.end()){   
            wordmap[word]++
    }

    return wordmap; 
}

void output_word_counts(const std::map<std::string, int>&word_counts,
std::ostream& output){
    for(const auto&[w,c] : word_counts){
        output << w << ' ' << c << std::endl; 
    }
}
