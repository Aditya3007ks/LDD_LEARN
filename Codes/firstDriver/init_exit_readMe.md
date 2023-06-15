Basically, these are nothing but C macros, which are defined in LINUX_SRC/include/linux/init.h. You can open the init.h file, and you will find these macros.

You can see above there are just C macros and which expand to a something called compiler directive. These are compiler directives, or you can also call it as compiler attributes (shown in Figure 1).

For example, if you take the first case __init, which expands into __section(.init.text). Here, this is called as a compiler directive, which directs the compiler to keep data or code in an output section called “init.” 

When you use this __init macro with any function, then that function code will be placed in a section called “.init” in the final kernel image.

 

Similarly, __exit is also another C macro, which expands to __section(.exit.text) compiler directive, which directs the compiler to keep data or code in an output section called “exit.” __init, and __exit makes sense only for static modules.

__init is a macro that will be translated into a compiler directive, which instructs the compiler to put the code in .init section of the final ELF of the linux kernel image. 

.init section will be freed from the memory by the kernel during boot time once all the initialization functions gets  executed.

Since the built-in driver cannot be unloaded, it’s init function will not be called again until the next reboot, that’s why there is no need to keep references to its init function anymore.

 

Figure 2. Init and Exit functions
Figure 2. Init and Exit functions
 

For example, this is the init function(in Figure 2).

If this module is a built-in module, then this function will be called only one time, that is, during the boot time. And once this function finishes, then why would you need this function. Because it’s a static function, no one is going to call it. Don’t you think it’s better to remove the memory occupied by this function code, the kernel can remove it from the memory, which will save some memory, because there are 100 thousand built-in modules.

Removing some memory for 100 modules would be huge. The kernel is going to save a lot of runtime memory. That’s why __init is a technique by using that we push that function into a init section, a separate section, which a kernel can free later.

Using __init macro is a technique, when used with a  function, the kernel will free the code memory of that function after its execution. And also, remember that it is an optional one. If you omit that, then no problem. You don’t see any compilation, warnings, or errors. You can omit that.


Similarly, you can use __initdata with variables that will be dropped after the initialization.__init is for code or for function,  __initdata is for variables, init variables.

 

What is the use of __exit?

You know that for built-in modules clean-up function is not required. When you use exit macro with a clean-up function, the kernel build system will exclude those functions during the build process itself.

__exit acts as a marker for the build system to drop the clean-up function in the build process itself. It will not be part of the final kernel image.

 

Let’s say you have three static modules. module1.c, module2.c, and module3.c, as shown in Figure 3.

Figure 3. Init function’s modules explanation
Figure 3. Init function’s modules explanation
 

Let’s say module1.c’s init function is m1 init function, module2.c’s init function is m2 init function, and module3.c’s init function is m3 init function. Out of these 3 init functions, m1 init function and m2 init functions are tagged with init macros.

When you trigger the kernel build, all these 3 modules will be part of the final Linux kernel image.

In the final Linux kernel image, a new section will be created,  that’s called “.init” And m1_init_function and m2_init_function will be part of that .init section. That means, the codes of m1_init_function and m2_init_function will be placed in the section called .init by the compiler.

When the kernel boots, the kernel calls  m1_init_function and m2_init_function. And after that, the kernel frees the memory which has been consumed by the .init section. Because, these functions will not get executed again during runtime of the kernel. 

That’s a reason what’s the use  of keeping that .init section. It will get freed. But, in this case m3_init_function will not be a part of .init. Because, it is not tagged with the macro __init. It will be a part of  .text region. That’s why, m3_init_function will permanently consume the memory during the run time of the kernel.

And also, remember that all __exit marked functions will be dropped by the kernel build system hence they will not be part of the final image. I hope now you get the idea why init and exit macros are used, and let me know if you have any questions.

In the following article, I am going to cover Linux Kernel module entry points
