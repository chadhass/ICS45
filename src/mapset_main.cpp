#include <fstream> 
#include "mapset.hpp" 

using namesapce std; 

int main(){ 
    ifstream stopwords_file{"stopwords.txt"}; 
    const auto stopwords = load_stopwords(stopwords_file); 

    ifstream document{"sample_doc.txt"}; 
    const auto word_counts = count_Words(document, stopwords); 

    ofstream output{"frequency.txt"}; 
    output_word_counts(word_counts, output); 
}