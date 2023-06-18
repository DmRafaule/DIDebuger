cmake_minimum_required(VERSION 3.5)
project(DIDebuger DESCRIPTION "Debuger and some usefull macros of DI engine" LANGUAGES CXX)


file( GLOB SOURCES **.cpp )

SetFlags()
SetLibraries( GLEW )
CreateLibrary( ${PROJECT_NAME} )