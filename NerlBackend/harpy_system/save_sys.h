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

    bool NERLL_API is_blob(std::string str);

    class NERLL_API save_sys
    {
        
    public:
        save_sys() = default;
        
        /*save_sys& operator=(save_sys save) = default;
        save_sys& operator=(const save_sys& save) = default;
        save_sys& operator=(save_sys&& save) = default;
        save_sys operator=(const save_sys&& save) = default;

        save_sys(save_sys& save) = default;
        save_sys(save_sys&& save) = default;
        save_sys(const save_sys& save) = default;
        save_sys(const save_sys&& save) = default;
        */

        
        

        


        ~save_sys() = default;
    };
}



#endif //HARPY_FILESAVE_SYS