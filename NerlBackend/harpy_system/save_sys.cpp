#include "save_sys.h"
#include <filesystem>
#include <thread>
#include <fstream>
namespace fs = std::filesystem;

bool harpy::system::is_blob(std::wstring str)
{
    if (str.find_last_of(L".blob", str.size() - 6) == std::string::npos) return false;
    return true;
    
}

harpy::system::save_sys::save_sys()
{
    hashiers.resize(std::thread::hardware_concurrency(), {{}, true});
}

void harpy::system::save_sys::save(std::string filename, blob file)
{
    std::jthread sub_thread{[this, filename, file]()
    {
        MD5* hasher{nullptr};
        int i = 0;
        
        while (!hasher)
        {
            if (i == hashiers.size())
            {
                i = 0;
                continue;
            }
            
            if(hashiers[i].second)
            {
                hasher = &hashiers[i].first;
                hashiers[i].second = false;
                break;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            i++;
        }
        
        hasher->update(filename.c_str(), filename.size());
        auto hash = hasher->finalize().hexdigest();
        std::wstring w_hash {hash.begin(), hash.end()};
        std::wofstream saver{common_filepath
            + fs::path::preferred_separator
            + w_hash[0]
            + w_hash[1]
            + fs::path::preferred_separator
            + w_hash[2]
            + w_hash[3]
            + fs::path::preferred_separator
            + w_hash.substr(4)
            + L".HFL", //HarpyFiLe
            std::ios::binary & std::ios::out
        };
        saver.write(file.data(), file.size());
        saver.close();
        hashiers[i].second = true;
    },
    };
    sub_thread.detach();

    
}

blob harpy::system::save_sys::load(std::string hash)
{
    std::ifstream getter{std::string(common_filepath.begin(), common_filepath.end())
         + static_cast<char>(fs::path::preferred_separator)
         + hash[0]
         + hash[1]
         + static_cast<char>(fs::path::preferred_separator)
         + hash[2]
         + hash[3]
         + static_cast<char>(fs::path::preferred_separator)
         + hash.substr(4)
         + ".HFL", //HarpyFiLe
         std::ios::binary & std::ios::out};
    
}

void harpy::system::save_sys::choose_base_filepath()
{
    std::cout << "Enter valid directory path where data will be stored" << std::endl;
    std::getline(std::wcin, common_filepath);
    if (common_filepath.empty())
    {
        throw std::runtime_error("Empty directory has been given while choosing filepath");
    }
}

void harpy::system::save_sys::choose_base_filepath(std::wstring filepath)
{
    common_filepath = std::move(filepath);
    if ()
    if (common_filepath.empty())
    {
        throw std::runtime_error("Empty directory has been given while choosing filepath");
    }
}
