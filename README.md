Part of a tutorial of writing / loading kernel modules.

My system is a stock Ubuntu 18.04 distribution.

Examples came from:
http://tldp.org/LDP/lkmpg/2.6/html/lkmpg.html#AEN40



To start the module:

```
    sudo insmod ./hello-3.ko
```

To stop the module:

```
    sudo rmmod hello-3
```

logs located:
```
    /var/log/syslog 
```
or 
```
    dmesg
```

With params
```
    sudo insmod hello-3.ko mystring='test-string' mybyte=154 myintArray=-1
```