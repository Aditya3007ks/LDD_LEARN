#include<linux/module.h>
#include<linux/init.h>

//Module Description

static int __init entry_hello_world(void);
static void __exit exit_hello_world(void);

static int __init entry_hello_world(void){
pr_info("inserted hello world module\n");
return 0;
}


static void __exit exit_hello_world(void){
pr_info("removed hello world module\n");
}

//Module Init
module_init(entry_hello_world);
module_exit(exit_hello_world);

//Module Description
MODULE_AUTHOR("aditya");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A Simple hello world module");
//MODULE_INFO("BASIC PRACTICE");



