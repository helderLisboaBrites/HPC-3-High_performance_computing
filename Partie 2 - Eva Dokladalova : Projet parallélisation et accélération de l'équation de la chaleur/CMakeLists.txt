cmake_minimum_required( VERSION 2.8 )

set(SRCS
    main.c
    function.c
    )
    
set(HEADERS
    function.h
    )


add_executable(main ${SRCS} ${HEADERS})