cmake_minimum_required(VERSION 3.12)
project(PosTagger)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
link_directories(library)

add_library(PosTagger PosTagger.h PosTaggedWord.cpp PosTaggedWord.h PosTaggedCorpus.cpp PosTaggedCorpus.h DummyPosTagger.cpp DummyPosTagger.h NaivePosTagger.cpp NaivePosTagger.h HmmPosTagger.cpp HmmPosTagger.h)
target_link_libraries(PosTagger Corpus Dictionary Math)

add_executable(Test PosTagger.h PosTaggedWord.cpp PosTaggedWord.h PosTaggedCorpus.cpp PosTaggedCorpus.h DummyPosTagger.cpp DummyPosTagger.h NaivePosTagger.cpp NaivePosTagger.h HmmPosTagger.cpp HmmPosTagger.h Test/DummyPosTaggerTest.cpp Test/HmmPosTaggerTest.cpp Test/NaivePosTaggerTest.cpp)
target_link_libraries(Test Corpus Dictionary Math)
