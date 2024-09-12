#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/unistd.h>	/* The list of system calls */
/** 
Take a look at 
/usr/src/linux-source-2.6.32/arch/x86/include/asm/unistd.h 
/usr/src/linux-source-2.6.32/arch/x86/include/asm/unistd_32.h 
**/
MODULE_DESCRIPTION("My kernel module");
MODULE_AUTHOR("John Doe");
MODULE_LICENSE("GPL");

/*
 * The system call table (a table of functions). We
 * just define this as external, and the kernel will
 * fill it up for us when we are insmod'ed
 */

extern void *sys_call_table[]; 

static int findsyscall_init(void) {
	/**
	 * CHANGE THIS SO THAT IT PRINTS OUT THE LOCATION
	 * OF the exit, fork and read system calls
	 */
	
	printk( KERN_DEBUG "Module findsyscall loaded\n" );
	printk( KERN_DEBUG "exit lives at %p\n",1 ); // FIX THIS
	printk( KERN_DEBUG "fork lives at %p\n",1 ); // FIX THIS
	printk( KERN_DEBUG "read lives at %p\n",1 ); // FIX THIS
	return 0;
}
static void findsyscall_exit(void) {
	printk( KERN_DEBUG "Module findsyscall unloaded\n" );
}
module_init(findsyscall_init);
module_exit(findsyscall_exit);
