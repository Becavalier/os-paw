# os-paw
A tool for diagnosing and playing with OS.


### How to use?

```
cmake . -Bbuild
cd ./build
make
```

### Commands

Get into the dedicated shell for running os-paw.

```bash
./os-paw  
``` 

Then, send commands directly.

```bash
sysconf    # Show all the runtime system configurations of the current OS.
cpuinfo    # Show detailed CPU info. 
# Original system commands are also supported. 
ls -al
```

BTW, you can also run the command direclty like below:

```bash
./os-paw sysconf
``` 
