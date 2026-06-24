# 20 - Signal: detect event

1. sc_event& default_event(), sc_event& value_changed_event(): return a reference to the value-changed event.
2. bool event(): return true if and only if the value of the signal changed in the update phase of the immediately preceding delta cycle and at the current simulation time.