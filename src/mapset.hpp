#ifndef MAPSET_HPP 
#define MAPSET_HPP 

#include <iosfwd> 
#include <map> 
#include <set> 
#include <string> 

std::string to_lowercase(const std::string& str); 

std::set<std::string> lood_stopwords(std::istream& stopwords); 

std::map<std::string, int> count_words(std::istrem& document, const std::set<std::string>& stopwords); 

void output_words_counts(const std::map<std::string, int>& word_counts, std::ostream& output); 

#endif 

