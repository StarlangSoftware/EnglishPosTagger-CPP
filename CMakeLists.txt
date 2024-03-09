cmake_minimum_required(VERSION 3.12)
project(PosTagger)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

find_package(corpus REQUIRED)
find_package(hmm REQUIRED)
find_package(data_structure REQUIRED)
find_package(math REQUIRED)

add_library(PosTagger src/PosTagger.h src/PosTaggedWord.cpp src/PosTaggedWord.h src/PosTaggedCorpus.cpp src/PosTaggedCorpus.h src/DummyPosTagger.cpp src/DummyPosTagger.h src/NaivePosTagger.cpp src/NaivePosTagger.h src/HmmPosTagger.cpp src/HmmPosTagger.h)
target_link_libraries(PosTagger corpus::corpus hmm::hmm data_structure::data_structure math::math)
add_executable(Test src/PosTagger.h src/PosTaggedWord.cpp src/PosTaggedWord.h src/PosTaggedCorpus.cpp src/PosTaggedCorpus.h src/DummyPosTagger.cpp src/DummyPosTagger.h src/NaivePosTagger.cpp src/NaivePosTagger.h src/HmmPosTagger.cpp src/HmmPosTagger.h Test/DummyPosTaggerTest.cpp Test/HmmPosTaggerTest.cpp Test/NaivePosTaggerTest.cpp)
target_link_libraries(Test corpus::corpus hmm::hmm data_structure::data_structure math::math)
