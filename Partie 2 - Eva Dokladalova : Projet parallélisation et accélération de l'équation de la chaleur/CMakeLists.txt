cmake_minimum_required( VERSION 3.16.3 )
project(HPC)
set(SRCS
    main.c
    function.c
    )
    
set(HEADERS
    function.h
    )



set (CMAKE_C_FLAGS "-fopenmp")
set (CMAKE_CXX_FLAGS "-fopenmp")
set (CMAKE_EXE_LINKER_FLAGS "-fopenmp")

add_executable(main ${SRCS} ${HEADERS})