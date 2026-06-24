// Learn with Examples, 2020, MIT license
#include <systemc>
using namespace sc_core;

SC_MODULE(EVENT) {
  sc_event e; // declare an event
  SC_CTOR(EVENT) {
    SC_THREAD(trigger); //register a trigger process
    SC_THREAD(catcher); // register a catcher process
  }
  void trigger() {
    while (true) { // infinite loop
    //   e.notify(); // trigger after 1 second: Event catched at 5 s
      e.notify(1, SC_SEC);
      if (sc_time_stamp() == sc_time(4, SC_SEC)) {
        e.cancel(); // cancel the event triggered at time = 4 s
      }
      wait(2, SC_SEC); // wait for 2 seconds before triggering again
    }
  }
  void catcher() {
    while (true) { // loop forever
      wait(e); // wait for event
      std::cout << "Event catched at " << sc_time_stamp() << std::endl; // print to console
    }
  }
};

int sc_main(int, char*[]) {
  EVENT event("event"); // define object
  sc_start(10, SC_SEC); // run simulation for 8 seconds
  return 0;
}