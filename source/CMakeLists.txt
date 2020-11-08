cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(Aqueduct LANGUAGES CXX)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

set(QT5_LIBS Qt5::Core Qt5::Widgets)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(Headers
    mainwindow.h
    librarybrowser.h
    libraryviewmodel.h
    assetviewmodel.h
    assetlistview.h
    assetbrowser.h
    )

set(Sources
    main.cpp
    mainwindow.cpp
    librarybrowser.cpp
    libraryviewmodel.cpp
    assetviewmodel.cpp
    assetlistview.cpp
    assetbrowser.cpp
    )

qt5_wrap_cpp(QT_MOC
    ${Headers}
    )

qt5_add_resources(QT_RES resources.qrc)

add_executable(${PROJECT_NAME}
    ${QT_MOC}
    ${QT_RES}
    ${Headers}
    ${Sources}
    )

target_link_libraries(${PROJECT_NAME} PUBLIC ${QT5_LIBS})
