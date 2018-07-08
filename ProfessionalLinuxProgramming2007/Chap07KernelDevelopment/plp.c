/* * plp.c - An example kernel module
 * * Copyright (C) 2006 Jon Masters <jcm@jonmasters.org>
 * * This program is free software; you can redistribute it and/or
 * * modify it under the terms of the GNU General Public License as
 * * published by the Free Software Foundation.  * */
/* Full path of headers for the initial installed kernel on my VM which has ScientificLinux 7.4 : 
 * /usr/src/kernels/3.10.0-862.el7.x86_64/include/linux/module.h 
 * /usr/src/kernels/3.10.0-862.el7.x86_64/include/linux/init.h 
 */
#include <linux/module.h>
#include <linux/init.h>
int __init greetings(void)
{
  printk("plp: hello reader!The module runs.\n");
  return 0;
}
void __exit goodbye(void)
{
  printk("plp: I just exited. Goodbye!\n");
}
/* Module Metadata */
MODULE_AUTHOR("George Doumas <gedoomgr@yahoo.gr>");
MODULE_DESCRIPTION("PLP example based on page 209 of book Professional Linux Programming 2007 edition");
MODULE_LICENSE("GPL");
module_init(greetings);
module_exit(goodbye);
