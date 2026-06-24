# 26 - Communication: export

An export:
  1. allows a module to provide an interface to its parent module.
  2. forwards interface method calls to the channel to which the export is bound.
  3. defines a set of services that are provided by the module containing the export.

When to use export:
  1. Providing an interface through an export is an alternative to a module simply implementing the interface.
  2. The use of an explicit export allows a single module instance to provide multiple interfaces in a structured manner.
  3. If a module is to call a member function belonging to a channel instance within a child module, that call should be made through an export of the child module.