/*
 * setlevel.c -- choose a console_loglevel for the kernel
 *
 * Copyright (C) 1998,2000,2001 Alessandro Rubini
 * 
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
/* #include <unistd.h> */ /* conflicting on the alpha */
#define __LIBRARY__ /* _syscall3 and friends are only available through this */
#include <linux/unistd.h>


/* define the system call, to override the library function */
/* [fei]- 这里显示声明syslog(2)系统调用，是因为glibc中有同样符号名称的函数（但不用的用途），避免混淆。
 * syslog(2)系统调用的glibc接口是klogctl(3)，声明于 <sys/klog.h>。*/
_syscall3(int, syslog, int, type, char *, bufp, int, len); 

int main(int argc, char **argv)
{
    int level;

    if (argc==2) {
	level = atoi(argv[1]); /* the chosen console */
    } else {
        fprintf(stderr, "%s: need a single arg\n",argv[0]); exit(1);
    }
    if (syslog(8,NULL,level) < 0) {  // [fei]- 查看syslog(2)的man page关于第一个参数的说明。https://man7.org/linux/man-pages/man2/syslog.2.html
        fprintf(stderr,"%s: syslog(setlevel): %s\n",
                argv[0],strerror(errno));
        exit(1);
    }
    exit(0);
}
