cmake_minimum_required(VERSION 3.13)
project(datalab_handout)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(datalab_handout
        bits.c
        bits.h
        btest.c
        btest.h
        decl.c
        dlc
        driver.pl
        Driverhdrs.pm
        Driverlib.pm
        fshow.c
        ishow.c
        Makefile
        README
        tests.c)
