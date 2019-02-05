# mbed-workshop
>documents about mbed-workshop at G-camp with Codezoo

Target Board : https://os.mbed.com/platforms/ST-Discovery-L475E-IOT01A/

#When I did this projects I set my env like bottom

<pre><code>mbed config -G GCC_ARM_PATH "~\bin"
mbed config -G TOOLCHAIN "GCC_ARM"
mbed import http://github.com/ARMmbed/mbed-os-example-blinky</code></pre>

and set Target

<pre><code>cd mbed-os-example-blinky
mbed config TARGET "DISCO_L475VG_IOT01A"</code></pre>

If u want to use sensor in the board, add sensor libraries by using `mbed add ~~~ (can got examples from mbed-os homepage)`

And want to know your setting try `mbed config --list`

Good
