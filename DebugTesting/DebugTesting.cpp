#include "harpy_system/save_sys.h"


int main(int argc, char* argv[])
{
    harpy::system::save_sys testing;
    try
    {
        testing.choose_base_filepath();
        testing.save("DRANICKS.txt", harpy::system::blob("Here lies some important рузке алфабет"));
        std::cout << testing.load(MD5("DRANICKS.txt").hexdigest()) << std::endl;
    }
    catch (std::exception& error)
    {
        std::cerr << error.what() << std::endl;
        std::cout << testing.load(MD5("DRANICKS.txt").hexdigest()) << std::endl;
    }
    return 0;
}
