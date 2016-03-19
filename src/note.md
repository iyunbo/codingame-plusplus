##### dangling pointer #####
A dangling pointer is a pointer that points to invalid data or to data which is not valid anymore

``` c++
    
    Class *object = new Class();
    Class *object2 = object;

    delete object;
    object = nullptr;
    // now object2 points to something which is not valid anymore
```

``` c++
    
    Object *method() {
      Object object;
      return &object;
    }
    
    Object *object2 = method();
    // object2 points to an object which has been removed from stack after exiting the function
```

##### `make_shared<Object>()` vs `shared_ptr(new Object())` #####

- exception safety
- one allocation of memory: control block at the space heap space of managed object
- instead of two: control block and managed object

##### stack or heap #####

###### satck ######
- function scope
- local variables
- memory is managed by cpu
- limited size
   
###### heap ######
- global access
- unlimited size
- memory is managed by developer
   
##### when use pointers #####
- use c library
- allocate heap
- Use reference wherever you can, pointers wherever you must.