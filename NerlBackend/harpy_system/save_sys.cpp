#include "save_sys.h"
#include <filesystem>
#include <thread>
namespace fs = std::filesystem;

bool harpy::system::is_blob(std::string str)
{
    if (str.find_last_of(".blob", str.size() - 6) == std::string::npos) return false;
    return true;
    
}

harpy::system::save_sys::save_sys()
{
    hashiers.resize(std::thread::hardware_concurrency(), {{}, true});
}

void harpy::system::save_sys::save(std::string filename, blob file)
{
    hasher.update(filename.c_str(), filename.size());
    auto hash = hasher.finalize().hexdigest();
    fs::path destination{common_filepath / (hash[0] + hash[1]) / (hash[2] + hash[3])};
}

void harpy::system::save_sys::save(std::string source, std::string destination)
{
    hashiers.load().update(file.c_str(), file.size());
    auto hash = hashiers.load().finalize().hexdigest();
    fs::path dest{destination};
}

blob harpy::system::save_sys::load(std::string hash)
{
    
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
