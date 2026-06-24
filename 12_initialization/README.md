# 12 - Initialization

Initialization is part of the execution stage, which happens after sc_start(). During initialization it perform the following three steps in the order given:
  1) Run the update phase but without continuing to the delta notification phase.
  2) Add every method and thread process instance in the object hierarchy to the set of runnable processes, excluding:
    a) those process instances for which the function dont_initialize has been called, and
    b) clocked thread processes.
  3) Run the delta notification phase. At the end of the delta notification phase, go to the evaluation phase.

NOTE:
  1. the update and delta notification phases are necessary because update requests can be created during elaboration in order to set initial values for primitive channels, for example, from function initialize of class sc_inout.
  2. In SystemC 1.0,
    a) thread processes are not executed during the initialization phase of the simulation.
    b) method processes are executed during the initialization phase of the simulation if they are made sensitive to input signals/ports.
  3. SystemC 2.0 scheduler will execute all thread processes and all method processes during the initialization phase of the simulation.
    If the behavior of a thread process is different between SystemC 1.0 and SystemC 2.0, insert one wait() statement before the infinite loop of the thread process.
  5. during initialization Phase, processes (SC_METHODs in SystemC 1.0; SC_METHODs and SC_THREADs in SystemC 2.0) are executed in an unspecified order.
  4. dont_initialize(): used to prevent the scheduler from executing a thread or method process during the initialization phase. Applies to the last declared process.