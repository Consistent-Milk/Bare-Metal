# Before fmt was added using MSYS2 this was the process of compiling:
# g++ --std=gnu++23 -I ../libraries/fmt/include 3_06.cpp ../libraries/fmt/src/format.cc -o 3_06.exe
# 3_06.exe
# Now:
g++ --std=gnu++23 3_06.cpp -o 3_06.exe
3_06.exe