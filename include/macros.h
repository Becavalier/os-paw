#ifndef	_MACRO_H
#define	_MACRO_H

#if !defined(_SC_ARG_MAX) 
  #define _SC_ARG_MAX -1
#elif !defined(_SC_CHILD_MAX)
  #define _SC_CHILD_MAX -1
#elif !defined(_SC_CLK_TCK)
  #define _SC_CLK_TCK -1
#elif !defined(_SC_HOST_NAME_MAX)
  #define _SC_HOST_NAME_MAX -1
#elif !defined(_SC_NGROUPS_MAX)
  #define _SC_NGROUPS_MAX -1
#elif !defined(_SC_LOGIN_NAME_MAX)
  #define _SC_LOGIN_NAME_MAX -1
#elif !defined(_SC_OPEN_MAX)
  #define _SC_OPEN_MAX -1
#elif !defined(_SC_PAGESIZE)
  #define _SC_PAGESIZE -1
#elif !defined(_SC_STREAM_MAX)
  #define _SC_STREAM_MAX -1
#elif !defined(_SC_SYMLOOP_MAX)
  #define _SC_SYMLOOP_MAX -1
#elif !defined(_SC_TTY_NAME_MAX)
  #define _SC_TTY_NAME_MAX -1
#endif

#define ITERATE_SYSCONF(V, ...) \
  V(_SC_ARG_MAX, "ARG_MAX", "The maximum length of the arguments to the exec(3) family of functions.", __VA_ARGS__); \
  V(_SC_CHILD_MAX, "CHILD_MAX", "The maximum number of simultaneous processes per user ID.", __VA_ARGS__); \
  V(_SC_CLK_TCK, "CLK_TCK", "The number of clock ticks per second.", __VA_ARGS__); \
  V(_SC_HOST_NAME_MAX, "HOST_NAME_MAX", "Maximum length of a hostname, not including the terminating null byte.", __VA_ARGS__); \
  V(_SC_LOGIN_NAME_MAX, "LOGIN_NAME_MAX", "Maximum length of a login name, including the terminating null byte.", __VA_ARGS__); \
  V(_SC_NGROUPS_MAX, "NGROUPS_MAX", "Maximum number of supplementary group IDs.", __VA_ARGS__); \
  V(_SC_OPEN_MAX, "OPEN_MAX", "The maximum number of files that a process can have open at any time.", __VA_ARGS__); \
  V(_SC_PAGESIZE, "PAGESIZE", "Size of a page in bytes.  Must not be less than 1.", __VA_ARGS__); \
  V(_SC_STREAM_MAX, "STREAM_MAX", "The maximum number of streams that a process can have open at any time.", __VA_ARGS__); \
  V(_SC_SYMLOOP_MAX, "SYMLOOP_MAX", "The maximum number of symbolic links seen in a pathname before resolution returns ELOOP.", __VA_ARGS__); \
  V(_SC_TTY_NAME_MAX, "TTY_NAME_MAX", "The maximum length of terminal device name, including the terminating null byte.", __VA_ARGS__)


#endif	/* _MACRO_H */