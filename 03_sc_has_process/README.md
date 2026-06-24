# 03 - SC_HAS_PROCESS
SC_HAS_PROCESS is introduced since systemC v2.0. It takes only one argument which is the name of the module class. It is often compared with SC_CTOR. Let's see how these two macros are defined:
  1. SC_SCOR: #define SC_CTOR(user_module_name) typedef user_module_name SC_CURRENT_USER_MODULE; user_module_name( ::sc_core::sc_module_name )
  2. SC_HAS_PROCESS: #define SC_HAS_PROCESS(user_module_name) typedef user_module_name SC_CURRENT_USER_MODULE

When providing e.g. "module" as input argument to SC_CTOR and SC_HAS_PROCESS, they expand to:
  1. SC_CTOR(module): typedef module SC_CURRENT_USER_MODULE; module( ::sc_core::sc_module_name )
  2. SC_HAS_PROCESS(module): typedef module SC_CURRENT_USER_MODULE;

From this you can see:
1. both defines the "module" as "SC_CURRENT_USER_MODULE", which is used when registering member functions to simulation kernel via SC_METHOD/SC_THREAD/SC_CTHREAD.
2. SC_CTOR also declares a default constructor with module name as the only input argument. The impact is:
  a) SC_CTOR saves one line of code to write a constructor file, whereas if using SC_HAS_PROCESS, one has to declare a constructor function:
      module_class_name(sc_module_name name, additional argument ...);
  b) since SC_CTOR has a constructor functior declarition, it can only be placed inside class header.

My recommendation:
  1. Don't use SC_CTOR or SC_HAS_PROCESS if a module has no simulation process (member functions registered to simulation kernel via SC_METHOD/SC_THREAD/SC_CTHREAD)
  2. Use SC_CTOR if the module need no additional parameter (other than module name) to instantiate
  3. Use SC_HAS_PROCESS when additional parameters are needed during instantiation