#ifndef MATRIX_HPP
#define MATRIX_HPP 

#include "array.hpp"

template <typename  T>
class Matrix{
public: 

    Matrix(): rows(0), cols(0){}  //Construct 0x0 matrix 
    //construct matrix with given number of rows and columns. 
    Matrix(int rows, int cols): rows(rows), cols(cols){
        data = Array<Array<T>>{rows}; 
        for(int rw =0; rw<rows; ++rw){ 
            data[rw] = Array<T>{cols}; 
        }
    }
    //Get a particular row of the matrix 
    Array<T>& operator[](int row){return data[row];}

    const Array<T>& operator[](int row) const{return data[row];}
    //Get number of rows/columns 
    int num_rows() const{return this->rows;}
    int num_cols() const{return this->cols;}
    //Fill every entry of the matrix with given value 'val'
    void fill(const T& val){
        for(int rw = 0; rw<this->rows; ++rw){
            for(int cl = 0; cl<cols; ++cl){
                data[rw][cl];
            }
        }
    }
    //Fil the matrix to set entry to row i nd column j to fn(i,j)
    template <typename Fn> 
    void fill_with_fn(Fn fn){
        for (int rw = 0; rw<this->rows; ++rw) {
            for(int cl = 0; cl<cols; ++cl){
                data[rw][cl] = fn(rw, cl); 
            }
        }
    }
private:
    int rows, cols; 
    Array<Array<T>> data; 
}; 
//Print matrix to out, Each row should be printed as a seperate time
template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix){
for (int r = 0; r<matrix.num_rows(); ++r) {
    for (int c = 0; c<matrix.num_cols(); ++c) {
        out << matrix[r][c] << '\t';
    }
    out << '\n';
    }
    return out;
}
//Read matriz from in, Assume the matrix is in a format like 
//      1 2 3
//      4 5 6  
//for a 2-row, 3-column matrix format. 
template <typename T>
std::istream& operator>>(std::istream& in, Matrix<T>& matrix){
    T val; 
    for(int i =0; i<matrix.num_rows(); ++i){ 
        for(int col =0; c<matrix.num_cols(); ++col){
            if(in>>val){ 
                matrix[i][col] = val;
            }
        }
    }
    return in; 
}
 #endif 
