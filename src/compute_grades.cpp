#include<iomanip>
#include<cmath>  
#include<stdexcept>
#include<algorithm>
#include<sstream>  
#include <numeric> 
#include "compute_grades.hpp"

void Student::validate() const{
     for(int score : quiz) {  
         if(score <  0 || score > 100){  
            throw std::domain_error("Error: invalid percentage " + std::to_string(score)); 
        }
    }

    for(int score : quiz){
      if(score <0 ||  score > 100){  
         throw std::domain_error("Error: invalid percenage " + std::to_string(score)); 
         }
    }

    if(final_score < 0 || final_score > 100){  
        throw std::domain_error("Error: invalid percdentage " + std::to_string(final_score));  
    }
}

void Student::compute_grade() {

         if (quiz.size() > 1) {
         auto min = std::min_element(quiz.begin(), quiz.end());  
         quiz_avg = (std::accumulate(quiz.begin(), quiz.end(), 0) - *min/(quiz.size()-1));  
          }

        else if(quiz.size() ==1){  
            quiz_avg = quiz[0]; 
        } 

         else{
            quiz_avg =0; 
        } 

        hw_avg = (hw.empty()) ? 0 : std::accumulate(hw.begin(), hw.end(), 0) / hw.size();

         course_score = round(quiz_avg * 0.4 + hw_avg * 0.3 + final_score * 0.3);
}

std::strong_ordering Student::operator<=>(const Student& other) const {
    return last_name<=> other.last_name;  
}

 bool Student::operator==(const Student& other) const {
      return (last_name == other.last_name && first_name == other.first_name); 
}

std::istream& operator>>(std::istream& in, Student& s) {
     std::string l;  
     std::getline(in,l);
     std::istringstream iss(l);
     iss >> s.first_name >> s.last_name;

     std::getline(in, l); 
     std::istringstream quiz_stream(l);
     int qscore;
     while(quiz_stream >>qscore){
         s.quiz.push_back(qscore);
     } 

      std::getline(in, l);
      std::istringstream hw_stream(l);
      while(hw_stream >> qscore){
          s.hw.push_back(qscore);
    } 

    std::getline(in,l); 
    std::istringstream fe_stream(l);
    fe_stream >> s.final_score; 

    return in; 

} 

std::ostream& operator<<(std::ostream& out, const Student& s) {
out << std::setw(8) << std::left << "Name: " << s.first_name << " " << s.last_name << std::endl;
out << std::setw(8) << std::left << "HW Ave: " << s.hw_avg << std::endl;
out << std::setw(8) << std::left << "QZ Ave: " << s.quiz_avg << std::endl;
out << std::setw(8) << std::left << "Final: " << s.final_score << std::endl;
out << std::setw(8) << std::left << "Grade: " << s.course_grade << std::endl;
out << std::setw(8) << std::left << "Total: " << s.course_score << std::endl;
out << std::endl;
return out; 
}

void Gradebook::compute_grades(){
    for(auto& s : students){
         s.compute_grade();
    } 
} 

void Gradebook::sort(){
    std::sort(students.begin(), students.end());
}

void Gradebook::validate() const {
     for(const auto& s : students){ 
        s.validate(); 
    }
} 

std::istream& operator>>(std::istream& in, Gradebook& b){
    Student s; 
    while(in>>s){ 
        b.students.push_back(s); 
    }

    return in; 
} 

 std::ostream& operator<<(std::ostream& out, const Gradebook& b){
     for(const auto& student : b.students){  
         out << student;  
    }
    return out; 
}
