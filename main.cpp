#include <iostream>
#include <string>

#include <boost/program_options.hpp>

#define FASTRW_IMPLEMENTATION
#include "fastrw.hpp"

int main(int argc, const char *argv[]) {
    namespace po = boost::program_options;
    
    std::string usage("./tester --source <cpp-source-file> --input <input-file> "
        "--output <output-file> --test <path/to/tests/folder>");

    try {
        po::options_description desc("USAGE: " + usage + "\nAllowed options");
        desc.add_options()
            ("help", "Produce this help message");

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);    
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}