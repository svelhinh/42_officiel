08048484 <greetuser>:
 8048484:       55                      push   ebp
 8048485:       89 e5                   mov    ebp,esp
 8048487:       83 ec 58                sub    esp,0x58
 804848a:       a1 88 99 04 08          mov    eax,ds:0x8049988
 804848f:       83 f8 01                cmp    eax,0x1
 8048492:       74 26                   je     80484ba <greetuser+0x36>
 8048494:       83 f8 02                cmp    eax,0x2
 8048497:       74 50                   je     80484e9 <greetuser+0x65>
 8048499:       85 c0                   test   eax,eax
 804849b:       75 6d                   jne    804850a <greetuser+0x86>
 804849d:       ba 10 87 04 08          mov    edx,0x8048710
 80484a2:       8d 45 b8                lea    eax,[ebp-0x48]
 80484a5:       8b 0a                   mov    ecx,DWORD PTR [edx]
 80484a7:       89 08                   mov    DWORD PTR [eax],ecx
 80484a9:       0f b7 4a 04             movzx  ecx,WORD PTR [edx+0x4]
 80484ad:       66 89 48 04             mov    WORD PTR [eax+0x4],cx
 80484b1:       0f b6 52 06             movzx  edx,BYTE PTR [edx+0x6]
 80484b5:       88 50 06                mov    BYTE PTR [eax+0x6],dl
 80484b8:       eb 50                   jmp    804850a <greetuser+0x86>
 80484ba:       ba 17 87 04 08          mov    edx,0x8048717
 80484bf:       8d 45 b8                lea    eax,[ebp-0x48]
 80484c2:       8b 0a                   mov    ecx,DWORD PTR [edx]
 80484c4:       89 08                   mov    DWORD PTR [eax],ecx
 80484c6:       8b 4a 04                mov    ecx,DWORD PTR [edx+0x4]
 80484c9:       89 48 04                mov    DWORD PTR [eax+0x4],ecx
 80484cc:       8b 4a 08                mov    ecx,DWORD PTR [edx+0x8]
 80484cf:       89 48 08                mov    DWORD PTR [eax+0x8],ecx
 80484d2:       8b 4a 0c                mov    ecx,DWORD PTR [edx+0xc]
 80484d5:       89 48 0c                mov    DWORD PTR [eax+0xc],ecx
 80484d8:       0f b7 4a 10             movzx  ecx,WORD PTR [edx+0x10]
 80484dc:       66 89 48 10             mov    WORD PTR [eax+0x10],cx
 80484e0:       0f b6 52 12             movzx  edx,BYTE PTR [edx+0x12]
 80484e4:       88 50 12                mov    BYTE PTR [eax+0x12],dl
 80484e7:       eb 21                   jmp    804850a <greetuser+0x86>
 80484e9:       ba 2a 87 04 08          mov    edx,0x804872a
 80484ee:       8d 45 b8                lea    eax,[ebp-0x48]
 80484f1:       8b 0a                   mov    ecx,DWORD PTR [edx]
 80484f3:       89 08                   mov    DWORD PTR [eax],ecx
 80484f5:       8b 4a 04                mov    ecx,DWORD PTR [edx+0x4]
 80484f8:       89 48 04                mov    DWORD PTR [eax+0x4],ecx
 80484fb:       8b 4a 08                mov    ecx,DWORD PTR [edx+0x8]
 80484fe:       89 48 08                mov    DWORD PTR [eax+0x8],ecx
 8048501:       0f b7 52 0c             movzx  edx,WORD PTR [edx+0xc]
 8048505:       66 89 50 0c             mov    WORD PTR [eax+0xc],dx
 8048509:       90                      nop
 804850a:       8d 45 08                lea    eax,[ebp+0x8]
 804850d:       89 44 24 04             mov    DWORD PTR [esp+0x4],eax
 8048511:       8d 45 b8                lea    eax,[ebp-0x48]
 8048514:       89 04 24                mov    DWORD PTR [esp],eax
 8048517:       e8 54 fe ff ff          call   8048370 <strcat@plt>
 804851c:       8d 45 b8                lea    eax,[ebp-0x48]
 804851f:       89 04 24                mov    DWORD PTR [esp],eax
 8048522:       e8 69 fe ff ff          call   8048390 <puts@plt>
 8048527:       c9                      leave
 8048528:       c3                      ret

08048529 <main>:
 8048529:       55                      push   ebp
 804852a:       89 e5                   mov    ebp,esp
 804852c:       57                      push   edi
 804852d:       56                      push   esi
 804852e:       53                      push   ebx
 804852f:       83 e4 f0                and    esp,0xfffffff0
 8048532:       81 ec a0 00 00 00       sub    esp,0xa0
 8048538:       83 7d 08 03             cmp    DWORD PTR [ebp+0x8],0x3
 804853c:       74 0a                   je     8048548 <main+0x1f>
 804853e:       b8 01 00 00 00          mov    eax,0x1
 8048543:       e9 e8 00 00 00          jmp    8048630 <main+0x107>
 8048548:       8d 5c 24 50             lea    ebx,[esp+0x50]
 804854c:       b8 00 00 00 00          mov    eax,0x0
 8048551:       ba 13 00 00 00          mov    edx,0x13
 8048556:       89 df                   mov    edi,ebx
 8048558:       89 d1                   mov    ecx,edx
 804855a:       f3 ab                   rep stos DWORD PTR es:[edi],eax
 804855c:       8b 45 0c                mov    eax,DWORD PTR [ebp+0xc]
 804855f:       83 c0 04                add    eax,0x4
 8048562:       8b 00                   mov    eax,DWORD PTR [eax]
 8048564:       c7 44 24 08 28 00 00    mov    DWORD PTR [esp+0x8],0x28
 804856b:       00
 804856c:       89 44 24 04             mov    DWORD PTR [esp+0x4],eax
 8048570:       8d 44 24 50             lea    eax,[esp+0x50]
 8048574:       89 04 24                mov    DWORD PTR [esp],eax
 8048577:       e8 44 fe ff ff          call   80483c0 <strncpy@plt>
 804857c:       8b 45 0c                mov    eax,DWORD PTR [ebp+0xc]
 804857f:       83 c0 08                add    eax,0x8
 8048582:       8b 00                   mov    eax,DWORD PTR [eax]
 8048584:       c7 44 24 08 20 00 00    mov    DWORD PTR [esp+0x8],0x20
 804858b:       00
 804858c:       89 44 24 04             mov    DWORD PTR [esp+0x4],eax
 8048590:       8d 44 24 50             lea    eax,[esp+0x50]
 8048594:       83 c0 28                add    eax,0x28
 8048597:       89 04 24                mov    DWORD PTR [esp],eax
 804859a:       e8 21 fe ff ff          call   80483c0 <strncpy@plt>
 804859f:       c7 04 24 38 87 04 08    mov    DWORD PTR [esp],0x8048738
 80485a6:       e8 d5 fd ff ff          call   8048380 <getenv@plt>
 80485ab:       89 84 24 9c 00 00 00    mov    DWORD PTR [esp+0x9c],eax
 80485b2:       83 bc 24 9c 00 00 00    cmp    DWORD PTR [esp+0x9c],0x0
 80485b9:       00
 80485ba:       74 5c                   je     8048618 <main+0xef>
 80485bc:       c7 44 24 08 02 00 00    mov    DWORD PTR [esp+0x8],0x2
 80485c3:       00
 80485c4:       c7 44 24 04 3d 87 04    mov    DWORD PTR [esp+0x4],0x804873d
 80485cb:       08
 80485cc:       8b 84 24 9c 00 00 00    mov    eax,DWORD PTR [esp+0x9c]
 80485d3:       89 04 24                mov    DWORD PTR [esp],eax
 80485d6:       e8 85 fd ff ff          call   8048360 <memcmp@plt>
 80485db:       85 c0                   test   eax,eax
 80485dd:       75 0c                   jne    80485eb <main+0xc2>
 80485df:       c7 05 88 99 04 08 01    mov    DWORD PTR ds:0x8049988,0x1
 80485e6:       00 00 00
 80485e9:       eb 2d                   jmp    8048618 <main+0xef>
 80485eb:       c7 44 24 08 02 00 00    mov    DWORD PTR [esp+0x8],0x2
 80485f2:       00
 80485f3:       c7 44 24 04 40 87 04    mov    DWORD PTR [esp+0x4],0x8048740
 80485fa:       08
 80485fb:       8b 84 24 9c 00 00 00    mov    eax,DWORD PTR [esp+0x9c]
 8048602:       89 04 24                mov    DWORD PTR [esp],eax
 8048605:       e8 56 fd ff ff          call   8048360 <memcmp@plt>
 804860a:       85 c0                   test   eax,eax
 804860c:       75 0a                   jne    8048618 <main+0xef>
 804860e:       c7 05 88 99 04 08 02    mov    DWORD PTR ds:0x8049988,0x2
 8048615:       00 00 00
 8048618:       89 e2                   mov    edx,esp
 804861a:       8d 5c 24 50             lea    ebx,[esp+0x50]
 804861e:       b8 13 00 00 00          mov    eax,0x13
 8048623:       89 d7                   mov    edi,edx
 8048625:       89 de                   mov    esi,ebx
 8048627:       89 c1                   mov    ecx,eax
 8048629:       f3 a5                   rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
 804862b:       e8 54 fe ff ff          call   8048484 <greetuser>
 8048630:       8d 65 f4                lea    esp,[ebp-0xc]
 8048633:       5b                      pop    ebx
 8048634:       5e                      pop    esi
 8048635:       5f                      pop    edi
 8048636:       5d                      pop    ebp
 8048637:       c3                      ret