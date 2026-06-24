# 14 - Event queue

An event queue:
  1. has a member function notify(), same as an event
  2. is a hierarchical channel and can have multiple notifications pending, this differs from an event which can have only one outstanding notificaiton scheduled.
  3. can only be constructed during elaboration.
  4. does not support immediate notification

Member functions:
  1. void notify(double, sc_time_unit) or void notify(const sc_time&):
    a) zero time i.e. SC_ZERO_TIME: a delta notification
    b) non-zero time: notification scheduled relative to the simulation time when function notify is called.
  2. void cancel_all(): immediately delete every pending notification for this event queue object including both delta and timed notifications.