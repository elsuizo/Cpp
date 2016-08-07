#!/usr/bin/env bash
mkdir -p build && \
pushd build && \
  g++\
    -o main \
    ../external/imgui/imgui.cpp \
    ../external/imgui/imgui_draw.cpp \
    ../external/imgui-SFML.cpp \
    ../external/imgui-SFML.h \
    ../src/main.cpp \
    -Wall \
    -g                      `# Generate complete debug info` \
    -std=c++11 \
    -I ../include \
    -I ../external/imgui \
    -L ../lib \
    -lGL \
    -lGLU \
    -lX11 \
    -lXxf86vm \
    -lXrandr \
    -lpthread \
    -lXi \
    -lXinerama \
    -lsfml-graphics \
    -lsfml-window \
    -lsfml-system \
    -lXcursor && \
popd || exit 1
