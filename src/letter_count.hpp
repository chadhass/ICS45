inline int char_to_index(char ch) {
    return std::toupper(ch) - 'A';
}

inline char index_to_char(int i) {
    return static_cast<char>('A' + i);
}

inline void count(std::string s, int counts[]) {
    for (char& ch : s) {
        if (std::isalpha(ch)) {
            counts[char_to_index(std::toupper(ch))]++;
        }
    }
}

inline void print_counts(int counts[], int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << index_to_char(i) << ' ' << counts[i] << '\n';
    }
}
