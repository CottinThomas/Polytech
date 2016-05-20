Compile
-------

mkdir build
cd build
cmake .. # -DDISABLE_TESTS=TRUE
         # -DCMAKE_BUILD_TYPE=Release
         # -DCMAKE_BUILD_TYPE=Debug
make


Compile & Run tests/sum test
-------------------------------

make && ./test__sum # --test
