cmake_minimum_required(VERSION 3.10)

# Proje ismi
project(NongradedProject)

# C++ standardını ayarlama
set(CMAKE_CXX_STANDARD 11)

# Başlık dosyalarının bulunduğu dizini ekleme
include_directories(headers)

# Kaynak dosyalarını belirleme
add_executable(NongradedProject
        src/main.cpp
        src/part1.cpp
        src/part2.cpp
        src/part3.cpp
)

# Eğer ek kütüphaneler ya da derleme seçenekleri varsa, bunları da burada ekleyebilirsiniz.
