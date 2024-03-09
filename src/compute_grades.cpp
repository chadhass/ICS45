#include<iomanip>
#include<cmath>  
#include<stdexcept>
#include<algorithm>
#include<sstream>  
#include<numeric> 
#include<string> 
#include<set>
#include<fstream> 
#include<iterator> 
#include<iostream> 
#include<vector>
#include "compute_grades.hpp"

void Student::validate() const{
    std::for_each(this->quiz.begin(), this->quiz.end(),[](int qs){
        if(qs <0 || qs >100){ 
            throw std::domain_error("Error: invalid percentage " +std::to_string(qs)); 
        } 
    }); 
    std::for_each(this->hw.begin(), this-> hw.end(), [](int hw){ 
        if(hw<0 || hw > 100){ 
            throw std::domain_error("Enter: invalid percentage "+std::to_string(hw)); 
        }
    }); 
    if(this->final_score <0 || this ->final_score > 100){ 
        throw std::domain_error("Error invalid percentage " + std::to_string(this->final_score)); 
    }
}


std::strong_ordering Student::operator<=>(const Student& other) const {
    if(auto comp = course_score <=> other.course_score; comp != std::strong_ordering::equal){ 
        return comp; 
    } 
    if(auto comp = first_name <=> other.first_name; comp != std::strong_ordering::equal){ 
        return comp; 
    }
    return last_name <=> other.last_name; 
}

 bool Student::operator==(const Student& other) const {
      return (this->course_score == other.course_score) ? true : false;
}

std::istream& operator>>(std::istream& in, Student& s) {
     std::string l;  
     std::vector<std::string> lines; 
     while(std::getline(in, l) && !l.empty()){ 
        lines.push_back(l); 
    } 

    std::for_each(lines.begin(), lines.end(), [&s](const std::string& l){ 
        std::istringstream iss(line); 
        std::string key;
        iss >>key; 
        if(key =="Name"){ 
            iss >> s.first_name >> std::ws; 
            std::getline(iss, s.last_name); 
        } 
        else if(key == "Quiz"){ 
            s.quiz = std::vector<int>(std::istream_iterator<int>(iss), std::istream_iterator<int>()); 
        } 
        else if(key == "HW"){ 
            s.hw = std::vector<int>(std::istream_iterator<int>(iss), std::istream_iterator<int>()}; 
        } 
        else if(key == "Final"){ 
            iss >> s.final_score; 
        } 
    }); 

    s.compute_grade(); 
    return in; 
} 

std::ostream& operator<<(std::ostream& out, const Student& s) {
out << std::setw(8) << std::left << "Name: " << s.first_name << " " << s.last_name << "\n" << std::setw(8) << "HW Ave: " << std::fixed << std::setprecision(2) << s.hw_avg << "\n" <<std::setw(8) << "QZ Av: " << std::fixed << std::setprecision(2) << s.quiz_avg << "\n" << std::setw(8) << "Final: " << s.final_score << "\n" << std::setw(8) << "Total: " << s.course_score << "\n" <<std::setw(8) << "Grade: " << s.course_grade << "\n" << "\n"; 
return out; 
}

void Student::compute_quiz_avg(){ 
    if(this->quiz.empty()){ 
        return; 
    } 
    bool multipleScores = this->quiz.size() >= 2; 

    int minVal = -1; 

    if(multipleScores){ 
        minVal = this->quiz[0]; 
        std::for_each(this->quiz.begin(),this->quiz.end(), [&](int qs){if(minVal >= qs){
            minVal = qs; 
        }
        }); 
    int quizSum =0; 
    std::for_each(this->quiz.begin(), this->quiz.end(),[&](int qs){if(minVal >= qs){ 
        quizSum +=  qs; 
    } 
    }); 
    if(multipleScores){ 
        this->quiz_avg = quizSum/(this->quiz.size()-1); 
    }
    else{ 
        this->quiz_avg = quizSum/(this->quiz.size()); 
    }
} 

void Student::compute_hw_avg(){ 
    int hwSum = 0; 
    std::for_each(this->hw.begin(),this->hw.end(),[&](int hw){ 
        hwSum += hw; 
    }); 
    this->hw_avg = hwSum/currSum/this->hw.size(); 
}

void Sudent::compute_course_score(){ 
    this->compute_hw_avg(); 
    this->compute_quiz_avg(); 
    this->course_score = (int(0.4 * this->quiz_avg + 0.3 * this->hw_avg + 0.3 * this->final_score +0.5); 
} 
void Student::compute_grade(){ 
    this->compute_course_score(); 
    std::string g; 
    int score = this->course_score; 
    if(score >= 97){ 
        g = "A+";
    }
    else if(score >= 93){ 
        g  = "A"; 
    } 
    else if(score >= 90){ 
        g = "A-"; 
    } 
    else if(score >= 87){ 
        g = "B+"; 
    }
    else if(score >= 83){ 
        g = "B"; 
    } 
    else if(score >= 80){ 
        g = "B-"; 
    } 
    else if(score >= 77){ 
        g = "C+";
    } 
    else if(score >= 73){ 
        g = "C"; 
    }
    else if(score >= 70){
        g = "C-"; 
    } 
    else if(score >= 67){ 
        g = "D+"; 
    } 
    else if(score >= 63){ 
        g = "D"; 
    } 
    else if(score >= 60){ 
        g = "D-"; 
    } 
    else{ 
        g = "F"; 
    }
    this->course_Grade = g; 
}


void Gradebook::compute_grades(){} 

void Gradebook::sort(){}

void Gradebook::validate() const {} 

std::istream& operator>>(std::istream& in, Gradebook& b){
    while(in.peek() != EOF){ 
        Student stu; 
        in >> student; 
        if(in){ 
            g.student.push_back(student); 
        } 
    } 
    return in; 
} 

 std::ostream& operator<<(std::ostream& out, const Gradebook& b){
    for(const Student& s : g.students){ 
        std::cout << "logging for student " << std::endl; 
        out <<s; 
    } 
    return out; 
 }
