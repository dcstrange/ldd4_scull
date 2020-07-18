# ldd3 examples code for Linux v4.19.125
本库Fork自 [omerjerk/ldd4_scull](https://github.com/omerjerk/ldd4_scull)。 

> Scull Linux device driver
> Scull source as mentioned in the book Linux Device Drivers 3rd Edition with all the appropriate changes to make it compatible with Linux Kernel 4.2 .

本仓库的代码源自于《Linux Device Driver (3rd Edition)》（简称ldd3）的示例代码，但随着Linux内核版本的更新，内核的API和数据结构也改变了，原本为内核版本为v2.6.27编写的示例代码，在新版本的内核中编译失败。
本仓库的代码主要用来在我的Linux内核版本为v4.19.125的机器上测试，解决旧版本源码与我的内核版本不兼容的问题。（其实[omerjerk/ldd4_scull](https://github.com/omerjerk/ldd4_scull)也是为了使Linux v2.6.27的源代码运行在Linux v4.2上，但我仍然发现v4.2的代码在我的机器上不兼容。)

说明：目前仅仅在我机器上使用的内核版本上测试通过，更新或者更早的版本也可能可以用，因为不知道内核API是在那个版本下变化的。

---

July 18, 2020

`linux/sched.h`定义了结构体`struct task_struct`，该结构体就是被我们熟悉的`current`宏所使用。除此之外，`sched.h`还提供了主要的内核调度器API（schedule(), wakeup variants, etc.）。

v4.19.125将`sched.h`内所使用的一些结构体的定义放在了`linux/sched/`目录的头文件内，比如结构体`signal_struct`可以在头文件`linux/sched/signal.h`中找到。

