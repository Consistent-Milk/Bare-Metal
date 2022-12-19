# This program only works with CPP Standard 14
# Newer Standards produce segmentation faults
# a probable reason maybe using string instead of string_view
# in struct student and other member access issues that
# were introduced in later standards
g++ --std=gnu++14 Program.cpp -o Program.exe
Program.exe
remove-item Program.exe