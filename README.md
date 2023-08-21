 ## CMAKE basic project example

cd into build directory and `cmake ..`

after cmake finishes, command to build binary `cmake --build .`

#### Debugging

cd into build and `cmake -DCMAKE_BUILD_TYPE=Debug`



## add a .clangd file to main project directory

inside the .clangd add this so you dont get pre c++ 17 errors
```
CompileFlags:
  Add: [-xc++, -std=c++17, -Wall, -Wno-missing-prototypes]
```

===================================================================================


## CPLUSPLUS VERSION
> how to view cur directory/path is different depending on the version of 

```
#include <iostream>

#if __cplusplus >= 201703L
// code for C++17 and later
#include <filesystem>
std::string cwd() { return std::filesystem::current_path(); }

#else
// code for earlier versions of c++
#include <unistd.h>
std::string cwd() {
    char buffer[FILENAME_MAX];
    if (getcwd(buffer, FILENAME_MAX) != nullptr) {
        return {buffer};
    }
    return "";
}
#endif


int main() {
    std::cout << cwd();
}

```

## Linux/Unix systems you can do this

```
#include <iostream>
#include <unistd.h>
#include <limits.h>

// ONLY WORKING IN UNIX-LIKE SYSTEMS SUCH AS LINUX
int main() {
    char cwd[PATH_MAX];
    ssize_t size = readlink("/proc/self/cwd", cwd, sizeof(cwd));
    if (size != -1) {
        cwd[size] = '\0'; // Null-terminate the string
        std::cout << "current working directory: " << cwd << std::endl;
    } else {
        std::cerr << "failed to read cwd" << std::endl;
    }

    return 0;
}

```

## windows version .. not tested

```
#include <windows.h>
#include <string>
#include <iostream>

std::wstring ExePath() {
    TCHAR buffer[MAX_PATH] = { 0 };
    GetModuleFileName( NULL, buffer, MAX_PATH );
    std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
    return std::wstring(buffer).substr(0, pos);
}

int main() {
    std::cout << "my directory is " << ExePath() << "\n";
}

```

 
 
 
 
