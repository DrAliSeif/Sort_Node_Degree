# Sort_Node_Degree
Sort number of node from lowest degree to highest degree

----------------------------------


```ruby
Sort number of node from lowest degree to highest degree


node    degree  ---->   node    degree
1       3       ---->   16      0
2       2       ---->   7       1
3       2       ---->   10      1
4       4       ---->   13      1
5       3       ---->   17      1
6       3       ---->   19      1
7       1       ---->   20      1
8       5       ---->   2       2
9       3       ---->   3       2
10      1       ---->   12      2
11      3       ---->   15      2
12      2       ---->   1       3
13      1       ---->   5       3
14      3       ---->   6       3
15      2       ---->   9       3
16      0       ---->   11      3
17      1       ---->   14      3
18      3       ---->   18      3
19      1       ---->   4       4
20      1       ---->   8       5

```
----------------------------------
# Code

```ruby
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
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@                                                                                @@@@
//@@@                                    main                                        @@@@
//@@@                                                                                @@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int main() {                                                                    //main program
	int N = 20;                                                                //number of node
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@                                                                                @@@@
//@@@                           created rand matrix                                  @@@@
//@@@                                                                                @@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    vector_2d_int matrix_file(N, vector_1d_int(N));                            //create 2d vector                         
    random_device rd;                                                           //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd());                                                          //Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<float> uniform_distribution_teta(0.0, 1.0);       //Uniform real distribution from 0 to 1
    for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {      
            if (uniform_distribution_teta(gen) < 0.1) {
                matrix_file[i][j]=1;
            }
            else {

                matrix_file[i][j] = 0;
            }
		}                                                                 
    }
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
```
