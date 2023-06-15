A Linux Kernel Module  consists of 3 sections: header , Code , registration and description.
Every kernel module should include this header file. Because it has got a definition of various macros, which we are going to use while writing a kernel module. 


#kernel headers path:  linux source tree at the path /include/linux.

while writing a kernel module, we use 2 entry points. 
Here, the first function is called the module initialization entry point, or in short, call it a module initialization function. 
And the second function is called the module clean-up entry point, or in short, I call it the module clean-up function. 

You don’t see the main function here. 

int fun_name(void); is the prototype of a module initialization function. i
It should return int and function name. You can give anything you want your custom name, and it will not be taking any parameters. 

Input parameters are void. 

The module initialization function must return a value; 0 for success, non zero means module initialization failed. 

So, the module will not get loaded into the kernel. 

This is an entry point to your module (like main). We talk in terms of entry points. 

This function will get called during boot time in the case of static modules. 

In the case of dynamic modules, this function will get called during module insertion. There should be one module initialization entry point in the module.

For example, if you compile this kernel module as a dynamic module, this function will get called when you insert the module into the kernel, using user-level programs such as insmod. 

 

Let’s explore more about the module initialization function.

You do some initialization of devices, 
Initialization of device private data structures, 
you request some memory dynamically for various kernel data structures and services, you request for allocation of major and minor numbers, device file creation, various things you do in this function.


Basically, you do initialization-related things in this function. Because, it’s an entry point. It’s like a main.

 

You have got a static keyword there and you have got to __init tag there.

What are those?


We have to understand that. The module initialization function is module-specific and should never be called from other modules of the kernel. Because, it’s a initialization function of a module.

Why would other modules will call it?

It is module-specific. It should not provide any services or functionalities which may be requested by other modules. You should not give any services here which may be required from other modules.

Hence it makes sense to make this function private using ‘static’ though it is optional. Here, the static keyword is actually optional, but as I said, this is module-specific, and it is private to the module. 

Then it’s good if you make this function a static function like private to a file or private to a kernel module. That’s a reason why we use static here, but it is optional. 





