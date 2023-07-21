#pragma once
#ifndef HARPY_CSHARP_CROSSOVER_SAVE_SYS
#define HARPY_CSHARP_CROSSOVER_SAVE_SYS

#pragma managed

namespace harpy
{
    namespace system
    {
        class cxx_save_sys;
    }
}

namespace harpy_csharp::utilities
{
    public ref class save_sys
    {
        harpy::system::cxx_save_sys* system;
        
    public:

        save_sys();

        void save(System::String^ name, System::String^ blob);

        System::String^ load (System::String^ hash);

        void choose_base_filepath();
        void choose_base_filepath(System::String^ directory);

        //Finalizer
        !save_sys();

        ~save_sys()
        {
            //release managed resources

            //call finalizer
            this->!save_sys();
        }
    };
}




#endif // HARPY_CSHARP_CROSSOVER_SAVE_SYS