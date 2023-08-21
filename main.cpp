#include <iostream>
//filesystem header
#include <filesystem>
// fstream to create files
#include <fstream>

// viewing the filesystem
std::string cwd() { 
    return std::__fs::filesystem::current_path();
}
// this is for a different style
// / "test#1.txt";

std::__fs::filesystem::path curpath = std::__fs::filesystem::current_path();

int main() {
    /* class usPath: Path { */
    /*  */
    /* }; */
   
    //std::ofstream file(cwd.string());
    //file.close();
    std::cout << "\n          ** Filesystems and C++ **\n\n";

    std::cout << "Current PATH: " << cwd() << std::endl; 
   
    std::cout << "\nNow lets look at the path class\n";

    std::cout << "Parent PATH: " <<curpath.parent_path() << std::endl;

    std::cout << "\nLets create a file, named 'test1.txt'" << std::endl;

    std::ofstream("test1.txt") << "example content..";
    
    std::cout << "File was created" << std::endl;

    //another way to open file
    //std::ifstream myfile;
    //myfile.open("test1.txt");

    // quicker way

    std::cout << "\nNow lets read the file we just created\n" << std::endl;
    std::ifstream myfile("test1.txt");

    if(myfile.is_open()) {
        std::cout << "\n-------------------START-OF-FILE-STREAM------------------------------\n\n";
        std::string line;
        while (std::getline(myfile, line)) {
            // use printf()
            printf("%s", line.c_str());
        };
        myfile.close();
        std::cout << "\n\n------------------END-OF-FILE-STREAM-------------------------------\n";
    }else{
        std::cout << "no file is open, or found" << std::endl;
    };

    return 0;



};
