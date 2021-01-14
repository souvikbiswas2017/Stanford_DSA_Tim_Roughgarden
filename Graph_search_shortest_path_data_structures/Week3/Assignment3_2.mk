##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Assignment3_2
ConfigurationName      :=Debug
WorkspacePath          :=/home/souvik/Documents/MyCourses/Stanford-AlgorithmCourse/StanfordDSAWorkspace
ProjectPath            :=/home/souvik/Documents/MyCourses/Stanford-AlgorithmCourse/StanfordDSAWorkspace/Assignment3_2
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Souvik Biswas
Date                   :=05/04/19
CodeLitePath           :=/home/souvik/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Assignment3_2.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/maxheap.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/heap.cpp$(ObjectSuffix) $(IntermediateDirectory)/minheap.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/maxheap.cpp$(ObjectSuffix): maxheap.cpp $(IntermediateDirectory)/maxheap.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/souvik/Documents/MyCourses/Stanford-AlgorithmCourse/StanfordDSAWorkspace/Assignment3_2/maxheap.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/maxheap.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/maxheap.cpp$(DependSuffix): maxheap.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/maxheap.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/maxheap.cpp$(DependSuffix) -MM maxheap.cpp

$(IntermediateDirectory)/maxheap.cpp$(PreprocessSuffix): maxheap.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/maxheap.cpp$(PreprocessSuffix) maxheap.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/souvik/Documents/MyCourses/Stanford-AlgorithmCourse/StanfordDSAWorkspace/Assignment3_2/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/heap.cpp$(ObjectSuffix): heap.cpp $(IntermediateDirectory)/heap.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/souvik/Documents/MyCourses/Stanford-AlgorithmCourse/StanfordDSAWorkspace/Assignment3_2/heap.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/heap.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/heap.cpp$(DependSuffix): heap.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/heap.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/heap.cpp$(DependSuffix) -MM heap.cpp

$(IntermediateDirectory)/heap.cpp$(PreprocessSuffix): heap.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/heap.cpp$(PreprocessSuffix) heap.cpp

$(IntermediateDirectory)/minheap.cpp$(ObjectSuffix): minheap.cpp $(IntermediateDirectory)/minheap.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/souvik/Documents/MyCourses/Stanford-AlgorithmCourse/StanfordDSAWorkspace/Assignment3_2/minheap.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/minheap.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/minheap.cpp$(DependSuffix): minheap.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/minheap.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/minheap.cpp$(DependSuffix) -MM minheap.cpp

$(IntermediateDirectory)/minheap.cpp$(PreprocessSuffix): minheap.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/minheap.cpp$(PreprocessSuffix) minheap.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/

