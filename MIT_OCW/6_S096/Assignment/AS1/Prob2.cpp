#include <iostream>
#include <fstream>
using namespace std;

#define MAXN 300

typedef struct Matrix_s{
    size_t R,C;
    int index[MAXN][MAXN];
} Matrix;

int matValCal(Matrix* m1, Matrix* m2, size_t i, size_t j){
    int sol = 0;
    size_t itr = m1->C;

    for(size_t t = 0; t<itr;t++){
        sol += (m1->index[i][t]) * (m2->index[t][j]);
    }
    return sol;
}

Matrix matMult(Matrix * m1, Matrix * m2){
    Matrix temp;
    temp.R = m1->R;
    temp.C = m2->C;

    for(size_t i = 0; i<temp.R; i++){
        for(size_t j = 0; j<temp.C; j++){
            temp.index[i][j] = matValCal(m1,m2,i,j);
        }
    }
    return temp;
}

void printMat(Matrix* m){
    cout << m->R << " " << m->C << endl;

    for(size_t i = 0; i<m->R; i++){
        for(size_t j = 0; j<m->C; j++){
            cout << m->index[i][j] << " ";
        }
        cout << endl;
    }
}

bool compare_Mat(Matrix* m1, Matrix* m2){
    if((m1->R!=m2->R)||(m1->C !=m2->C))
        return false;
    for(size_t i = 0; i<m1->R; i++){
        for(size_t j = 0; j<m1->C; j++){
            if((m1->index[i][j])!=(m2->index[i][j])){
                return false;
            }
        }
    }
    return true;
}

int main(){
    string path = "C:\\Users\\Daniel\\Desktop\\2015WinterProgramming\\MIT_OCW\\6_S096\\Assignment\\AS1\\matrix.data\\matrix.";

    ifstream ifile;
    ifstream ofile;

    string fileName;
    cout << "Num of input test file : " << endl;
    cin >> fileName;

    ifile.open(path+fileName+".in");
    ofile.open(path+fileName+".out");
    // Input file name and open instance of ifstream

    Matrix mat[4];
    Matrix* matPtr;

    matPtr = mat;

    for(size_t i = 0; i<2;i++){
        ifile >> (matPtr+i)->R >> (matPtr+i)->C;
        for(size_t j = 0; j<(matPtr+i)->R;j++){
            for(size_t k = 0; k<(matPtr+i)->C;k++){
                ifile >> ((matPtr+i)->index[j][k]);
            }
        }
    }

    ofile >> (matPtr+3)->R >> (matPtr+3)->C;
    for(size_t j = 0; j<(matPtr+3)->R;j++){
            for(size_t k = 0; k<(matPtr+3)->C;k++){
                ofile >> ((matPtr+3)->index[j][k]);
            }
    }

    ifile.close();
    ofile.close();

    if(matPtr->C != (matPtr+1)->R){
        cout << "0,0" <<endl;
        return 1;
    }

    mat[2] = matMult(matPtr, (matPtr+1));
    printMat(matPtr+2);

    if(compare_Mat(matPtr+2, matPtr+3))
        cout << "Correct" << endl;
    else
        cout << "Incorrect" << endl;

    return 0;
}