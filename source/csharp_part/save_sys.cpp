//For c++ impl
#include <harpy_system/cxx_save_sys.h>


//For c++/cli
#include "save_sys.h"




std::string marshal_string ( System::String^ s)
{  
    const char* kPtoC =  static_cast<const char*>((System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(s)).ToPointer());                                                        
    System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)kPtoC));
    return kPtoC;
}


harpy_csharp::utilities::save_sys::save_sys()
{
    system = new harpy::system::cxx_save_sys();
}

void harpy_csharp::utilities::save_sys::save(System::String^ name, System::String^ blob)
{
    
    system->save(marshal_string(name), marshal_string(blob));
}

System::String^ harpy_csharp::utilities::save_sys::load(System::String^ hash)
{
    return gcnew System::String(system->load(marshal_string(hash)).c_str());
}

void harpy_csharp::utilities::save_sys::choose_base_filepath()
{
    system->choose_base_filepath();
}

void harpy_csharp::utilities::save_sys::choose_base_filepath(System::String^ directory)
{
    system->choose_base_filepath(marshal_string(directory));
}

void harpy_csharp::utilities::save_sys::!save_sys()
{
    delete system;
}


