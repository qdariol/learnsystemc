# 26 - Communication: port 2 port

So far we covered the cases of:
  1. connecting two processes of same module via channel:
      process1() --> channel --> process2()
  2. connecting two processes of different modules via port and channel:
      module1::process1() --> module1::port1 --> channel --> module2::port2 --> module2::process2()
  3. connecting two processes of different modules via export:
      module1::process1() --> module1::channel --> module1::export1 --> module2::port2 --> module2::process2()

In all these cases, a channel is needed to connect the ports. There is a special case that allows a port to directly connect to a port of submodules. I.e.,
  module::port1 --> module::submodule::port2