# EnglishPosTagger

This is a tool meant for tagging words with their part-of-speech, a grammatical category based on their function within a sentence, such as noun, adjective, verb, and so forth. 

For Developers
============
You can also see either [Python](https://github.com/olcaytaner/EnglishPosTagger-Py) 
or [Java](https://github.com/olcaytaner/EnglishPosTagger) repository.
## Requirements

* [C++ Compiler](#cpp)
* [Git](#git)


### CPP
To check if you have compatible C++ Compiler installed,
* Open CLion IDE 
* Preferences >Build,Execution,Deployment > Toolchain  

### Git

Install the [latest version of Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git).

## Download Code

In order to work on code, create a fork from GitHub page. 
Use Git for cloning the code to your local or below line for Ubuntu:

	git clone <your-fork-git-link>

A directory called EnglishPosTagger-CPP will be created. Or you can use below link for exploring the code:

	git clone https://github.com/olcaytaner/EnglishPosTagger-CPP.git

## Open project with CLion IDE

To import projects from Git with version control:

* Open CLion IDE , select Get From Version Control.

* In the Import window, click URL tab and paste github URL.

* Click open as Project.

Result: The imported project is listed in the Project Explorer view and files are loaded.


## Compile

**From IDE**

After being done with the downloading and opening project, select **Build Project** option from **Build** menu. After compilation process, user can run PosTagTest.cpp .

Detailed Description
============
+ [PosTagger](#postagger)

## PosTagger

İngilizce pos tagging için kullanılan PosTagger'ı eğitmek için 

	void train(PosTaggedCorpus corpus)
	
eğitilen PosTagger modelini kaydetmek için

	void saveModel()
	
daha önce eğitilmiş bir PosTagger modelini yüklemek için

	void loadModel()
	
ve yeni eğitilmiş veya yüklenmiş bir PosTagger modelini kullanarak bir cümleyi taglemek için

	Sentence posTag(Sentence sentence)
	
metodu kullanılır.

3 farklı PosTagger modeli desteklenmektedir. Rasgele bir tag ile kelimeleri taglemek için kullanılan

	DummyPosTagger
	
o kelime için en çok kullanılan tag ile kelimeleri tagleyen

	NaivePosTagger
	
ve Hmm tabanlı bir eğitim yapıp buna göre kelimeleri tagleyen

	HmmPosTagger
