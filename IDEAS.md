# Ideas
Some thoughts on how this all fits together.

## Contents
* Creating objects
* Object hierarchy
* Managers
* Systems
* Events

## Creating objects
Should I derive all objects from a `AbstractManagedObject` base class? A memory manager could create all objects, handle all allocations? Eg:
```c++
ObjectManager->create< Graph >();
ObjectManager->create< Node >();
ObjectManager->create< Connection >();
```
All object types and ids will be unique...
```
m_objects {
      Connections: [0, 1, ..., n],
      Graph:       [0, 1, ..., n],
      Group:       [0, 1, ..., n],
      Node:        [0, 1, ..., n],
      Plug:        [0, 1, ..., n],
}
```

## Object Hierarchy
Inheritance layout.
```c++
AbstractManagedObject
  Container           // Container base
    Graph             // Execution entry point
    Group             // Group nodes
    Node              // Process container
  Plug                // Data entry/exit points
  Connection          // Dependency pipeline
  
AbstractManager
  MemoryManager       // Managed object allocator
  ContainerManager    // Container access
  ConnectionManager   // Container access
  PluginManager       // Container access

AbstractSystem         
  ConnectionSystem    // Container  --> Container 
  PlugSystem          // Connection --> Plug 
```

## Managers
TODO

## Systems
TODO

## Events
Some example signals
```
Container::created(type, id)
Container::destroyed(type, id)

Connection::connected(type, id)
Connection::disconnected(type, id)

Plug::added(type, id)
Plug::removed(type, id)
```


