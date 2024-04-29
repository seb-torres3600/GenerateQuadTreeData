#include <iostream>
#include <fstream>
#include <sstream>

#include <unistd.h>
#include <getopt.h>

#include <nlohmann/json.hpp>

#include <chrono>


int main(int argc, char* argv[]){
    int opt;
    std:: string output_dir = "./data/";
    int rows;
    int cols;

    // Creating the long options
    static struct option long_options[] = {
            {"author",   no_argument,         0,  'a' },
            {"output_dir", required_argument, 0, 'o'},
            {"x_points", required_argument, 0, 'x'}, 
            {"y_points", required_argument, 0, 'y'}, 
            {0, 0, 0, 0}
    };

    while(opt != -1){
        int index = 0;
        opt = getopt_long(argc, argv, "a:o:x:y:", long_options, &index);
        switch (opt){
            case 'a':
                std:: cout << "Author: Sebastian Torres" << std:: endl;
                return 0;
            case 'o':  
                output_dir = optarg;
                break;
            case 'x':
                rows = std::stoi(optarg);
            case 'y':
                cols = std::stoi(optarg);
            default:
                break;
        }
    }

    int id = 0;

    nlohmann::json data = nlohmann::json::array();

    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < cols; i++){
        for(int j = 0; j < rows; j++){
            nlohmann::json tmp;
            tmp["id"] = id++;
            tmp["shape"] = "rectangle";
            nlohmann::json::array();
            tmp["coordinates"] = {j, i, j+1, i+1};
            data.push_back(tmp);
        }
    }
    // Format a string using std::stringstream
    std::stringstream ss;
    ss << output_dir << rows << "x" << cols << ".json";
    std::string file_name = ss.str();
    // Writing JSON data to file
    std::ofstream ofs(file_name);
    ofs << std::setw(4) << data << std::endl;
    ofs.close();
    std::cout << "JSON data has been written to " << file_name << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}