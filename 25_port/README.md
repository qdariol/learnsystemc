# 25 - Communication: port
Three key concepts for communication:
  1. Interface:
    a) an abstract class derived from sc_interface but not derived from sc_object.
    b) contains a set of pure virtual functions that shall be defined in one or more channels derived from that interface.
  2. Port:
    a) provides the means by which a module can be written such that it is independent of the context in which it is instantiated.
    b) forwards interface method calls to the channel to which the port is bound.
    c) defines a set of services (as identified by the type of the port) that are required by the module containing the port.
  3. Channel:
    a) sc_prim_channel is the base class for all primitive channels.
    b) channel may provide public member functions that can be called using the interface method call paradigm.
    c) a primitive channel shall implement one or more interfaces.

In short:
  port requires services, interface defines services, channel implements services.
  a port can connect (bind) to a channel if the channel implements the interface that the port requires.
  a port is basically a pointer to a channel.

when to use port:
  1. If a module is to call a member function belonging to a channel that is outside the module itself, that call should be made using an interface method call through a port of the module. Otherwise is considered bad coding style.
  2. However, a call to a member function belonging to a channel instantiated within the current module may be made directly. This is known as portless channel access.
  3. If a module is to call a member function belonging to a channel instance within a child module, that call should be made through an export of the child module.