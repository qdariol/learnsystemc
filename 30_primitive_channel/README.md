# 30 - Primitive Channel

sc_prim_channel:
  1. is the base class for all primitive channels
  2. provides primitive channels with unique access to the update phase of the scheduler.
  3. contains no hierachy, ports, or simulation processes.
  4. in common with hierarchical channels, a primitive channel may provide public member functions that can be called using the interface method call paradigm.
  provides the following member functions:
    a) request_update(): scheduler to queue an update request for the channel
    b) async_request_update():
      1) scheduler to queue an update request for the channel in a thread-safe manner. May be called reliably from an operating system thread other than systemC kernel.
      2) not recommended to be called from functions executed in the context of the systemC kernel
    c) update():
      1) called back by the scheduler during the udpate phase in response to a call to request_update or async_request_update.
      2) an application may override this member function. The definition of this function in sc_prim_channel itself does nothing.
      3) typically only read and modify data members of the current object and create delta notifications.
      4) shall not:
        a) call any member function of class sc_prim_channel with the exception of member function update itself if overridden within a base class of the current object
        b) call member function notify() of class sc_event with no arguments to create an immediate notification
        c) call any of the member functions of class sc_process_handle for process control (suspend or kill, for example)
        d) change the state of any storage except for data members of the current object.
        e) read the state of any primitive channel instance other than the current object.
        f) call interface methods of other channel instances. In particular, member function update should not write to any signals.
    d) next_trigger()
    e) wait()

A channel shall implement one or more interface, thus needs to inherit from an interface class (of base class type sc_interface). The interface provides the required methods for the channel.