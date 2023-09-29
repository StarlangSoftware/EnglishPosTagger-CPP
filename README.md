Pos Tagging
============

This is a tool meant for tagging words with their part-of-speech, a grammatical category based on their function within a sentence, such as noun, adjective, verb, and so forth. 

Video Lectures
============

[<img src="https://github.com/StarlangSoftware/EnglishPosTagger/blob/master/video1.jpg" width="50%">](https://youtu.be/gQmc7Nhwhuk)[<img src="https://github.com/StarlangSoftware/EnglishPosTagger/blob/master/video2.jpg" width="50%">](https://youtu.be/GHUib73MRks)

For Developers
============

You can also see [Java](https://github.com/starlangsoftware/EnglishPosTagger), [Python](https://github.com/starlangsoftware/EnglishPosTagger-Py), [Cython](https://github.com/starlangsoftware/EnglishPosTagger-Cy), [Swift](https://github.com/starlangsoftware/EnglishPosTagger-Swift), [C](https://github.com/starlangsoftware/EnglishPosTagger-C), [Js](https://github.com/starlangsoftware/EnglishPosTagger-Js), or [C#](https://github.com/starlangsoftware/EnglishPosTagger-CS) repository.

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

	git clone https://github.com/starlangsoftware/EnglishPosTagger-CPP.git

## Open project with CLion IDE

To import projects from Git with version control:

* Open CLion IDE , select Get From Version Control.

* In the Import window, click URL tab and paste github URL.

* Click open as Project.

Result: The imported project is listed in the Project Explorer view and files are loaded.


## Compile

**From IDE**

After being done with the downloading and opening project, select **Build Project** option from **Build** menu. After compilation process, user can run PosTagTest.cpp.

Detailed Description
============

+ [PosTagger](#postagger)

## PosTagger

To train the PosTagger which is used for English pos tagging 

	void train(PosTaggedCorpus corpus)
	
To save the trained PosTagger model

	void saveModel()
	
To tag a sentence, using a newly trained or loaded PosTagger model

	void loadModel()
	
ve yeni eğitilmiş veya yüklenmiş bir PosTagger modelini kullanarak bir cümleyi taglemek için

	Sentence posTag(Sentence sentence)
	

3 different PosTagger models are supported: 
The one that is used to tag the sentences with a random tag

	DummyPosTagger
	
the one that tags the word with the most used tag for a given word

	NaivePosTagger
	
the one that does an Hmm based training and tags the words accordingly

	HmmPosTagger
