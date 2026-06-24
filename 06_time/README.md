# 06 - Time notation
Let's first understand the difference of the two time measurements:
  1. wall-clock time
    the time from the start of execution to completion, including time waiting on other system activities and applications
  2. simulated time
    the time being modeled by the simulation, which may be less than or greater than the simulation's wall-clock time.

In systemC, sc_time is the data type used by simulation kernal to track simulated time. It defines several time units:
SC_SEC, SC_MS, SC_US, SC_NS, SC_PS, SC_FS. Each subsequent time unit is 1/1000 of its preceder.

sc_time objects may be used as operands for assignment, arithmetic, and comparison operations:
  multiplication allows one of its operands to be a double
  division allows the divisor to be a double

SC_ZERO_TIME:
a macro representing a time value of zero. It is good practice to use this constant whenever writing a time value of zero, for example, when creating a delta notification or a delta time-out.

To get current simulated time, use sc_time_stamp().