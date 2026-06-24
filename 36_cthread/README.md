# 36 - Process: CTHREAD

SC_CTHREAD:
  1. is depcrecated in SystemC 2.0. It is still supported for the case where the second argument is an event finder.
  2. requires a clock when registering a process.
  3. has no separate sensitivity list as SC_METHOD or SC_THREAD.
  4. is activated whenever the specified clock edge occurs.