#include "save_sys.h"

bool harpy::system::is_blob(std::string str)
{
    if (str.find_last_of(".blob", str.size() - 6) == std::string::npos) return false;
    return false;
}
