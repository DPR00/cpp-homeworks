c++ -c -I./include src/subtract.cpp -o build/subtract.o
c++ -c -I./include src/sum.cpp -o build/sum.o
ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o
c++ -std=c++17 -I./include src/main.cpp -L./build -lipb_arithmetic -o results/bin/main
