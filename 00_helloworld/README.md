# 00 - Hello World
There are two approaches to print a string to console:
  1. c++ style: print from a normal c++ function
  2. systemc style: print from a systemC method invoked by systemC simulation kernel

Before we start, you need to know some basics.

SystemC header file:
To use the SystemC class library features, an application shall include either of the C++ header files specified below:
  1. `#include <systemc.h>`
      - `systemc.h` add all of the names from the namespaces sc_core and sc_dt to the declarative region in which it is included, together with the name sc_unnamed and selected names from the standard C or C++ libraries (e.g. cin, cout, iostream).
      - `systemc.h` is provided for backward compatibility with earlier versions of SystemC and may be deprecated in future versions of this standard.
  2. `#include <systemc>`
    systemc is the old systemc.h without usings
A common practice is to include `<systemc>`, followed by `using namespace sc_core`. The programmer can then include other namespaces on a need basis.

SystemC entry point:
  while a normal c++ program's entry point is the main() function, systemC user has to use int_sc_main(int argc, char* argv[]) as the entry point.
  This is because systemC library has the main() function already defined. main() will call sc_main() and passes the command-line parameters.

SystemC module:
  a systemC module is a class (or struct) that inherits the sc_module base class. This will be discussed in upcoming examples.