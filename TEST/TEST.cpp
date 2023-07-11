#pragma comment(lib, "Nerll.lib")
#include <harpy_system/save_sys.h>


int main(int argc, char* argv[])
{
    harpy::system::save_sys testing;
    testing.choose_base_filepath();
    testing.save("DRANICKS.txt", blob(L"Here lies some important data"));
    return 0;
}
