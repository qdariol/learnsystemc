# 02 - Constructor: SC_CTOR
Every c++ function must have a constructor. For a normal c++ function, a default constructor will be auto-generated if not explicitly provided.
However, every systemC module must have a unique "name", which is provided when instantiating a module object. This requires a constructor with at least one parameter.

SystemC provides a macro (SC_CTOR) for convenience when declaring or defining a constructor of a module. SC_CTOR:
  1. shall only be used where the rules of C++ permit a constructor to be declared and can be used as the declarator of a constructor declaration or a constructor definition.
  2. has only one argument, which is the name of the module class being constructed.
  3. cannot add user-defined arguments to the constructor. If an application needs to pass additional arguments, the constructor shall be provided explicitly.