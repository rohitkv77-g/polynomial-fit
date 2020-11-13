# polynomial-fit

use generator to generate random test data
- g++ random_data_gen.cpp -o test.out
- ./test.out > data

compile main.cpp and run on test data
- g++ main.cpp -o main.out
- main.out < data
