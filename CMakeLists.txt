cmake_minimum_required(VERSION 3.2)

set(PROJECT_VERSION_PATCH $ENV{TRAVIS_BUILD_NUMBER})
set( DOC_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/Doc )
project(editor VERSION 0.0.${PROJECT_VERSION_PATCH})

configure_file(version.h.in version.h @ONLY)

set(SRC
    main.cpp
    )

set(HDR
    DocumentEditor.h
    Editor.h
    IFormat.h
    IShape.h
    )

#Program editor
add_executable(editor ${SRC} ${HDR})

set_target_properties(editor PROPERTIES
    INCLUDE_DIRECTORIES ${CMAKE_CURRENT_BINARY_DIR}
)

#Дополнительный свойста компилятора для всех проектов
set_target_properties( editor PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS -Wall
)

install(TARGETS editor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT aquila-2004@yandex.ru)

include(CPack)
