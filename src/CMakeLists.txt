cmake_minimum_required(VERSION 3.12)
project(PosTagger)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

find_package(corpus REQUIRED)
find_package(hmm REQUIRED)
find_package(data_structure REQUIRED)
find_package(math REQUIRED)

add_library(PosTagger PosTagger.h PosTaggedWord.cpp PosTaggedWord.h PosTaggedCorpus.cpp PosTaggedCorpus.h DummyPosTagger.cpp DummyPosTagger.h NaivePosTagger.cpp NaivePosTagger.h HmmPosTagger.cpp HmmPosTagger.h)
target_link_libraries(PosTagger corpus::corpus hmm::hmm data_structure::data_structure math::math)
