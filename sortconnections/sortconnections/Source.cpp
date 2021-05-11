#include<iostream>                                                              //for cout
#include<vector>                                                                //for vector
#include <fstream>                                                              //infile
#include<algorithm>                                                             // for sort()
#include <random>                                                               //random_device & ...
#include <chrono>                                                               //chrono
using namespace std;                                                            //using standard 
typedef std::vector<int> vector_1d_int;                                         //define type of vector integer one dimensional
typedef std::vector<vector_1d_int> vector_2d_int;                               //define type of vector integer two dimensional
using vec2i = vector<vector<int>>;                                              //using of vector integer two dimensional
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@                                                                                @@@@
//@@@                         read matrix connection                                 @@@@
//@@@                                                                                @@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void matrix(int size_matrix, const std::string address_matrix, vec2i& a) {      //read matrix connection 
    vector_2d_int matrix_2d;                                                    //create vector integer two dimensional(matrix_2d)
    std::ifstream ifile(address_matrix + ".txt");                               //read address of file .txt
    if (ifile.is_open()) {                                                      //if file was available 
        vector_1d_int matrix_1d;                                                //create vector integer one dimensional(matrix_1d)
        int num;                                                                //create integer number(num)
        while (ifile >> num) {                                                  //Set the read number of the file to the defined integer(num)
            matrix_1d.push_back(num);                                           //set defined integer(num) into the One after the last cell vector integer one dimensional(matrix_1d)
            if (matrix_1d.size() == size_matrix) {                              //if size of vector is full
                matrix_2d.push_back(matrix_1d);                                 //set vector integer one dimensional(matrix_1d) into the One after the last cell vector integer tow dimensional(matrix_2d)
                matrix_1d.clear();                                              //clean all cels of vector integer one dimensional(matrix_1d) and delete it
            }                                                                   //
        }                                                                       //
    }                                                                           //
    else {                                                                      //else if file wasn't available
        std::cout << "There was an error opening the input file!\n";            //print "..."
        exit(1);                                                                //means program(process) terminate normally unsuccessfully..
    }                                                                           //
    for (int i = 0; i < size_matrix; i++) {                                     //loop for from 0 to 200 for row
        for (int j = 0; j < size_matrix; j++) {                                 //loop for from 0 to 200 for clumn
            a[i][j] = matrix_2d[i][j];                                          //move data matrix in to the  matrix_file pointer 2D
        }                                                                       //
    }                                                                           //
    matrix_2d.clear();                                                          //remove vectore
}                                                                               //
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@                                                                                @@@@
//@@@                                    main                                        @@@@
//@@@                                                                                @@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int main() {                                                                    //main program
	int N = 200;                                                                //number of node
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@                                                                                @@@@
//@@@                                read matrix                                     @@@@
//@@@                                                                                @@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    vector_2d_int matrix_file(N, vector_1d_int(N)) ;                            //create 2d vector                         
    matrix(N, "matrix-SF-DAG1src-2", matrix_file);                              //call read matrix
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@                                                                                @@@@
//@@@                           created rand matrix                                  @@@@
//@@@                                                                                @@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    /*random_device rd;                                                           //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd());                                                          //Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<float> uniform_distribution_teta(0.0, 1.0);       //Uniform real distribution from 0 to 1
    for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {      
            if (uniform_distribution_teta(gen) < 0.02) {
                matrix_file[i][j]=1;
            }
            else {

                matrix_file[i][j] = 0;
            }
		}                                                                 
    }*/
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@                      create number and degree input                            @@@@
//@@@                       in to the old and new vector                             @@@@
//@@@                     and sort new degree input vector                           @@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    vector_2d_int input(2, vector_1d_int(N));
    vector_2d_int input_new(2, vector_1d_int(N));
    for (int i = 0; i < N; i++) {                                   
        for (int j = 0; j < N; j++) {                              
            if (matrix_file[i][j] > 1.e-8) {
                input[1][i]++;
            }
        }                                                          
        input[0][i] = i + 1;
        input_new[0][i] = input[0][i];
        input_new[1][i] = input[1][i];
    }
    sort(input_new[1].begin(), input_new[1].end());
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@                                                                                @@@@
//@@@                     save number data with sort with repeat                     @@@@
//@@@                                                                                @@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    vector_1d_int save;
    for (int i = 0; i < N; i++) {
        for (int j= 0; j < N; j++) {
            if (input_new[1][i] == input[1][j] ) {
                save.push_back(j + 1);
            }
        }
    }
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@                                                                                @@@@
//@@@                           calculate number of repeat                           @@@@
//@@@                                                                                @@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    vector_1d_int conter;
    vector_1d_int number;
    int x = -1;
    int y = 1;
    for (int i = 0; i < N; i++) {
        if (x!= input_new[1][i]) {
            conter.push_back(input_new[1][i]);
            x = input_new[1][i];
            y = 1;
            number.push_back(y);
        }
        else {
            y++;
            number.back() = y;
        }
    }
    vector_1d_int sumber(number.size());
    int sum = 0;
    for (int i = 0; i < number.size(); i++) {
        sum += pow(number[i], 2);
        sumber[i] = sum - 1;
    }
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@                                                                                @@@@
//@@@                                 remove repeat                                  @@@@
//@@@                                                                                @@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    vector_1d_int inc;
    int d = 0;
    for (int i = 0; i <= sumber[0]; i++) 
    {
        if (d < number[0]) {

            inc.push_back(save[i]);

        }
        d++;
    }
    for (int j = 0; j < number.size()-1; j++) {
        d = 0;
        for (int i = sumber[j]; i < sumber[j+1]; i++) {
            if ( d < number[j+1] ) {
                inc.push_back(save[i + 1]);
            }
            d++;
        }
    }
    for (int i = 0; i < N; i++) {
        input_new[0][i] = inc[i];

    }
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@                                                                                @@@@
//@@@                                     print data                                 @@@@
//@@@                                                                                @@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    cout << "Sort number of node from lowest degree to highest degree" << endl;
    cout << endl<<endl<< "node\tdegree\t---->\tnode\tdegree" <<endl;
    for (int i = 0; i < N; i++) {
        cout << input[0][i] << '\t' << input[1][i] << "\t---->\t" << input_new[0][i] << '\t' << input_new[1][i]  << endl;
    }
	return 0;
}