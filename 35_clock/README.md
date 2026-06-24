# 35 - Clock

sc_clock s a predefined primitive channel derived from the class sc_signal and intended to model the behavior of a digital clock signal.
The value and events associated with the clock are accessed through the interface sc_signal_in_if<bool>.

Constructor:
sc_clock(
  constchar*name_, // unique module name
  double period_v_, // the time interval between two consecutive transitions from false to true, also equal to the time interval between two consecutive transitions from true to false. Greater than zero, default is 1 nanosecond.
  sc_time_unit period_tu_, // time unit, used for period
  double duty_cycle_, // the proportion of the period during which the clock has the value true. Between 0.0 and 1.0, exclusive. Default is 0.5.
  double start_time_v_, // the absolute time of the first transition of the value of the clock (false to true or true to false). Default is zero.
  sc_time_unit start_time_tu_,
  bool posedge_first_ = true ); // if true, the clock is initialized to false, and changes to true at the start time. Vice versa. Default is true.