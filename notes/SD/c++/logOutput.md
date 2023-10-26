# valgrind error log output

>raw output

```log
==41694== Memcheck, a memory error detector
==41694== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==41694== Using Valgrind-3.21.0-d97fed7c3e-20230428 and LibVEX; rerun with -h for copyright info
==41694== Command: ./CarRental
==41694==  
--41694-- Valgrind options:
--41694--    -v
--41694--    --leak-check=yes
--41694--    --show-leak-kinds=all
--41694-- Contents of /proc/version:
--41694--   Linux version 6.6.0-1-MANJARO (builduser@fv-az953-872) (gcc (GCC) 13.2.1 20230801, GNU ld (GNU Binutils)
2.41.0) #1 SMP PREEMPT_DYNAMIC Mon Oct  2 22:30:04 UTC 2023
--41694--  
--41694-- Arch and hwcaps: AMD64, LittleEndian, amd64-cx16-lzcnt-rdtscp-sse3-ssse3-avx-avx2-bmi-f16c-rdrand-rdseed
--41694-- Page sizes: currently 4096, max supported 4096
--41694-- Valgrind library directory: /usr/lib/valgrind
--41694-- Reading syms from /home/void/school/t-db3-2324nj-karlo-koelewijn/SD/cpp/CarRental_C++/CarRental
--41694-- Reading syms from /usr/lib/ld-linux-x86-64.so.2
==41694== Downloading debug info for /usr/lib/ld-linux-x86-64.so.2...
--41694--   Considering /home/void/.cache/debuginfod_client/6ebd6e95dffa2afcbdaf7b7c91103b23ecf2b012/debuginfo ..
--41694--   .. CRC is valid
==41694== Successfully downloaded debug file for /usr/lib/ld-linux-x86-64.so.2
--41694-- Reading syms from /usr/lib/valgrind/memcheck-amd64-linux
==41694== Downloading debug info for /usr/lib/valgrind/memcheck-amd64-linux...
--41694--   Considering /home/void/.cache/debuginfod_client/4efee52aade45b84c3c34acbcf7e3a30dbc49e62/debuginfo ..
--41694--   .. CRC is valid
==41694== Successfully downloaded debug file for /usr/lib/valgrind/memcheck-amd64-linux
--41694--    object doesn't have a dynamic symbol table
--41694-- Scheduler: using generic scheduler lock implementation.
--41694-- Reading suppressions file: /usr/lib/valgrind/default.supp
==41694== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-41694-by-void-on-???
==41694== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-41694-by-void-on-???
==41694== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-41694-by-void-on-???
==41694==  
==41694== TO CONTROL THIS PROCESS USING vgdb (which you probably
==41694== don't want to do, unless you know exactly what you're doing,
==41694== or are doing some strange experiment):
==41694==   /usr/lib/valgrind/../../bin/vgdb --pid=41694 ...command...
==41694==  
==41694== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==41694==   /path/to/gdb ./CarRental
==41694== and then give GDB the following command
==41694==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=41694
==41694== --pid is optional if only one valgrind process is running
==41694==  
--41694-- REDIR: 0x40241e0 (ld-linux-x86-64.so.2:strlen) redirected to 0x580c1122 (vgPlain_amd64_linux_REDIR_FOR_str
len)
--41694-- REDIR: 0x4022990 (ld-linux-x86-64.so.2:index) redirected to 0x580c113c (vgPlain_amd64_linux_REDIR_FOR_inde
x)
--41694-- Reading syms from /usr/lib/valgrind/vgpreload_core-amd64-linux.so
==41694== Downloading debug info for /usr/lib/valgrind/vgpreload_core-amd64-linux.so...
--41694--   Considering /home/void/.cache/debuginfod_client/060a58c2256ae9a895586d0231020becccaadf3a/debuginfo ..
--41694--   .. CRC is valid
==41694== Successfully downloaded debug file for /usr/lib/valgrind/vgpreload_core-amd64-linux.so
--41694-- Reading syms from /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so
==41694== Downloading debug info for /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so...
--41694--   Considering /home/void/.cache/debuginfod_client/23b76fcedd76ac77e136ed69676378bd047b5ff2/debuginfo ..
--41694--   .. CRC is valid
==41694== Successfully downloaded debug file for /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so
==41694== WARNING: new redirection conflicts with existing -- ignoring it
--41694--     old: 0x040241e0 (strlen              ) R-> (0000.0) 0x580c1122 vgPlain_amd64_linux_REDIR_FOR_strlen
--41694--     new: 0x040241e0 (strlen              ) R-> (2007.0) 0x04847fe0 strlen
--41694-- REDIR: 0x4022bc0 (ld-linux-x86-64.so.2:strcmp) redirected to 0x4849100 (strcmp)
--41694-- REDIR: 0x4021ff0 (ld-linux-x86-64.so.2:mempcpy) redirected to 0x484cef0 (mempcpy)
--41694-- Reading syms from /usr/lib/libstdc++.so.6.0.32
--41694-- Reading syms from /usr/lib/libm.so.6
==41694== Downloading debug info for /usr/lib/libm.so.6...
--41694--   Considering /home/void/.cache/debuginfod_client/90e8fc2234ada419e7ad4d2222939e088b9dbb31/debuginfo ..
--41694--   .. CRC is valid
==41694== Successfully downloaded debug file for /usr/lib/libm.so.6
--41694-- Reading syms from /usr/lib/libgcc_s.so.1
--41694-- Reading syms from /usr/lib/libc.so.6
==41694== Downloading debug info for /usr/lib/libc.so.6...
--41694--   Considering /home/void/.cache/debuginfod_client/8bfe03f6bf9b6a6e2591babd0bbc266837d8f658/debuginfo ..
--41694--   .. CRC is valid
==41694== Successfully downloaded debug file for /usr/lib/libc.so.6
--41694-- REDIR: 0x4024380 (ld-linux-x86-64.so.2:strncmp) redirected to 0x4848930 (strncmp)
--41694-- REDIR: 0x4cb7e10 (libc.so.6:strncasecmp) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb51c0 (libc.so.6:mempcpy) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb5520 (libc.so.6:stpcpy) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4d33430 (libc.so.6:__memmove_chk) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cd8740 (libc.so.6:wmemcmp) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb6070 (libc.so.6:strcat) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb4950 (libc.so.6:memcpy@@GLIBC_2.14) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4d33310 (libc.so.6:__memcpy_chk) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
==41694== WARNING: new redirection conflicts with existing -- ignoring it
--41694--     old: 0x04d6c150 (__memcpy_chk_avx_una) R-> (2024.0) 0x0484c960 __memmove_chk
--41694--     new: 0x04d6c150 (__memcpy_chk_avx_una) R-> (2030.0) 0x0484cff0 __memcpy_chk
--41694-- REDIR: 0x4ccca00 (libc.so.6:wcslen) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb5370 (libc.so.6:memset) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4ccd280 (libc.so.6:wcsnlen) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb8100 (libc.so.6:strnlen) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb8190 (libc.so.6:strpbrk) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb61f0 (libc.so.6:strcmp) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb52e0 (libc.so.6:memrchr) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4ccb7c0 (libc.so.6:wcschr) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb60e0 (libc.so.6:index) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb81c0 (libc.so.6:rindex) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4ccb870 (libc.so.6:wcscmp) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb5590 (libc.so.6:stpncpy) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cd86c0 (libc.so.6:wmemchr) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb7fb0 (libc.so.6:strncmp) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb55f0 (libc.so.6:strcasecmp) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb7390 (libc.so.6:strcspn) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4ccc7f0 (libc.so.6:wcscpy) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb7eb0 (libc.so.6:strncasecmp_l) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb6160 (libc.so.6:strchrnul) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb4860 (libc.so.6:bcmp) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb7320 (libc.so.6:strcpy) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb5690 (libc.so.6:strcasecmp_l) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb7d80 (libc.so.6:strlen) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb8050 (libc.so.6:strncpy) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb50a0 (libc.so.6:memmove) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
==41694== Preferring higher priority redirection:
--41694--     old: 0x04d6c180 (__memcpy_avx_unalign) R-> (2018.0) 0x0484a4e0 __memcpy_avx_unaligned_erms
--41694--     new: 0x04d6c180 (__memcpy_avx_unalign) R-> (2018.1) 0x0484bf80 memmove
--41694-- REDIR: 0x4cb47e0 (libc.so.6:memchr) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb8380 (libc.so.6:strspn) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4cb8b30 (libc.so.6:strstr) redirected to 0x48361c0 (_vgnU_ifunc_wrapper)
--41694-- REDIR: 0x4d70d70 (libc.so.6:__strrchr_avx2) redirected to 0x48479c0 (rindex)
--41694-- REDIR: 0x4d6eec0 (libc.so.6:__strlen_avx2) redirected to 0x4847ec0 (strlen)
--41694-- REDIR: 0x4d6ba20 (libc.so.6:__memcmp_avx2_movbe) redirected to 0x484b6a0 (bcmp)
--41694-- REDIR: 0x4d6ffa0 (libc.so.6:__strncmp_avx2) redirected to 0x4848750 (strncmp)
--41694-- REDIR: 0x4cb0c10 (libc.so.6:malloc) redirected to 0x48417d0 (malloc)
--41694-- REDIR: 0x4d6c180 (libc.so.6:__memcpy_avx_unaligned_erms) redirected to 0x484bf80 (memmove)
--41694-- REDIR: 0x4937880 (libstdc++.so.6:operator new(unsigned long)) redirected to 0x4841f50 (operator new(unsign
ed long))
--41694-- REDIR: 0x4935ab0 (libstdc++.so.6:operator delete(void*)) redirected to 0x48446f0 (operator delete(void*))


Car Rental menu
--41694-- REDIR: 0x4d6c140 (libc.so.6:__mempcpy_avx_unaligned_erms) redirected to 0x484caf0 (mempcpy)
===============
(1) Show all cars
(2) Select car
(3) Rent selected car
(4) Return selected car
(5) Check if car needs cleaning
(6) Clean car
-----------------------
(9) QUIT

Choice : 2
These cars are currently listed:
0) BMW - 535d, SD-001
1) BMW - 535d, SD-002
2) BMW - 535d, SD-003
3) BMW - 535d, SD-004
4) Rolls Roys - Phantom Extended Wheelbase, LM-001
5) Rolls Roys - Phantom Extended Wheelbase, LM-002

Please enter a car number: 1


Car Rental menu
===============
(1) Show all cars
(2) Select car
(3) Rent selected car
(4) Return selected car
(5) Check if car needs cleaning
(6) Clean car
-----------------------
(9) QUIT

Choice : 3


Car Rental menu
===============
(1) Show all cars
(2) Select car
(3) Rent selected car
(4) Return selected car
(5) Check if car needs cleaning
(6) Clean car
-----------------------
(9) QUIT

Choice : 4
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x10A659: Car::Return(int) (Car.cpp:41)
==41694==    by 0x10BEB1: RentalAdministration::ReturnCar(std::__cxx11::basic_string<char, std::char_traits<char>, s
td::allocator<char> > const&, int) (RentalAdministration.cpp:48)
==41694==    by 0x10B5A5: returnCar(RentalAdministration*, unsigned long) (main.cpp:87)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
--41694-- REDIR: 0x4d6e520 (libc.so.6:__strchrnul_avx2) redirected to 0x484c9d0 (strchrnul)
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B071: __printf_fp_buffer_1.isra.0 (printf_fp.c:230)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B08B: __printf_fp_buffer_1.isra.0 (printf_fp.c:230)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C65696: __mpn_extract_double (dbl2mpn.c:56)
==41694==    by 0x4C6B77E: __printf_fp_buffer_1.isra.0 (printf_fp.c:230)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B169: __printf_fp_buffer_1.isra.0 (printf_fp.c:271)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B18C: __printf_fp_buffer_1.isra.0 (printf_fp.c:271)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6B18E: __printf_fp_buffer_1.isra.0 (printf_fp.c:271)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B1BE: __printf_fp_buffer_1.isra.0 (printf_fp.c:272)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B1E1: __printf_fp_buffer_1.isra.0 (printf_fp.c:272)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6B1E3: __printf_fp_buffer_1.isra.0 (printf_fp.c:272)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B20C: __printf_fp_buffer_1.isra.0 (printf_fp.c:273)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B22F: __printf_fp_buffer_1.isra.0 (printf_fp.c:273)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6B231: __printf_fp_buffer_1.isra.0 (printf_fp.c:273)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B250: __printf_fp_buffer_1.isra.0 (printf_fp.c:280)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B26A: __printf_fp_buffer_1.isra.0 (printf_fp.c:297)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6C12E: __printf_fp_buffer_1.isra.0 (printf_fp.c:305)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C641FC: __mpn_lshift (lshift.S:59)
==41694==    by 0x4C6C132: __printf_fp_buffer_1.isra.0 (printf_fp.c:305)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C641FF: __mpn_lshift (lshift.S:60)
==41694==    by 0x4C6C132: __printf_fp_buffer_1.isra.0 (printf_fp.c:305)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6C162: __printf_fp_buffer_1.isra.0 (printf_fp.c:310)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6C17A: __printf_fp_buffer_1.isra.0 (printf_fp.c:311)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B2A0: __printf_fp_buffer_1.isra.0 (printf_fp.c:313)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B35F: __printf_fp_buffer_1.isra.0 (printf_fp.c:322)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x484BF9E: memmove (vg_replace_strmem.c:1400)
==41694==    by 0x4C6B31A: memcpy (string_fortified.h:29)
==41694==    by 0x4C6B31A: __printf_fp_buffer_1.isra.0 (printf_fp.c:369)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x484BFAB: is_overlap (vg_replace_strmem.c:141)
==41694==    by 0x484BFAB: is_overlap (vg_replace_strmem.c:128)
==41694==    by 0x484BFAB: memmove (vg_replace_strmem.c:1400)
==41694==    by 0x4C6B31A: memcpy (string_fortified.h:29)
==41694==    by 0x4C6B31A: __printf_fp_buffer_1.isra.0 (printf_fp.c:369)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x484BFB8: memmove (vg_replace_strmem.c:1400)
==41694==    by 0x4C6B31A: memcpy (string_fortified.h:29)
==41694==    by 0x4C6B31A: __printf_fp_buffer_1.isra.0 (printf_fp.c:369)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x484C081: memmove (vg_replace_strmem.c:1400)
==41694==    by 0x4C6B31A: memcpy (string_fortified.h:29)
==41694==    by 0x4C6B31A: __printf_fp_buffer_1.isra.0 (printf_fp.c:369)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B326: __printf_fp_buffer_1.isra.0 (printf_fp.c:385)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B32C: __printf_fp_buffer_1.isra.0 (printf_fp.c:385)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63AB6: __mpn_cmp (cmp.c:37)
==41694==    by 0x4C6BCD7: __printf_fp_buffer_1.isra.0 (printf_fp.c:385)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63ABA: __mpn_cmp (cmp.c:38)
==41694==    by 0x4C6BCD7: __printf_fp_buffer_1.isra.0 (printf_fp.c:385)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C63AC1: __mpn_cmp (cmp.c:39)
==41694==    by 0x4C6BCD7: __printf_fp_buffer_1.isra.0 (printf_fp.c:385)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6BCDA: __printf_fp_buffer_1.isra.0 (printf_fp.c:385)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x484BF9E: memmove (vg_replace_strmem.c:1400)
==41694==    by 0x4C6B3C5: memcpy (string_fortified.h:29)
==41694==    by 0x4C6B3C5: __printf_fp_buffer_1.isra.0 (printf_fp.c:388)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x484C07E: memmove (vg_replace_strmem.c:1400)
==41694==    by 0x4C6B3C5: memcpy (string_fortified.h:29)
==41694==    by 0x4C6B3C5: __printf_fp_buffer_1.isra.0 (printf_fp.c:388)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x484C081: memmove (vg_replace_strmem.c:1400)
==41694==    by 0x4C6B3C5: memcpy (string_fortified.h:29)
==41694==    by 0x4C6B3C5: __printf_fp_buffer_1.isra.0 (printf_fp.c:388)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x484C08C: memmove (vg_replace_strmem.c:1400)
==41694==    by 0x4C6B3C5: memcpy (string_fortified.h:29)
==41694==    by 0x4C6B3C5: __printf_fp_buffer_1.isra.0 (printf_fp.c:388)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6B3CE: __printf_fp_buffer_1.isra.0 (printf_fp.c:389)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C64758: __mpn_mul_1 (mul_1.S:36)
==41694==    by 0x4C64590: __mpn_mul (mul.c:81)
==41694==    by 0x4C6B389: __printf_fp_buffer_1.isra.0 (printf_fp.c:375)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C647E3: __mpn_mul_1 (mul_1.S:85)
==41694==    by 0x4C64590: __mpn_mul (mul.c:81)
==41694==    by 0x4C6B389: __printf_fp_buffer_1.isra.0 (printf_fp.c:375)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C64852: __mpn_mul_1 (mul_1.S:117)
==41694==    by 0x4C64590: __mpn_mul (mul.c:81)
==41694==    by 0x4C6B389: __printf_fp_buffer_1.isra.0 (printf_fp.c:375)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6459D: __mpn_mul (mul.c:83)
==41694==    by 0x4C6B389: __printf_fp_buffer_1.isra.0 (printf_fp.c:375)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6B421: __printf_fp_buffer_1.isra.0 (printf_fp.c:411)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6B426: __printf_fp_buffer_1.isra.0 (printf_fp.c:407)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6B44A: __printf_fp_buffer_1.isra.0 (printf_fp.c:407)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B471: __printf_fp_buffer_1.isra.0 (printf_fp.c:407)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6B450: __printf_fp_buffer_1.isra.0 (printf_fp.c:407)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6C897: __printf_fp_buffer_1.isra.0 (printf_fp.c:430)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6C839: __printf_fp_buffer_1.isra.0 (printf_fp.c:452)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C653FC: __mpn_rshift (rshift.S:62)
==41694==    by 0x4C6C851: __printf_fp_buffer_1.isra.0 (printf_fp.c:470)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C65421: __mpn_rshift (rshift.S:73)
==41694==    by 0x4C6C851: __printf_fp_buffer_1.isra.0 (printf_fp.c:470)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C653A9: __mpn_rshift (rshift.S:31)
==41694==    by 0x4C6C872: __printf_fp_buffer_1.isra.0 (printf_fp.c:474)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C653D0: __mpn_rshift (rshift.S:45)
==41694==    by 0x4C6C872: __printf_fp_buffer_1.isra.0 (printf_fp.c:474)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C653FA: __mpn_rshift (rshift.S:61)
==41694==    by 0x4C6C872: __printf_fp_buffer_1.isra.0 (printf_fp.c:474)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C653FC: __mpn_rshift (rshift.S:62)
==41694==    by 0x4C6C872: __printf_fp_buffer_1.isra.0 (printf_fp.c:474)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6540D: __mpn_rshift (rshift.S:67)
==41694==    by 0x4C6C872: __printf_fp_buffer_1.isra.0 (printf_fp.c:474)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C65421: __mpn_rshift (rshift.S:73)
==41694==    by 0x4C6C872: __printf_fp_buffer_1.isra.0 (printf_fp.c:474)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6C887: __printf_fp_buffer_1.isra.0 (printf_fp.c:478)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6C88D: __printf_fp_buffer_1.isra.0 (printf_fp.c:478)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6AD21: hack_digit (printf_fp.c:101)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63EA0: __mpn_divrem (divrem.c:62)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63EA3: __mpn_divrem (divrem.c:63)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C63EB4: __mpn_divrem (divrem.c:65)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C63EBD: __mpn_divrem (divrem.c:72)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63ED0: __mpn_divrem (divrem.c:73)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63EDF: __mpn_divrem (divrem.c:73)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C63EE7: __mpn_divrem (divrem.c:72)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63F15: __mpn_divrem (divrem.c:79)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6AD84: hack_digit (printf_fp.c:107)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6AD8C: hack_digit (printf_fp.c:108)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6AD9C: hack_digit (printf_fp.c:111)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6ADB0: hack_digit (printf_fp.c:111)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C64758: __mpn_mul_1 (mul_1.S:36)
==41694==    by 0x4C6AD34: hack_digit (printf_fp.c:122)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6477C: __mpn_mul_1 (mul_1.S:52)
==41694==    by 0x4C6AD34: hack_digit (printf_fp.c:122)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6AD38: hack_digit (printf_fp.c:123)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6AD4A: hack_digit (printf_fp.c:124)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6C253: __printf_fp_buffer_1.isra.0 (printf_fp.c:774)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6C257: __printf_fp_buffer_1.isra.0 (printf_fp.c:774)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6B89F: __printf_fp_buffer_1.isra.0 (printf_fp.c:790)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B8A3: __printf_fp_buffer_1.isra.0 (printf_fp.c:790)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B8B5: __printf_fp_buffer_1.isra.0 (printf_fp.c:805)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63EA0: __mpn_divrem (divrem.c:62)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6B8CD: __printf_fp_buffer_1.isra.0 (printf_fp.c:806)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63EA3: __mpn_divrem (divrem.c:63)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6B8CD: __printf_fp_buffer_1.isra.0 (printf_fp.c:806)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C63EB4: __mpn_divrem (divrem.c:65)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6B8CD: __printf_fp_buffer_1.isra.0 (printf_fp.c:806)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63F15: __mpn_divrem (divrem.c:79)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6B8CD: __printf_fp_buffer_1.isra.0 (printf_fp.c:806)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6AD84: hack_digit (printf_fp.c:107)
==41694==    by 0x4C6B8CD: __printf_fp_buffer_1.isra.0 (printf_fp.c:806)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6AD8C: hack_digit (printf_fp.c:108)
==41694==    by 0x4C6B8CD: __printf_fp_buffer_1.isra.0 (printf_fp.c:806)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6AD9C: hack_digit (printf_fp.c:111)
==41694==    by 0x4C6B8CD: __printf_fp_buffer_1.isra.0 (printf_fp.c:806)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6ADB0: hack_digit (printf_fp.c:111)
==41694==    by 0x4C6B8CD: __printf_fp_buffer_1.isra.0 (printf_fp.c:806)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6C213: __printf_fp_buffer_1.isra.0 (printf_fp.c:810)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6C217: __printf_fp_buffer_1.isra.0 (printf_fp.c:810)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B9B1: __printf_fp_buffer_1.isra.0 (printf_fp.c:931)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6BA9D: __printf_fp_buffer_1.isra.0 (printf_fp.c:987)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6BD43: __printf_fp_buffer_1.isra.0 (printf_fp.c:999)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
--41694-- REDIR: 0x4d6b780 (libc.so.6:__memchr_avx2) redirected to 0x4849180 (memchr)
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x48491A4: memchr (vg_replace_strmem.c:985)
==41694==    by 0x49BFA55: find (char_traits.h:421)
==41694==    by 0x49BFA55: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1070)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C98E5C: _IO_new_file_xsputn (fileops.c:1219)
==41694==    by 0x4C98E5C: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1197)
==41694==    by 0x4C8CAD1: fwrite (iofwrite.c:39)
==41694==    by 0x49BFCF2: sputn (streambuf:458)
==41694==    by 0x49BFCF2: _M_put (streambuf_iterator.h:327)
==41694==    by 0x49BFCF2: __write<char> (locale_facets.h:124)
==41694==    by 0x49BFCF2: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1118)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== Syscall param write(buf) points to uninitialised byte(s)
==41694==    at 0x4D18034: write (write.c:26)
==41694==    by 0x4C98D4C: _IO_file_write@@GLIBC_2.2.5 (fileops.c:1181)
==41694==    by 0x4C97013: new_do_write (fileops.c:449)
==41694==    by 0x4C97E18: _IO_do_write@@GLIBC_2.2.5 (fileops.c:426)
==41694==    by 0x4C98EC6: _IO_new_file_xsputn (fileops.c:1244)
==41694==    by 0x4C98EC6: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1197)
==41694==    by 0x4C8CAD1: fwrite (iofwrite.c:39)
==41694==    by 0x49CF9E4: sputn (streambuf:458)
==41694==    by 0x49CF9E4: __ostream_write<char, std::char_traits<char> > (ostream_insert.h:53)
==41694==    by 0x49CF9E4: std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_
traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long) (ostream_insert.h:104)
==41694==    by 0x49CFDBC: std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char
> >(std::basic_ostream<char, std::char_traits<char> >&, char const*) (ostream:667)
==41694==    by 0x10B635: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  Address 0x4e0d8e8 is 40 bytes inside a block of size 1,024 alloc'd
==41694==    at 0x4841848: malloc (vg_replace_malloc.c:431)
==41694==    by 0x4C8B499: _IO_file_doallocate (filedoalloc.c:101)
==41694==    by 0x4C9A278: _IO_doallocbuf (genops.c:347)
==41694==    by 0x4C9A278: _IO_doallocbuf (genops.c:342)
==41694==    by 0x4C983E7: _IO_file_overflow@@GLIBC_2.2.5 (fileops.c:745)
==41694==    by 0x4C98EC6: _IO_new_file_xsputn (fileops.c:1244)
==41694==    by 0x4C98EC6: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1197)
==41694==    by 0x4C8CAD1: fwrite (iofwrite.c:39)
==41694==    by 0x49CF9E4: sputn (streambuf:458)
==41694==    by 0x49CF9E4: __ostream_write<char, std::char_traits<char> > (ostream_insert.h:53)
==41694==    by 0x49CF9E4: std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_
traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long) (ostream_insert.h:104)
==41694==    by 0x49CFDBC: std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char
> >(std::basic_ostream<char, std::char_traits<char> >&, char const*) (ostream:667)
==41694==    by 0x10B913: showMenu() (main.cpp:121)
==41694==    by 0x10BA5A: main (main.cpp:145)
==41694==  
Car BMW - 535d, SD-002 returned. price: 145


Car Rental menu
===============
(1) Show all cars
(2) Select car
(3) Rent selected car
(4) Return selected car
(5) Check if car needs cleaning
(6) Clean car
-----------------------
(9) QUIT

Choice : 9   
--41694-- REDIR: 0x4cb12e0 (libc.so.6:free) redirected to 0x48440c0 (free)
==41694==  
==41694== HEAP SUMMARY:
==41694==     in use at exit: 0 bytes in 0 blocks
==41694==   total heap usage: 26 allocs, 26 frees, 77,341 bytes allocated
==41694==  
==41694== All heap blocks were freed -- no leaks are possible
==41694==  
==41694== Use --track-origins=yes to see where uninitialised values come from
==41694== ERROR SUMMARY: 144 errors from 96 contexts (suppressed: 0 from 0)
==41694==  
==41694== 1 errors in context 1 of 96:
==41694== Syscall param write(buf) points to uninitialised byte(s)
==41694==    at 0x4D18034: write (write.c:26)
==41694==    by 0x4C98D4C: _IO_file_write@@GLIBC_2.2.5 (fileops.c:1181)
==41694==    by 0x4C97013: new_do_write (fileops.c:449)
==41694==    by 0x4C97E18: _IO_do_write@@GLIBC_2.2.5 (fileops.c:426)
==41694==    by 0x4C98EC6: _IO_new_file_xsputn (fileops.c:1244)
==41694==    by 0x4C98EC6: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1197)
==41694==    by 0x4C8CAD1: fwrite (iofwrite.c:39)
==41694==    by 0x49CF9E4: sputn (streambuf:458)
==41694==    by 0x49CF9E4: __ostream_write<char, std::char_traits<char> > (ostream_insert.h:53)
==41694==    by 0x49CF9E4: std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_
traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long) (ostream_insert.h:104)
==41694==    by 0x49CFDBC: std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char
> >(std::basic_ostream<char, std::char_traits<char> >&, char const*) (ostream:667)
==41694==    by 0x10B635: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  Address 0x4e0d8e8 is 40 bytes inside a block of size 1,024 alloc'd
==41694==    at 0x4841848: malloc (vg_replace_malloc.c:431)
==41694==    by 0x4C8B499: _IO_file_doallocate (filedoalloc.c:101)
==41694==    by 0x4C9A278: _IO_doallocbuf (genops.c:347)
==41694==    by 0x4C9A278: _IO_doallocbuf (genops.c:342)
==41694==    by 0x4C983E7: _IO_file_overflow@@GLIBC_2.2.5 (fileops.c:745)
==41694==    by 0x4C98EC6: _IO_new_file_xsputn (fileops.c:1244)
==41694==    by 0x4C98EC6: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1197)
==41694==    by 0x4C8CAD1: fwrite (iofwrite.c:39)
==41694==    by 0x49CF9E4: sputn (streambuf:458)
==41694==    by 0x49CF9E4: __ostream_write<char, std::char_traits<char> > (ostream_insert.h:53)
==41694==    by 0x49CF9E4: std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_
traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long) (ostream_insert.h:104)
==41694==    by 0x49CFDBC: std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char
> >(std::basic_ostream<char, std::char_traits<char> >&, char const*) (ostream:667)
==41694==    by 0x10B913: showMenu() (main.cpp:121)
==41694==    by 0x10BA5A: main (main.cpp:145)
==41694==  
==41694==  
==41694== 1 errors in context 2 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6BD43: __printf_fp_buffer_1.isra.0 (printf_fp.c:999)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 3 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6BA9D: __printf_fp_buffer_1.isra.0 (printf_fp.c:987)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 4 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B9B1: __printf_fp_buffer_1.isra.0 (printf_fp.c:931)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 5 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6C217: __printf_fp_buffer_1.isra.0 (printf_fp.c:810)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 6 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6C213: __printf_fp_buffer_1.isra.0 (printf_fp.c:810)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 7 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6ADB0: hack_digit (printf_fp.c:111)
==41694==    by 0x4C6B8CD: __printf_fp_buffer_1.isra.0 (printf_fp.c:806)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 8 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6AD9C: hack_digit (printf_fp.c:111)
==41694==    by 0x4C6B8CD: __printf_fp_buffer_1.isra.0 (printf_fp.c:806)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 9 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6AD8C: hack_digit (printf_fp.c:108)
==41694==    by 0x4C6B8CD: __printf_fp_buffer_1.isra.0 (printf_fp.c:806)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 10 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6AD84: hack_digit (printf_fp.c:107)
==41694==    by 0x4C6B8CD: __printf_fp_buffer_1.isra.0 (printf_fp.c:806)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 11 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63F15: __mpn_divrem (divrem.c:79)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6B8CD: __printf_fp_buffer_1.isra.0 (printf_fp.c:806)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 12 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C63EB4: __mpn_divrem (divrem.c:65)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6B8CD: __printf_fp_buffer_1.isra.0 (printf_fp.c:806)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 13 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63EA3: __mpn_divrem (divrem.c:63)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6B8CD: __printf_fp_buffer_1.isra.0 (printf_fp.c:806)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 14 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63EA0: __mpn_divrem (divrem.c:62)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6B8CD: __printf_fp_buffer_1.isra.0 (printf_fp.c:806)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 15 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B8B5: __printf_fp_buffer_1.isra.0 (printf_fp.c:805)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 16 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B8A3: __printf_fp_buffer_1.isra.0 (printf_fp.c:790)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 17 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6B89F: __printf_fp_buffer_1.isra.0 (printf_fp.c:790)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 18 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6C257: __printf_fp_buffer_1.isra.0 (printf_fp.c:774)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 19 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6C253: __printf_fp_buffer_1.isra.0 (printf_fp.c:774)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 20 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C63EE7: __mpn_divrem (divrem.c:72)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 21 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C63EBD: __mpn_divrem (divrem.c:72)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 22 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6AD21: hack_digit (printf_fp.c:101)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 23 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6C88D: __printf_fp_buffer_1.isra.0 (printf_fp.c:478)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 24 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6C887: __printf_fp_buffer_1.isra.0 (printf_fp.c:478)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 25 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C65421: __mpn_rshift (rshift.S:73)
==41694==    by 0x4C6C872: __printf_fp_buffer_1.isra.0 (printf_fp.c:474)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 26 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6540D: __mpn_rshift (rshift.S:67)
==41694==    by 0x4C6C872: __printf_fp_buffer_1.isra.0 (printf_fp.c:474)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 27 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C653FC: __mpn_rshift (rshift.S:62)
==41694==    by 0x4C6C872: __printf_fp_buffer_1.isra.0 (printf_fp.c:474)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 28 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C653FA: __mpn_rshift (rshift.S:61)
==41694==    by 0x4C6C872: __printf_fp_buffer_1.isra.0 (printf_fp.c:474)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 29 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C653D0: __mpn_rshift (rshift.S:45)
==41694==    by 0x4C6C872: __printf_fp_buffer_1.isra.0 (printf_fp.c:474)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 30 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C653A9: __mpn_rshift (rshift.S:31)
==41694==    by 0x4C6C872: __printf_fp_buffer_1.isra.0 (printf_fp.c:474)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 31 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C65421: __mpn_rshift (rshift.S:73)
==41694==    by 0x4C6C851: __printf_fp_buffer_1.isra.0 (printf_fp.c:470)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 32 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C653FC: __mpn_rshift (rshift.S:62)
==41694==    by 0x4C6C851: __printf_fp_buffer_1.isra.0 (printf_fp.c:470)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 33 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6C839: __printf_fp_buffer_1.isra.0 (printf_fp.c:452)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 34 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6C897: __printf_fp_buffer_1.isra.0 (printf_fp.c:430)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 35 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6B450: __printf_fp_buffer_1.isra.0 (printf_fp.c:407)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 36 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B471: __printf_fp_buffer_1.isra.0 (printf_fp.c:407)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 37 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6B44A: __printf_fp_buffer_1.isra.0 (printf_fp.c:407)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 38 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6B426: __printf_fp_buffer_1.isra.0 (printf_fp.c:407)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 39 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6B421: __printf_fp_buffer_1.isra.0 (printf_fp.c:411)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 40 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6459D: __mpn_mul (mul.c:83)
==41694==    by 0x4C6B389: __printf_fp_buffer_1.isra.0 (printf_fp.c:375)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 41 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C64852: __mpn_mul_1 (mul_1.S:117)
==41694==    by 0x4C64590: __mpn_mul (mul.c:81)
==41694==    by 0x4C6B389: __printf_fp_buffer_1.isra.0 (printf_fp.c:375)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 42 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C647E3: __mpn_mul_1 (mul_1.S:85)
==41694==    by 0x4C64590: __mpn_mul (mul.c:81)
==41694==    by 0x4C6B389: __printf_fp_buffer_1.isra.0 (printf_fp.c:375)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 43 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C64758: __mpn_mul_1 (mul_1.S:36)
==41694==    by 0x4C64590: __mpn_mul (mul.c:81)
==41694==    by 0x4C6B389: __printf_fp_buffer_1.isra.0 (printf_fp.c:375)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 44 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6B3CE: __printf_fp_buffer_1.isra.0 (printf_fp.c:389)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 45 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x484C08C: memmove (vg_replace_strmem.c:1400)
==41694==    by 0x4C6B3C5: memcpy (string_fortified.h:29)
==41694==    by 0x4C6B3C5: __printf_fp_buffer_1.isra.0 (printf_fp.c:388)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 46 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x484C07E: memmove (vg_replace_strmem.c:1400)
==41694==    by 0x4C6B3C5: memcpy (string_fortified.h:29)
==41694==    by 0x4C6B3C5: __printf_fp_buffer_1.isra.0 (printf_fp.c:388)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 47 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x484BF9E: memmove (vg_replace_strmem.c:1400)
==41694==    by 0x4C6B3C5: memcpy (string_fortified.h:29)
==41694==    by 0x4C6B3C5: __printf_fp_buffer_1.isra.0 (printf_fp.c:388)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 48 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x484BFB8: memmove (vg_replace_strmem.c:1400)
==41694==    by 0x4C6B31A: memcpy (string_fortified.h:29)
==41694==    by 0x4C6B31A: __printf_fp_buffer_1.isra.0 (printf_fp.c:369)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 49 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x484BFAB: is_overlap (vg_replace_strmem.c:141)
==41694==    by 0x484BFAB: is_overlap (vg_replace_strmem.c:128)
==41694==    by 0x484BFAB: memmove (vg_replace_strmem.c:1400)
==41694==    by 0x4C6B31A: memcpy (string_fortified.h:29)
==41694==    by 0x4C6B31A: __printf_fp_buffer_1.isra.0 (printf_fp.c:369)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 50 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x484BF9E: memmove (vg_replace_strmem.c:1400)
==41694==    by 0x4C6B31A: memcpy (string_fortified.h:29)
==41694==    by 0x4C6B31A: __printf_fp_buffer_1.isra.0 (printf_fp.c:369)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 51 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B2A0: __printf_fp_buffer_1.isra.0 (printf_fp.c:313)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 52 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6C17A: __printf_fp_buffer_1.isra.0 (printf_fp.c:311)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 53 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6C162: __printf_fp_buffer_1.isra.0 (printf_fp.c:310)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 54 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C641FF: __mpn_lshift (lshift.S:60)
==41694==    by 0x4C6C132: __printf_fp_buffer_1.isra.0 (printf_fp.c:305)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 55 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C641FC: __mpn_lshift (lshift.S:59)
==41694==    by 0x4C6C132: __printf_fp_buffer_1.isra.0 (printf_fp.c:305)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 56 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6C12E: __printf_fp_buffer_1.isra.0 (printf_fp.c:305)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 57 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B26A: __printf_fp_buffer_1.isra.0 (printf_fp.c:297)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 58 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B250: __printf_fp_buffer_1.isra.0 (printf_fp.c:280)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 59 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6B231: __printf_fp_buffer_1.isra.0 (printf_fp.c:273)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 60 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B22F: __printf_fp_buffer_1.isra.0 (printf_fp.c:273)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 61 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B20C: __printf_fp_buffer_1.isra.0 (printf_fp.c:273)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 62 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6B1E3: __printf_fp_buffer_1.isra.0 (printf_fp.c:272)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 63 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B1E1: __printf_fp_buffer_1.isra.0 (printf_fp.c:272)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 64 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B1BE: __printf_fp_buffer_1.isra.0 (printf_fp.c:272)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 65 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6B18E: __printf_fp_buffer_1.isra.0 (printf_fp.c:271)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 66 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B18C: __printf_fp_buffer_1.isra.0 (printf_fp.c:271)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 67 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B169: __printf_fp_buffer_1.isra.0 (printf_fp.c:271)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 68 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C65696: __mpn_extract_double (dbl2mpn.c:56)
==41694==    by 0x4C6B77E: __printf_fp_buffer_1.isra.0 (printf_fp.c:230)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 69 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B08B: __printf_fp_buffer_1.isra.0 (printf_fp.c:230)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 70 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B071: __printf_fp_buffer_1.isra.0 (printf_fp.c:230)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 1 errors in context 71 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x10A659: Car::Return(int) (Car.cpp:41)
==41694==    by 0x10BEB1: RentalAdministration::ReturnCar(std::__cxx11::basic_string<char, std::char_traits<char>, s
td::allocator<char> > const&, int) (RentalAdministration.cpp:48)
==41694==    by 0x10B5A5: returnCar(RentalAdministration*, unsigned long) (main.cpp:87)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 2 errors in context 72 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6AD4A: hack_digit (printf_fp.c:124)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 2 errors in context 73 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6AD38: hack_digit (printf_fp.c:123)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 2 errors in context 74 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6477C: __mpn_mul_1 (mul_1.S:52)
==41694==    by 0x4C6AD34: hack_digit (printf_fp.c:122)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 2 errors in context 75 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C64758: __mpn_mul_1 (mul_1.S:36)
==41694==    by 0x4C6AD34: hack_digit (printf_fp.c:122)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 2 errors in context 76 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6BCDA: __printf_fp_buffer_1.isra.0 (printf_fp.c:385)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 2 errors in context 77 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C63AC1: __mpn_cmp (cmp.c:39)
==41694==    by 0x4C6BCD7: __printf_fp_buffer_1.isra.0 (printf_fp.c:385)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 2 errors in context 78 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63ABA: __mpn_cmp (cmp.c:38)
==41694==    by 0x4C6BCD7: __printf_fp_buffer_1.isra.0 (printf_fp.c:385)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 2 errors in context 79 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63AB6: __mpn_cmp (cmp.c:37)
==41694==    by 0x4C6BCD7: __printf_fp_buffer_1.isra.0 (printf_fp.c:385)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 2 errors in context 80 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B32C: __printf_fp_buffer_1.isra.0 (printf_fp.c:385)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 2 errors in context 81 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B326: __printf_fp_buffer_1.isra.0 (printf_fp.c:385)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 2 errors in context 82 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x484C081: memmove (vg_replace_strmem.c:1400)
==41694==    by 0x4C6B3C5: memcpy (string_fortified.h:29)
==41694==    by 0x4C6B3C5: __printf_fp_buffer_1.isra.0 (printf_fp.c:388)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 2 errors in context 83 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x484C081: memmove (vg_replace_strmem.c:1400)
==41694==    by 0x4C6B31A: memcpy (string_fortified.h:29)
==41694==    by 0x4C6B31A: __printf_fp_buffer_1.isra.0 (printf_fp.c:369)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 3 errors in context 84 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C98E5C: _IO_new_file_xsputn (fileops.c:1219)
==41694==    by 0x4C98E5C: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1197)
==41694==    by 0x4C8CAD1: fwrite (iofwrite.c:39)
==41694==    by 0x49BFCF2: sputn (streambuf:458)
==41694==    by 0x49BFCF2: _M_put (streambuf_iterator.h:327)
==41694==    by 0x49BFCF2: __write<char> (locale_facets.h:124)
==41694==    by 0x49BFCF2: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1118)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 3 errors in context 85 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x48491A4: memchr (vg_replace_strmem.c:985)
==41694==    by 0x49BFA55: find (char_traits.h:421)
==41694==    by 0x49BFA55: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1070)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 3 errors in context 86 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6ADB0: hack_digit (printf_fp.c:111)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 3 errors in context 87 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6AD9C: hack_digit (printf_fp.c:111)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 3 errors in context 88 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6AD8C: hack_digit (printf_fp.c:108)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 3 errors in context 89 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C6AD84: hack_digit (printf_fp.c:107)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 3 errors in context 90 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63F15: __mpn_divrem (divrem.c:79)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 3 errors in context 91 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63EDF: __mpn_divrem (divrem.c:73)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 3 errors in context 92 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63ED0: __mpn_divrem (divrem.c:73)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 3 errors in context 93 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C63EB4: __mpn_divrem (divrem.c:65)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 3 errors in context 94 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63EA3: __mpn_divrem (divrem.c:63)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 3 errors in context 95 of 96:
==41694== Use of uninitialised value of size 8
==41694==    at 0x4C63EA0: __mpn_divrem (divrem.c:62)
==41694==    by 0x4C6AD74: hack_digit (printf_fp.c:105)
==41694==    by 0x4C6C1AF: __printf_fp_buffer_1.isra.0 (printf_fp.c:769)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694==  
==41694== 13 errors in context 96 of 96:
==41694== Conditional jump or move depends on uninitialised value(s)
==41694==    at 0x4C6B35F: __printf_fp_buffer_1.isra.0 (printf_fp.c:322)
==41694==    by 0x4C6D1D3: __printf_fp_l_buffer (printf_fp.c:1122)
==41694==    by 0x4C73FEC: __printf_fp_spec (vfprintf-internal.c:266)
==41694==    by 0x4C73FEC: __printf_buffer (vfprintf-internal.c:999)
==41694==    by 0x4C95534: __vsnprintf_internal (vsnprintf.c:96)
==41694==    by 0x4C95534: vsnprintf (vsnprintf.c:103)
==41694==    by 0x498A141: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h
:97)
==41694==    by 0x49BF8C8: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambu
f_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits
<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
==41694==    by 0x49D0E3E: put (locale_facets.h:2463)
==41694==    by 0x49D0E3E: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:78)
==41694==    by 0x10B620: returnCar(RentalAdministration*, unsigned long) (main.cpp:88)
==41694==    by 0x10BB05: main (main.cpp:161)
==41694==  
==41694== ERROR SUMMARY: 144 errors from 96 contexts (suppressed: 0 from 0)
```
