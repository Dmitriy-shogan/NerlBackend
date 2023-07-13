#pragma comment(lib, "Nerll.lib")
#include "harpy_system/save_sys.h"


int main(int argc, char* argv[])
{
    try
    {
        harpy::system::save_sys testing;
        testing.choose_base_filepath();
        testing.save("DRANICKS.txt", harpy::system::blob(L"Here lies some important руззке алфабет"));
        std::wcout << testing.load(MD5("DRANICKS.txt").hexdigest()) << std::endl;
    }
    catch (std::exception& error)
    {
        std::cerr << error.what() << std::endl;
    }
    return 0;
}
