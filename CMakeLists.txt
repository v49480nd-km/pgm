cmake_minimum_required(VERSION 3.29.3)

project(pgm
    VERSION 0.1
    DESCRIPTION "A Password Generator and Manager"
    LANGUAGES C
)

add_executable(${PROJECT_NAME}
    src/main.c
    src/utils.c
    src/utils.h
    src/crypt.c
    src/crypt.h
)

target_compile_features(${PROJECT_NAME}
    PRIVATE
    c_std_17
)

target_compile_options(${PROJECT_NAME}
    PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -O3
)
