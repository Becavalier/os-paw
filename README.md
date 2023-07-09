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
# Show all the runtime system configurations of the current OS.
sysconf   
# Original system commands are also supported. 
ls -al
```
