# BeeLang
Stupid (but fun) little esoteric language, will be updated frequently.

To run BeeLang in python from commandline:
``` Python3 Bee.py ```

To run Beelang in C from commandline:

compile:
```gcc -o Bee Bee.c```

there is also a script for those that prefer. 

```chmod +x compileBee.sh```
```./compileBee.sh```

once compiled: 

```./Bee <name_of_input_file>.txt

BeeLang is interpreted.

BeeLang consists of an array of registers which all start at 0, these registers can be changed and will display a letter based on what value is being store. 0-25 for a-z, -1 for space.

**For help:**

```bee```

**B** refers to current register. 

**b** refers to ptr location. 

**eE increments** 

**Ee decrements** 

**BEE** prints all registers 

**Bee** prints current register
