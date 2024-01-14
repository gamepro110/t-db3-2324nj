# hardfault notes

src: [info blog](<https://interrupt.memfault.com/blog/cortex-m-hardfault-debug>) (visited 2024-1-13)

cpu info: [pdf](<https://www.keil.com/appnotes/files/apnt209.pdf>) (visited 2024-1-13)

entire CFSR - 0xE000ED2A

![screenshot value](<UFSR val.png>)

base 10

> 1024

base2

> 0100 0000 0000

[this section](<https://interrupt.memfault.com/blog/cortex-m-hardfault-debug#relevant-status-registers>) goes a bit deeper on which part the error is in.  
mine was in the BFSR (busfault status register) lacated on `*(uint8_t *)0xE000ED29`.

## busfault

talked about [here](<https://interrupt.memfault.com/blog/cortex-m-hardfault-debug#imprecise-error-debug>).  
in the end the cause was my logger class

## links

- <https://www.google.com/search?client=firefox-b-d&q=cmsis-rtos2+detect+hardfault+reason>
- <https://interrupt.memfault.com/blog/cortex-m-hardfault-debug>
- <https://www.google.com/search?q=arm+cortex+m4+UsageFault+Status+Register&client=firefox-b-d&sca_esv=598179004&ei=27miZYjSN_uW9u8P7u-0uAM&ved=0ahUKEwjIq--D5NqDAxV7i_0HHe43DTcQ4dUDCBA&uact=5&oq=arm+cortex+m4+UsageFault+Status+Register&gs_lp=Egxnd3Mtd2l6LXNlcnAiKGFybSBjb3J0ZXggbTQgVXNhZ2VGYXVsdCBTdGF0dXMgUmVnaXN0ZXIyCBAAGIAEGKIEMggQABiABBiiBEinYFCJGFjBVXABeAGQAQCYAXagAZQKqgEEMTEuM7gBA8gBAPgBAcICChAAGEcY1gQYsAPCAggQIRigARjDBMICBhAAGB4YDcICChAhGAoYoAEYwwTiAwQYACBBiAYBkAYG&sclient=gws-wiz-serp>
- <https://www.google.com/search?client=firefox-b-d&q=what+can+cause+INVPC+on+arm+cortex+m4>
- <https://www.keil.com/appnotes/files/apnt209.pdf>
