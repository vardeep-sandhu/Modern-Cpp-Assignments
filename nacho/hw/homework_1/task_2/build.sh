rm -rf build/
mkdir build/
# Make object files for the implementations

c++ -std=c++17 -c src/sum.cpp -I ./include/ -o ./build/sum.o
c++ -std=c++17 -c src/subtract.cpp -I ./include/ -o ./build/subtract.o

# Make archive 
ar rcs ./build/libipb_arithmetic.a ./build/sum.o ./build/subtract.o

# connecting the main.cpp with the created lib and the includes.
c++ -std=c++17 src/main.cpp -I ./include/ -L./build -lipb_arithmetic -o main