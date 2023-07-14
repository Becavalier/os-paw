#ifndef	_MACRO_H
#define	_MACRO_H

#define ITERATE_SYSCONF(V, ...) \
  V(_SC_VERSION, "VERSION", "The year and month the POSIX.1 standard was approved.", __VA_ARGS__); \
  V(_SC_XOPEN_VERSION, "XOPEN_VERSION", "The version of the X/Open Portability Guide to which the implementation conforms.", __VA_ARGS__); \
  V(_SC_ARG_MAX, "ARG_MAX", "Maximum length of the arguments to the exec(3) family of functions.", __VA_ARGS__); \
  V(_SC_CHILD_MAX, "CHILD_MAX", "Maximum number of simultaneous processes per user ID.", __VA_ARGS__); \
  V(_SC_CLK_TCK, "CLK_TCK", "Number of clock ticks per second.", __VA_ARGS__); \
  V(_SC_HOST_NAME_MAX, "HOST_NAME_MAX", "Maximum length of a hostname, not including the terminating null byte.", __VA_ARGS__); \
  V(_SC_LOGIN_NAME_MAX, "LOGIN_NAME_MAX", "Maximum length of a login name, including the terminating null byte.", __VA_ARGS__); \
  V(_SC_NGROUPS_MAX, "NGROUPS_MAX", "Maximum number of supplementary group IDs.", __VA_ARGS__); \
  V(_SC_OPEN_MAX, "OPEN_MAX", "Maximum number of files that a process can have open at any time.", __VA_ARGS__); \
  V(_SC_PAGESIZE, "PAGESIZE", "Size of a page in bytes.  Must not be less than 1.", __VA_ARGS__); \
  V(_SC_STREAM_MAX, "STREAM_MAX", "Maximum number of streams that a process can have open at any time.", __VA_ARGS__); \
  V(_SC_SYMLOOP_MAX, "SYMLOOP_MAX", "Maximum number of symbolic links seen in a pathname before resolution returns ELOOP.", __VA_ARGS__); \
  V(_SC_TTY_NAME_MAX, "TTY_NAME_MAX", "Maximum length of terminal device name, including the terminating null byte.", __VA_ARGS__); \
  V(_SC_ASYNCHRONOUS_IO, "POSIX_ASYNCHRONOUS_IO", "Support POSIX async IO?", __VA_ARGS__); \
  V(_SC_BARRIERS, "POSIX_BARRIERS", "Support Barriers?", __VA_ARGS__); \
  V(_SC_CLOCK_SELECTION, "POSIX_CLOCK_SELECTION", "Support Clock Selection?", __VA_ARGS__); \
  V(_SC_MAPPED_FILES, "POSIX_MAPPED_FILES", "Support Mapped Files?", __VA_ARGS__); \
  V(_SC_MEMORY_PROTECTION, "POSIX_MEMORY_PROTECTION", "Support Memory Protection?", __VA_ARGS__); \
  V(_SC_READER_WRITER_LOCKS, "POSIX_READER_WRITER_LOCKS", "Support Reader-Writer Locks?", __VA_ARGS__); \
  V(_SC_REALTIME_SIGNALS, "POSIX_REALTIME_SIGNALS", "Support Realtime Signals?", __VA_ARGS__); \
  V(_SC_SEMAPHORES, "POSIX_SEMAPHORES", "Support POSIX Semaphores?", __VA_ARGS__); \
  V(_SC_SHELL, "POSIX_SHELL", "Support POSIX Shell?", __VA_ARGS__); \
  V(_SC_SPIN_LOCKS, "POSIX_SPIN_LOCKS", "Support Spin Locks?", __VA_ARGS__); \
  V(_SC_THREAD_SAFE_FUNCTIONS, "POSIX_THREAD_SAFE", "Support Thread-safe Functions?", __VA_ARGS__); \
  V(_SC_THREADS, "POSIX_THREADS", "Support Threads?", __VA_ARGS__); \
  V(_SC_TIMEOUTS, "POSIX_TIMEOUTS", "Support Timeouts?", __VA_ARGS__); \
  V(_SC_TIMERS, "POSIX_TIMERS", "Support Timers?", __VA_ARGS__); \
  V(_SC_XOPEN_VERSION, "XOPEN_VERSION", "XSI Version that supported.", __VA_ARGS__)



#endif	/* _MACRO_H */