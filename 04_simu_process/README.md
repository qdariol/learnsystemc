# 04 - Simulation Process

A simulation process:
  1. is a member function of a sc_module class, and
  3. has no input argument and returns no value, and
  2. is registered with the simulation kernel

How to register a simulation process:
  1. SC_METHOD(func): does not have its own thread of execution, consumes no simulated time, cannot be suspended, and cannot call code that calls wait()
  2. SC_THREAD(func): has its own thread of execution, may consume simulated time, can be susupended, and can call code that calls wait()
  3. SC_CTHREAD(func, event): a special form of SC_THREAD thatcan only have a static sensitivity of a clock edge event

When can registration happen:
  1. in the body of the constructor,
  2. in the before_end_of_elaboration or end_of_elaboration callbacks of a module,
  3. or in a member function called from the constructor or callback

Restrictions:
  1. registration can only be performed on member functions of the same module.
  2. SC_CTHREAD shall not be invoked from the end_of_elaboration callback.

Note:
  1. SC_THREAD can do everything that SC_METHOD or SC_CHTEAD does. I'll mostly use this process in the examples.
  2. In order for an SC_THREAD or SC_CTHREAD process to be called again, there shall be a while loop making sure it never exits.
  3. An SC_THREAD process doesn't require a while loop. It is invoked again by next_trigger()
  4. simulated time in systemC is not the actual time a program runs. It's a counter managed by the simulation kernel. To be explained later.