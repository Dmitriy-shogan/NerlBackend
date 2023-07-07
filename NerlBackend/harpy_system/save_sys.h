﻿#pragma once
#ifndef HARPY_FILESAVE_SYS
#define HARPY_FILESAVE_SYS
#include <string>
#include <vector>
#include <atomic>

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
typedef std::vector<wchar_t> blob;


namespace harpy::system
{

    bool NERLL_API is_blob(std::wstring str);

    class NERLL_API save_sys
    {
        static std::wstring common_filepath{};

        //First in pair is hasher, second shows is it free for thread
        std::vector<std::pair<MD5, bool>> hashiers;
    
        
    public:
        save_sys();
        
        /*save_sys& operator=(save_sys save) = default;
        save_sys& operator=(const save_sys& save) = default;
        save_sys& operator=(save_sys&& save) = default;
        save_sys operator=(const save_sys&& save) = default;

        save_sys(save_sys& save) = default;
        save_sys(save_sys&& save) = default;
        save_sys(const save_sys& save) = default;
        save_sys(const save_sys&& save) = default;
        */

        void save(std::string file, blob data);
        
        blob load(std::string hash);

        static void choose_base_filepath();
        static void choose_base_filepath(std::wstring);
        

        
        

        


        ~save_sys() = default;
    };
}



#endif //HARPY_FILESAVE_SYS