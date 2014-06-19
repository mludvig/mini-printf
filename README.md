mini-printf
===========

Minimal printf() implementation for embedded projects.

Motivation
----------

I was recently working on an embedded project with a STM32 MCU.
The chip had 32kB of flash memory - that's heaps for a microcontroller!
How surprised I was when the linker suddelnly failed saying that
the program is too big and won't fit! How come?!

It's just some USB, I2C, GPIO, a few timers ... and snprintf()
It turned out the memory hog was indeed the glibc's snprintf() - it
took nearly 24kB out of my 32kB and left very little for my program.

Now what? I looked around the internet for some stripped down
printf() implementations but none I really liked. Then I decided
to develop my own minimal snprintf().

Here are some numbers (.bin file size of my STM32 project):

    no snprintf():      10768 bytes
    mini snprintf():    11420 bytes     (+  652 bytes)
    glibc snprintf():   34860 bytes     (+24092 bytes!!)

Why *SN*printf()?
-----------------

Why snprintf() and not printf()? Simply because there are so many
different ways to print from an embedded system that I can't really
make an universal-enough printf().

The way I chose makes printing really easy - use mini\_snprintf()
to print into a "char buffer[]" and then output that buffer to your
chip's USART, USB or network or whatever other channel you fancy.

As a by-product there's also a mini\_vsnprintf() function available.

Compatibility
-------------

I didn't implement each and every formatting sequence the glibc does.
For now only these are supported:

    %%       - print '%'
    %c       - character
    %s       - string
    %d, %u   - decimal integer
    %x, %X   - hex integer

The integer formatting also supports 0-padding up to 9 characters wide.
(no space-padding or left-aligned padding yet).

The implementation should be compatible with any GCC-based compiler.
Tested with native x86-64 gcc, arm-none-eabi-gcc and avr-gcc.

It's completely standalone without any external dependencies.

Usage
-----

1. Include "mini-printf.h" into your source files.
2. Add mini-printf.o to your objects list.
3. Use snprintf() as usual in your project.
4. Compile, Flash, Test

Etc.
----

Written by:
	Michal Ludvig <michal@logix.cz>

Project homepage:
	http://logix.cz/michal/devel/mini-printf

Source download:
	https://github.com/mludvig/mini-printf

Donations:
	http://logix.cz/michal/devel/donations

License
-------
Copyright (c) 2013,2014 Michal Ludvig <michal@logix.cz>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the auhor nor the names of its contributors
      may be used to endorse or promote products derived from this software
      without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
