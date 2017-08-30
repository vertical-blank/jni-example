
```
make -f Makefile.native
```

```
gradle compilejava
```


```
java -Djava.library.path=target/lib -cp build/classes/main/ vblank.HelloJni
```

```
chmod 755 target/obj/fromc.o;target/obj/fromc.o
```


## from c


```
make -f Makefile.fromc
export DYLD_LIBRARY_PATH=/Library/Java/JavaVirtualMachines/jdk1.8.0_121.jdk/Contents/Home/jre/lib/server
target/obj/fromc.o
```
