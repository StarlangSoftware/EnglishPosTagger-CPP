cmake_minimum_required(VERSION 3.12)
project(PosTagger)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(PosTagger src/PosTagger.h src/PosTaggedWord.cpp src/PosTaggedWord.h src/PosTaggedCorpus.cpp src/PosTaggedCorpus.h src/DummyPosTagger.cpp src/DummyPosTagger.h src/NaivePosTagger.cpp src/NaivePosTagger.h src/HmmPosTagger.cpp src/HmmPosTagger.h)
target_link_libraries(PosTagger ${CONAN_LIBS})
add_executable(Test src/PosTagger.h src/PosTaggedWord.cpp src/PosTaggedWord.h src/PosTaggedCorpus.cpp src/PosTaggedCorpus.h src/DummyPosTagger.cpp src/DummyPosTagger.h src/NaivePosTagger.cpp src/NaivePosTagger.h src/HmmPosTagger.cpp src/HmmPosTagger.h Test/DummyPosTaggerTest.cpp Test/HmmPosTaggerTest.cpp Test/NaivePosTaggerTest.cpp)
target_link_libraries(Test ${CONAN_LIBS})
