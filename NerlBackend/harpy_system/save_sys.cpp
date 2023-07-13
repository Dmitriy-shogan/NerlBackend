﻿#include "save_sys.h"
#include <filesystem>
#include <thread>
#include <fstream>
namespace fs = std::filesystem;

bool harpy::system::is_blob(std::string str)
{
    if (str.find_last_of(".blob", str.size() - 6) == std::string::npos) return false;
    return true;
    
}

harpy::system::save_sys::save_sys()
{
    /*hashiers.resize(std::thread::hardware_concurrency(), {{}, true});*/
}

void harpy::system::save_sys::save(std::string filename, blob file)
{
    if (common_filepath.empty())
        throw std::runtime_error("Please, first enter valid directory path where files will be stored");
    
    hasher.update(filename.c_str(), filename.size());
    auto hash = hasher.finalize().hexdigest();

    auto directory {common_filepath
        + static_cast<char> (fs::path::preferred_separator)
        + hash[0]
        + hash[1]
        + static_cast<char> (fs::path::preferred_separator)
        + hash[2]
        + hash[3]};
    auto hash_filename {static_cast<char> (fs::path::preferred_separator) + hash.substr(4)+ ".HHF"}; //Harpy Hashed File
    
    std::wofstream saver{
        directory + hash_filename, 
        std::ios::binary & std::ios::out
    };

    if (!saver.is_open())
    {
        fs::create_directories(directory);
        std::wofstream(directory + hash_filename);
        saver.open(directory + hash_filename);
    }
    
    saver.write(file.data(), file.size());
    saver.close();
}

harpy::system::blob harpy::system::save_sys::load(std::string hash)
{
    std::wifstream getter{std::string(common_filepath.begin(), common_filepath.end())
         + static_cast<char>(fs::path::preferred_separator)
         + hash[0]
         + hash[1]
         + static_cast<char>(fs::path::preferred_separator)
         + hash[2]
         + hash[3]
         + static_cast<char>(fs::path::preferred_separator)
         + hash.substr(4)
         + ".HHF", //HarpyFiLe
         std::ios::binary & std::ios::in};

    std::wostringstream sstr;
    sstr << getter.rdbuf();
    return sstr.str();
}

void harpy::system::save_sys::choose_base_filepath()
{
    std::cout << "Enter valid directory path where data will be stored" << std::endl;
    std::getline(std::cin, common_filepath);
    if (common_filepath.empty())
    {
        throw std::runtime_error("Empty directory has been given while choosing filepath");
    }
}

void harpy::system::save_sys::choose_base_filepath(std::string filepath)
{
    common_filepath = std::move(filepath);
    if (common_filepath.empty())
    {
        throw std::runtime_error("Empty directory has been given while choosing filepath");
    }
}
