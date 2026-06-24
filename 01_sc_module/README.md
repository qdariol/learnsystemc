# 01 - SystemC module
A systemC module is:
  1. the smallest container of functionality with state, behavior, and strucure for hierarchical connectivity.
  2. a C++ class, which inherits a systemC basic class: sc_module.
  3. the principle structural building block of SystemC.
  4. used to repsent a component in real systems.

How to define a systemC module:
  1. SC_MODULE(module_name) {}: this uses the systemC defined macro "SC_MODULE", which is equivement to #2.
  2. struct module_name: public sc_module {}: a struct that inherits sc_module.
  3. class module_name : public sc_module { public: }: a class that inherits sc_module.
Note, class is identical to struct except for its default access control mode of "private", as compared to "public" of struct.

How to use a systemC module:
  1. Objects of class sc_module can only be constructed during elaboration. It shall be an error to instantiate a module during simulation.
  2. Every class derived (directly or indirectly) from sc_module shall have at least one constructor. Every constructor shall have one and only one parameter of class sc_module_name but may have further parameters of classes other than sc_module_name.
  3. A string-valued argument shall be passed to the constructor of every module instance. It is good practice to make this string name the same as the C++ variable name through which the module is referenced, if such a variable exists.
  4. (To be explained later) Inter-module communication should typically be accomplished using interface method calls; that is, a module should communicate with its environment through its ports. Other communication mechanisms are permissible, for example, for debugging or diagnostic purposes.