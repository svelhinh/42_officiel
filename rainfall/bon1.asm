08048424 <main>:
 8048424:       55                      push   ebp
 8048425:       89 e5                   mov    ebp,esp
 8048427:       83 e4 f0                and    esp,0xfffffff0
 804842a:       83 ec 40                sub    esp,0x40
 804842d:       8b 45 0c                mov    eax,DWORD PTR [ebp+0xc]
 8048430:       83 c0 04                add    eax,0x4
 8048433:       8b 00                   mov    eax,DWORD PTR [eax]
 8048435:       89 04 24                mov    DWORD PTR [esp],eax
 8048438:       e8 23 ff ff ff          call   8048360 <atoi@plt>
 804843d:       89 44 24 3c             mov    DWORD PTR [esp+0x3c],eax
 8048441:       83 7c 24 3c 09          cmp    DWORD PTR [esp+0x3c],0x9
 8048446:       7e 07                   jle    804844f <main+0x2b>
 8048448:       b8 01 00 00 00          mov    eax,0x1
 804844d:       eb 54                   jmp    80484a3 <main+0x7f>
 804844f:       8b 44 24 3c             mov    eax,DWORD PTR [esp+0x3c]
 8048453:       8d 0c 85 00 00 00 00    lea    ecx,[eax*4+0x0]
 804845a:       8b 45 0c                mov    eax,DWORD PTR [ebp+0xc]
 804845d:       83 c0 08                add    eax,0x8
 8048460:       8b 00                   mov    eax,DWORD PTR [eax]
 8048462:       89 c2                   mov    edx,eax
 8048464:       8d 44 24 14             lea    eax,[esp+0x14]
 8048468:       89 4c 24 08             mov    DWORD PTR [esp+0x8],ecx
 804846c:       89 54 24 04             mov    DWORD PTR [esp+0x4],edx
 8048470:       89 04 24                mov    DWORD PTR [esp],eax
 8048473:       e8 a8 fe ff ff          call   8048320 <memcpy@plt>
 8048478:       81 7c 24 3c 46 4c 4f    cmp    DWORD PTR [esp+0x3c],0x574f4c46
 804847f:       57
 8048480:       75 1c                   jne    804849e <main+0x7a>
 8048482:       c7 44 24 08 00 00 00    mov    DWORD PTR [esp+0x8],0x0
 8048489:       00
 804848a:       c7 44 24 04 80 85 04    mov    DWORD PTR [esp+0x4],0x8048580
 8048491:       08
 8048492:       c7 04 24 83 85 04 08    mov    DWORD PTR [esp],0x8048583
 8048499:       e8 b2 fe ff ff          call   8048350 <execl@plt>
 804849e:       b8 00 00 00 00          mov    eax,0x0
 80484a3:       c9                      leave
 80484a4:       c3                      ret