# 32 - Trace file

A trace file:
  1. records a time-ordered sequence of value changes during simulation.
  2. uses VCD (Value change dump) file format.
  3. can only be created and opened by sc_create_vcd_trace_file.
  4. may be opened during elaboration or at any time during simulation.
  5. contains values that can only be traced by sc_trace.
  6. shall be opened before values can be traced to that file, and values shall not be traced to a given trace file if one or more delta cycles have elapsed since opening the file.
  7. shall be closed by sc_close_vcd_trace_file. A trace file shall not be closed before the final delta cycle of simulation.