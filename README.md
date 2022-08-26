# queue-in-C
This queue uses a linked list. That means it can theoretically store infinite values. You can choose whether you want padding or packing.
Just uncomment the fourth line if you want packing. There's a detailed explanation above the SIZE_OVER_SPEED macro. There's a tester program(test.c) that inserts hardcoded values into the queue and dequeues them. Output is correct, which means the program works. The program was also checked for memory leaks and none were found. 
## Valgrind output
==9624== Memcheck, a memory error detector
==9624== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==9624== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info
==9624== Command: ./test
==9624== 
4	3	2	1	
1	2	3	4	
==9624== 
==9624== HEAP SUMMARY:
==9624==     in use at exit: 0 bytes in 0 blocks
==9624==   total heap usage: 5 allocs, 5 frees, 1,120 bytes allocated
==9624== 
==9624== All heap blocks were freed -- no leaks are possible
==9624== 
==9624== For lists of detected and suppressed errors, rerun with: -s
==9624== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
## LeakSanitizer(libasan) output
(nothing, which means no leaks.)

If someone thinks this queue can be made better, please create a pull request or an issue.
