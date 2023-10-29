file(
    GLOB_RECURSE
    libSrc
    "src/*.cpp"
    "src/*.h"
)

add_library(
    lib
    "${libSrc}"
)
