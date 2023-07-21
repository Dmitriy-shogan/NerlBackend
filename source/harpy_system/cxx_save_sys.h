#pragma once
#ifndef HARPY_FILESAVE_SYS
#define HARPY_FILESAVE_SYS
#include <string>

#include "hash/MD5.h"

/* Common workflow will be like this:
 * 1) Here comes blob
 * 2) Hash everything else.
 * 3) Save file into the directory of first two letters of hash and into the directory of two second.
 * 4) OPTIONAL MOVE if defined HARPY_OPTIONAL_HASH_FILE, we will save HASH.FILE along with file to remain information like name, extension and data of original file.
 * 
 *
 *
 */

namespace harpy::system
{
    using blob = std::string;
    
    bool is_blob(std::string str);

    class cxx_save_sys
    {
        std::string common_filepath;

        //NOT IMPLEMENTED YET
        //First in pair is hasher, second shows is it free for thread
        /*std::vector<std::pair<MD5, bool>> hashiers;*/
        MD5 hasher{};
    
        
    public:
        cxx_save_sys();
        
        /*cxx_save_sys& operator=(cxx_save_sys save) = default;
        cxx_save_sys& operator=(const cxx_save_sys& save) = default;
        cxx_save_sys& operator=(cxx_save_sys&& save) = default;
        cxx_save_sys operator=(const cxx_save_sys&& save) = default;

        cxx_save_sys(cxx_save_sys& save) = default;
        cxx_save_sys(cxx_save_sys&& save) = default;
        cxx_save_sys(const cxx_save_sys& save) = default;
        cxx_save_sys(const cxx_save_sys&& save) = default;
        */

        void save(std::string file, blob data);
        
        blob load(std::string hash);

        void choose_base_filepath();
        void choose_base_filepath(std::string);
        ~cxx_save_sys() = default;
    };
}



#endif //HARPY_FILESAVE_SYS