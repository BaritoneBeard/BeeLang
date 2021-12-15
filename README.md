 <h3 align="center">Bee Language</h3>
 <h4 align = "center">a stupid (but fun) little esoteric language</h4>

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a>Running the Language</a>
    </li>
    <li>
      <a>Help/Info</a>
    </li>
  </ol>
</details>


<!-- Running the Language-->
# Running the Language
To run BeeLang in python from commandline:
``` Python3 Bee.py ```

To run Beelang in C from commandline:

compile:
```gcc -o Bee Bee.c```

there is also a script for those that prefer. 

```chmod +x compileBee.sh```
```./compileBee.sh```

once compiled: 

```./Bee <name_of_input_file>.txt```

BeeLang is interpreted.

BeeLang consists of an array of registers which all start at 0, these registers can be changed and will display a letter based on what value is being store. 0-25 for a-z, -1 for space.

<!-- Help/Info-->
# Help/Info

the keyword

```bee```

will bring up the following information

**B** refers to current register. 

**b** refers to ptr location. 

**eE increments** 

**Ee decrements** 

**BEE** prints all registers 

**Bee** prints current register
