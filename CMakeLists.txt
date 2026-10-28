cmake_minimum_required(VERSION 3.16)

project(finiteAutomata LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(finiteAutomata main.cpp
    fsa.h fsa.cpp)

include(GNUInstallDirs)
install(TARGETS finiteAutomata
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
