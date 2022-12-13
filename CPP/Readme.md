-> Compiled using --std=gnu++23 (Important because many methods are not implemented in the default selection,
which is usually --std=gnu++17)

-> Decided to not use 'using namespace std' as a personal practice, which may make the programs look more verbose than necessary. In my case, using std:: let's me know without thinking where some name is coming from. This might be more useful when working with several namespaces.

-> Create a 'libraries' folder inside CPP and add necessary libraries from their sources

    BigNumber
    ---------
    1. Open integrated terminal inside 'libraries' then run:
        git clone https://github.com/limeoats/BigNumber

    This should make BigNumber available as a library for GNU g++ compiler, but compiling programs manually using this library is a bit tedious so I have added the necessary g++ comamnd to use for compilation in programs where this library is necessary.

    Otherwise you can also modify 'tasks.json' folder inside .vscode in the root of the project to automatically use the necessary libraries by adding their filepaths following a -I, but that will always use the libraries included for compiling every program going forward, probably not an optimal solution.

Note to self: Consider using CMAKE or MESON?
